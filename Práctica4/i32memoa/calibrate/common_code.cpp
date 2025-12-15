/**
 * @file common_code.cpp
 * @author Francisco José Madrid Cuevas (fjmadrid@uco.es)
 * @brief Utility functions to calibrate/undistort a camera.
 * @version 0.1
 * @date 2024-09-24
 *
 * @copyright Copyright (c) 2024-
 *
 */
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include "common_code.hpp"

std::vector<cv::Point3f>
fsiv_generate_3d_calibration_points(const cv::Size &board_size,
                                    float square_size)
{
    std::vector<cv::Point3f> ret_v;
    // TODO
    // Remember: the first inner point has (1,1) in board coordinates.
        for(int i=1; i<=board_size.height; i++){
            for(int j=1; j<=board_size.width; j++){
                ret_v.push_back(cv::Point3f(square_size * j, square_size * i, 0.0f));
            }
        }
    //
    CV_Assert(ret_v.size() == static_cast<size_t>(board_size.width * board_size.height));
    return ret_v;
}

bool fsiv_find_chessboard_corners(const cv::Mat &img, const cv::Size &board_size,
                                  std::vector<cv::Point2f> &corner_points,
                                  int win_r,
                                  int zz_r,
                                  const cv::TermCriteria &tcr)
{
    CV_Assert(img.type() == CV_8UC3);
    bool was_found = false;
    // TODO
    // Hint: use cv::findChessboardCorners and cv::cornerSubPix.
    // Remember: cornerSubPix requires a grayscale image.
        cv::Mat img_gray;
        cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
        if( cv::findChessboardCorners(img_gray, board_size, corner_points)){
            cv::cornerSubPix(img_gray, corner_points, cv::Size(win_r, win_r), cv::Size(zz_r, zz_r), tcr);
            was_found = true;
        }
    //
    CV_Assert(!was_found || corner_points.size() == (board_size.width * board_size.height));
    return was_found;
}

float fsiv_calibrate_camera(const std::vector<std::vector<cv::Point2f>> &_2d_points,
                            const std::vector<std::vector<cv::Point3f>> &_3d_points,
                            const cv::Size &camera_size,
                            cv::Mat &camera_matrix,
                            cv::Mat &dist_coeffs,
                            std::vector<cv::Mat> *rvecs,
                            std::vector<cv::Mat> *tvecs)
{
    CV_Assert(_3d_points.size() >= 2 && _3d_points.size() == _2d_points.size());
    float error = 0.0;
    // TODO
    // Hint: use cv::calibrateCamera.
    // Remember: if rvecs or tvecs are not nullptr, save the rotation and translation vectors.

        std::vector<cv::Mat> local_rvecs;
        std::vector<cv::Mat> local_tvecs;

        error = cv::calibrateCamera(
            _3d_points, 
            _2d_points, 
            camera_size, 
            camera_matrix, 
            dist_coeffs, 
            local_rvecs, 
            local_tvecs
        );

        if( rvecs != nullptr){
            *rvecs = local_rvecs;
        } 
        if( tvecs != nullptr ){ 
            *tvecs = local_tvecs;
        }
    //
    CV_Assert(camera_matrix.rows == camera_matrix.cols &&
              camera_matrix.rows == 3 &&
              camera_matrix.type() == CV_64FC1);
    CV_Assert((dist_coeffs.rows * dist_coeffs.cols) == 5 &&
              dist_coeffs.type() == CV_64FC1);
    CV_Assert(rvecs == nullptr || rvecs->size() == _2d_points.size());
    CV_Assert(tvecs == nullptr || tvecs->size() == _2d_points.size());
    return error;
}

void fsiv_save_calibration_parameters(cv::FileStorage &fs,
                                      const cv::Size &camera_size,
                                      float error,
                                      const cv::Mat &camera_matrix,
                                      const cv::Mat &dist_coeffs,
                                      const cv::Mat &rvec,
                                      const cv::Mat &tvec)
{
    CV_Assert(fs.isOpened());
    CV_Assert(camera_matrix.type() == CV_64FC1 && camera_matrix.rows == 3 && camera_matrix.cols == 3);
    CV_Assert(dist_coeffs.type() == CV_64FC1 && dist_coeffs.rows == 1 && dist_coeffs.cols == 5);
    CV_Assert(rvec.type() == CV_64FC1 && rvec.rows == 3 && rvec.cols == 1);
    CV_Assert(tvec.type() == CV_64FC1 && tvec.rows == 3 && tvec.cols == 1);
    // TODO
    // Hint: use cv::FileStorage "<<" operator to save the data.
    // Remember: the labels are: image-width, image-height, error, camera-matrix, distortion-coefficients, rvec, tvec.
        fs << "image-width" << camera_size.width;
        fs << "image-height" << camera_size.height;
        fs << "error" << error;
        fs << "camera-matrix" << camera_matrix;
        fs << "distortion-coefficients" << dist_coeffs;
        fs << "rvec" << rvec;
        fs << "tvec" << tvec;
    //
    CV_Assert(fs.isOpened());
    return;
}

void fsiv_load_calibration_parameters(cv::FileStorage &fs,
                                      cv::Size &camera_size,
                                      float &error,
                                      cv::Mat &camera_matrix,
                                      cv::Mat &dist_coeffs,
                                      cv::Mat &rvec,
                                      cv::Mat &tvec)
{
    CV_Assert(fs.isOpened());
    // TODO
    // Hint: use cv::FileStorage ">>" operator to load the data.
    // Remember: the labels are: image-width, image-height, error, camera-matrix, distortion-coefficients, rvec, tvec.
        fs["image-width"] >> camera_size.width;
        fs["image-height"] >> camera_size.height;
        fs["error"] >> error;
        fs["camera-matrix"] >> camera_matrix;
        fs["distortion-coefficients"] >> dist_coeffs;
        fs["rvec"] >> rvec;
        fs["tvec"] >> tvec;
    //
    CV_Assert(fs.isOpened());
    CV_Assert(camera_matrix.type() == CV_64FC1 && camera_matrix.rows == 3 && camera_matrix.cols == 3);
    CV_Assert(dist_coeffs.type() == CV_64FC1 && dist_coeffs.rows == 1 && dist_coeffs.cols == 5);
    CV_Assert(rvec.type() == CV_64FC1 && rvec.rows == 3 && rvec.cols == 1);
    CV_Assert(tvec.type() == CV_64FC1 && tvec.rows == 3 && tvec.cols == 1);
    return;
}

void fsiv_undistort_image(const cv::Mat &input, cv::Mat &output,
                          const cv::Mat &camera_matrix,
                          const cv::Mat &dist_coeffs)
{
    // TODO
    // Hint: use cv::undistort.
        cv::undistort(input, output, camera_matrix, dist_coeffs);
    //
}

void fsiv_undistort_video_stream(cv::VideoCapture &input_stream,
                                 cv::VideoWriter &output_stream,
                                 const cv::Mat &camera_matrix,
                                 const cv::Mat &dist_coeffs,
                                 const int interp,
                                 const char *input_wname,
                                 const char *output_wname,
                                 double fps)
{
    CV_Assert(input_stream.isOpened());
    CV_Assert(output_stream.isOpened());
    // TODO
    // Hint: to speed up, first compute the transformation maps
    //  with the first video frame using cv::initUndistortRectifyMap
    //  and then, for the rest of video frames, only remap (cv::remap)
    //  the input frame using the computed maps.
    // Remember: if input_wname or output_wname are not nullptr, show the frames.
    // Read first frame to obtain size and compute maps once
        cv::Mat frame;
        if (!input_stream.read(frame) || frame.empty()) {
            return;
        }

        const cv::Size frame_size = frame.size();
        cv::Mat map1, map2;

        cv::initUndistortRectifyMap(camera_matrix, dist_coeffs, cv::Mat(), camera_matrix,
                                    frame_size, CV_32FC1, map1, map2);

        cv::Mat undist;

        cv::remap(frame, undist, map1, map2, interp);
        output_stream.write(undist);

        if (input_wname != nullptr){
            cv::imshow(input_wname, frame);
        }
            
        if (output_wname != nullptr){
            cv::imshow(output_wname, undist);
        }
            

        const bool show = (input_wname != nullptr) || (output_wname != nullptr);
        const int delay_ms = (fps > 0.0) ? static_cast<int>(std::max(1.0, 1000.0 / fps)) : 1;

        if( show ){
            int k = cv::waitKey(delay_ms);
            if ( k == 27 ){
                if (input_wname) cv::destroyWindow(input_wname);
                if (output_wname) cv::destroyWindow(output_wname);
                return;
            }
        }

        while ( true ){
            if ( !input_stream.read(frame) || frame.empty() )
                break;

            cv::remap(frame, undist, map1, map2, interp);
            output_stream.write(undist);

            if (input_wname != nullptr)
                cv::imshow(input_wname, frame);
            if (output_wname != nullptr)
                cv::imshow(output_wname, undist);

            if (show) {
                int k = cv::waitKey(delay_ms);
                if (k == 27)
                    break;
            }
        }

        if (input_wname) cv::destroyWindow(input_wname);
        if (output_wname) cv::destroyWindow(output_wname);

    CV_Assert(input_stream.isOpened());
    CV_Assert(output_stream.isOpened());
}
