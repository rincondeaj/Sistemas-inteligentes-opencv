#include <iostream>
#include "common_code.hpp"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

cv::Mat
fsiv_convert_bgr_to_hsv(const cv::Mat &img)
{
    CV_Assert(img.channels() == 3);
    cv::Mat out;
    //! TODO
    // Hint: use cvtColor.
    // Remember: the input color scheme is assumed to be BGR.
        cv::cvtColor(img,out, cv::COLOR_BGR2HSV);
    //
    CV_Assert(out.channels() == 3);
    return out;
}

cv::Mat
fsiv_combine_images(const cv::Mat &img1, const cv::Mat &img2,
                    const cv::Mat &mask)
{
    CV_Assert(img2.size() == img1.size());
    CV_Assert(img2.type() == img1.type());
    CV_Assert(mask.size() == img1.size());
    cv::Mat output;
    //! TODO
    //  HINT: you can use cv::Mat::copyTo().
        cv::Mat img2_aux;
        img2.copyTo(img2_aux);
        img1.copyTo(img2_aux, mask);
        output = img2_aux;
    //
    CV_Assert(output.size() == img1.size());
    CV_Assert(output.type() == img1.type());
    return output;
}

cv::Mat
fsiv_compute_chroma_key_mask(const cv::Mat &bgr_img,
                             int chroma_key,
                             int sensitivity)
{
    CV_Assert(bgr_img.type() == CV_8UC3);
    cv::Mat mask;
    // TODO
    // Hint: use fsiv_xxx defined functions.
    // Hint: use cv::inRange to get the mask.
    // Remember: the use full range for S and V channels ([0,255]).
        cv::Mat hsv_img;
        hsv_img = fsiv_convert_bgr_to_hsv(bgr_img);
        cv::Scalar lower_b(chroma_key - sensitivity, 0, 0);
        cv::Scalar upper_b(chroma_key + sensitivity, 255, 255);
        cv::inRange(hsv_img, lower_b, upper_b, mask);
    //
    return mask;
}

cv::Mat
fsiv_apply_chroma_key(const cv::Mat &foreg, const cv::Mat &backg, int hue,
                      int sensitivity, cv::Mat *mask_out)
{
    cv::Mat out;
    cv::Scalar lower_b, upper_b; // HSV range.

    // TODO
    // Hint: use fsiv_xxx defined functions.
    // Hint: use cv::resize if backg img has different size than foreg.
    // Remember: if mask_out is not null, the computed mask must be assigned to *mask_out.
        cv::Mat mask, backg_resized;

        if(foreg.size() != backg.size()){
            cv::resize(backg, backg_resized, foreg.size(), 0, 0, cv::INTER_LINEAR);
        } else {
            backg_resized = backg;
        }
        
        mask = fsiv_compute_chroma_key_mask(foreg, hue, sensitivity);
        cv::bitwise_not(mask, mask);
        if( mask_out != nullptr){
            *mask_out = mask;
        }

        out = fsiv_combine_images(foreg, backg_resized, mask);
    //
    CV_Assert(out.size() == foreg.size());
    CV_Assert(out.type() == foreg.type());
    return out;
}
