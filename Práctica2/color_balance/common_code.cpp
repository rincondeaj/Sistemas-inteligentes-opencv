#include "common_code.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

cv::Mat fsiv_color_rescaling(const cv::Mat &in, const cv::Scalar &from, const cv::Scalar &to)
{
    cv::Mat out;
    // TODO
    // HINT: use cv:divide to compute the scaling factor.
    // HINT: use method cv::Mat::mul() to scale the input matrix.
        cv::Scalar lambda;
        cv::divide(to, from, lambda);
        out = in.clone();
        out = out.mul(lambda);
    //
    CV_Assert(out.type() == in.type());
    CV_Assert(out.size() == in.size());
    return out;
}

cv::Mat fsiv_gray_world_color_balance(cv::Mat const &in)
{
    CV_Assert(in.type() == CV_8UC3);
    cv::Mat out;
    // TODO
    //  HINT: use cv::mean to compute the mean pixel value.
        cv::Scalar from;
        from = cv::mean(in);
        cv::Scalar to(128, 128, 128);
        out = fsiv_color_rescaling(in, from, to);

    //
    CV_Assert(out.type() == in.type());
    CV_Assert(out.rows == in.rows && out.cols == in.cols);
    return out;
}

cv::Mat fsiv_convert_bgr_to_gray(const cv::Mat &img, cv::Mat &out)
{
    CV_Assert(img.channels() == 3);
    // TODO
    // HINT: use cv::cvtColor()
        cv::cvtColor(img, out, cv::COLOR_BGR2GRAY);
    //
    CV_Assert(out.channels() == 1);
    return out;
}

cv::Mat fsiv_compute_image_histogram(cv::Mat const &img)
{
    CV_Assert(img.type() == CV_8UC1);
    cv::Mat hist;
    // TODO
    // Hint: use cv::calcHist().
        std::vector<cv::Mat> images = {img};
        std::vector<int> channels = {0};
        std::vector<int> histSize = {256};
        std::vector<float> ranges = {0, 256};
        cv::calcHist(images, channels, cv::Mat(), hist, histSize, ranges, false);
    //
    CV_Assert(hist.type() == CV_32FC1);
    CV_Assert(hist.rows == 256 && hist.cols == 1);
    return hist;
}

int fsiv_compute_histogram_percentile(cv::Mat const &hist, float p_value)
{
    CV_Assert(hist.type() == CV_32FC1);
    CV_Assert(hist.cols == 1);
    CV_Assert(0.0 <= p_value && p_value <= 1.0);

    int p = 0;

    // TODO
    // Remember: find the smaller index 'p' such that
    //           sum(h[0], h[1], ... , h[p]) >= p_value*area(hist)
    // Hint: use cv::sum() to compute the histogram area.
        float area = cv::sum(hist)[0];
        float aux = 0;
        while( p < hist.rows){
            aux += hist.at<float>(p, 0);
            if( aux >= (p_value * area))return p;
            p++;
        }
    //

    CV_Assert(0 <= p && p < hist.rows);
    return p;
}

cv::Mat fsiv_white_patch_color_balance(cv::Mat const &in, float p)
{
    CV_Assert(in.type() == CV_8UC3);
    CV_Assert(0.0f <= p && p < 1.0f);
    cv::Mat out;
    if (p == 0.0)
    {
        // TODO
        // HINT: convert to GRAY color space to get the illuminance.
        // HINT: use cv::minMaxLoc to locate the brightest pixel.
        // HINT: use fsiv_color_rescaling when the "from" scalar was computed.
            cv::Mat grey;
            fsiv_convert_bgr_to_gray(in, grey);
            double max;
            cv::Point maxLoc;
            cv::minMaxLoc(grey, NULL, &max, NULL, &maxLoc);
            cv::Vec3b pixel = in.at<cv::Vec3b>(maxLoc.y, maxLoc.x);
            cv::Scalar from(pixel[0], pixel[1], pixel[2]);
            cv::Scalar to(255, 255, 255);
            out = fsiv_color_rescaling(in, from, to);
        //
    }
    else
    {
        // TODO
        // HINT: convert to GRAY color space to get the illuminance.
        // HINT: Compute the illuminance histogram and find the 1-p percentile.
        // HINT: use operator >= to compute a mask with p% brighter pixels and use it
        //        to compute the mean value with cv::mean.
        // HINT: use fsiv_color_rescaling when the "from" scalar was computed.
            cv::Mat grey;
            int aux;
            fsiv_convert_bgr_to_gray(in, grey);
            out = fsiv_compute_image_histogram(grey);
            aux = fsiv_compute_histogram_percentile(out, 1-p);
            cv::Mat mask = grey >= aux;
            cv::Scalar from = cv::mean(in, mask);
            cv::Scalar to(255, 255, 255);
            out = fsiv_color_rescaling(in, from, to);
        //
    }

    CV_Assert(out.type() == in.type());
    CV_Assert(out.rows == in.rows && out.cols == in.cols);
    return out;
}
