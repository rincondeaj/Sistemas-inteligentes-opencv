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
    CV_Assert(ret_v.size() ==
              static_cast<size_t>(board_size.width * board_size.height));
    return ret_v;
}

bool fsiv_fast_find_chessboard_corners(const cv::Mat &img, const cv::Size &board_size,
                                       std::vector<cv::Point2f> &corner_points)
{
    CV_Assert(img.type() == CV_8UC3);
    bool was_found = false;
    // TODO
    // Hint: use cv::findChessboardCorners only with the fast check flag.
    // Remember: do not refine the corner points to get a better computational performance.
        cv::Mat img_gray;
        cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
        if( cv::findChessboardCorners(img_gray, board_size, corner_points, cv::CALIB_CB_FAST_CHECK)){
            was_found = true;
        }
    //
    return was_found;
}

void fsiv_compute_camera_pose(const std::vector<cv::Point3f> &_3dpoints,
                              const std::vector<cv::Point2f> &_2dpoints,
                              const cv::Mat &camera_matrix,
                              const cv::Mat &dist_coeffs,
                              cv::Mat &rvec,
                              cv::Mat &tvec)
{
    CV_Assert(_3dpoints.size() >= 4 && _3dpoints.size() == _2dpoints.size());
    // TODO
    // Hint: use cv::solvePnP to the pose of a calibrated camera.
        cv::solvePnP(_3dpoints, _2dpoints, camera_matrix, dist_coeffs, rvec, tvec);
    //
    CV_Assert(rvec.rows == 3 && rvec.cols == 1 && rvec.type() == CV_64FC1);
    CV_Assert(tvec.rows == 3 && tvec.cols == 1 && tvec.type() == CV_64FC1);
}

void fsiv_draw_axes(cv::Mat &img,
                    const cv::Mat &camera_matrix, const cv::Mat &dist_coeffs,
                    const cv::Mat &rvec, const cv::Mat &tvec,
                    const float size, const int line_width)
{
    // TODO
    // Hint: use cv::projectPoints to get the image coordinates of the 3D points
    // (0,0,0), (size, 0, 0), (0, size, 0) and (0, 0, -size) and draw a line for
    // each axis: blue for axis OX, green for axis OY and red for axis OZ.
    // Warning: use of cv::drawFrameAxes() is not allowed.
        std::vector<cv::Point3f> axes3d = {
            {0.f, 0.f, 0.f},
            {size, 0.f, 0.f},
            {0.f, size, 0.f},
            {0.f, 0.f, -size}
        };

        std::vector<cv::Point2f> img_pts;
        cv::projectPoints(axes3d, rvec, tvec, camera_matrix, dist_coeffs, img_pts);
        cv::Point p0 = img_pts[0], pX = img_pts[1], pY = img_pts[2], pZ = img_pts[3];
        cv::line(img, p0, pX, cv::Scalar(255,0,0), line_width); // azul
        cv::line(img, p0, pY, cv::Scalar(0,255,0), line_width); // verde
        cv::line(img, p0, pZ, cv::Scalar(0,0,255), line_width); // rojo
    //
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
    //  Hint: use fs["label"] >> var to load data items from the file.
    //  @see cv::FileStorage operators "[]" and ">>"
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

void fsiv_draw_3d_model(cv::Mat &img, const cv::Mat &M, const cv::Mat &dist_coeffs,
                        const cv::Mat &rvec, const cv::Mat &tvec,
                        const float size)
{
    CV_Assert(img.type() == CV_8UC3);

    // TODO
    // Hint: build a 3D object points vector with pair of segments end points.
    // Use cv::projectPoints to get the 2D image coordinates of 3D object points,
    // build a vector of vectors of Points, one for each segment, and use
    // cv::polylines to draw the wire frame projected model.
    // Hint: use a "reference point" to move the model around the image and update it
    //       at each call to move the 3D model around the scene.

        std::vector<cv::Point3f> objPts = {
            {0.f, 0.f, 0.f},
            {size, 0.f, 0.f},
            {size, size, 0.f},
            {0.f, size, 0.f},
            {0.f, 0.f, -size},
            {size, 0.f, -size},
            {size, size, -size},
            {0.f, size, -size}
        };

        std::vector<cv::Point2f> imgpts;
        cv::projectPoints(objPts, rvec, tvec, M, dist_coeffs, imgpts);

        std::vector<cv::Point> pts;
        pts.reserve(imgpts.size());
        for (const auto &p : imgpts)
            pts.emplace_back(cv::Point(cvRound(p.x), cvRound(p.y)));

        std::vector<std::vector<cv::Point>> segments;
        auto push_edge = [&](int a, int b) {
            segments.push_back(std::vector<cv::Point>{pts[a], pts[b]});
        };

        push_edge(0,1); push_edge(1,2); push_edge(2,3); push_edge(3,0);
        push_edge(4,5); push_edge(5,6); push_edge(6,7); push_edge(7,4);
        push_edge(0,4); push_edge(1,5); push_edge(2,6); push_edge(3,7);

        cv::polylines(img, segments, false, cv::Scalar(0, 255, 255), 2);
    //
}

void fsiv_project_image(const cv::Mat &model, cv::Mat &scene,
                        const cv::Size &board_size,
                        const std::vector<cv::Point2f> &chess_board_corners)
{
    CV_Assert(!model.empty() && model.type() == CV_8UC3);
    CV_Assert(!scene.empty() && scene.type() == CV_8UC3);
    CV_Assert(static_cast<size_t>(board_size.area()) ==
              chess_board_corners.size());

    // TODO
    // Hint: get the upper-left, upper-right, bottom-right and bottom-left
    //   chess_board_corners and map to the upper-left, upper-right, bottom-right
    //   and bottom-left model image point coordinates.
    //   Use cv::getPerspectiveTransform compute such mapping.
    // Hint: use cv::wrapPerspective to get a wrap version of the model image
    //   using the computed mapping. Use INTER_LINEAR as interpolation method
    //   and use BORDER_TRANSPARENT as a border extrapolation method
    //   to maintain the underlying image.
        const cv::Point2f ul = chess_board_corners[0];
        const cv::Point2f ur = chess_board_corners[board_size.width - 1];
        const cv::Point2f br = chess_board_corners[board_size.width * board_size.height - 1];
        const cv::Point2f bl = chess_board_corners[(board_size.height - 1) * board_size.width];

        std::vector<cv::Point2f> srcPts = {
            cv::Point2f(0.f, 0.f),
            cv::Point2f(static_cast<float>(model.cols - 1), 0.f),
            cv::Point2f(static_cast<float>(model.cols - 1), static_cast<float>(model.rows - 1)),
            cv::Point2f(0.f, static_cast<float>(model.rows - 1))
        };

        std::vector<cv::Point2f> dstPts = { ul, ur, br, bl };

        cv::Mat H = cv::getPerspectiveTransform(srcPts, dstPts);

        cv::warpPerspective(model, scene, H, scene.size(), cv::INTER_LINEAR, cv::BORDER_TRANSPARENT);

    //
}
