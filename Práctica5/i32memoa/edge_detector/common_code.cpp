#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "common_code.hpp"

void fsiv_compute_derivate(cv::Mat const &img, cv::Mat &dx, cv::Mat &dy, int g_r,
                           int s_ap)
{
    CV_Assert(img.type() == CV_8UC1);
    // TODO
    // Remember: if g_r > 0 apply a previous Gaussian Blur operation with kernel size 2*g_r+1.
    // Hint: use Sobel operator to compute derivate.
        cv::Mat source_sobel;

        if(g_r > 0){
            cv::Size size_blur = {2 * g_r + 1, 2 * g_r + 1};
            cv::GaussianBlur(img, source_sobel, size_blur, 0);
        }else source_sobel = img;

        int sobel_size = s_ap;
        cv::Sobel(source_sobel, dx, CV_32F, 1, 0, sobel_size);
        cv::Sobel(source_sobel, dy, CV_32F, 0, 1, sobel_size);
    //
    CV_Assert(dx.size() == img.size());
    CV_Assert(dy.size() == dx.size());
    CV_Assert(dx.type() == CV_32FC1);
    CV_Assert(dy.type() == CV_32FC1);
}

void fsiv_compute_gradient_magnitude(cv::Mat const &dx, cv::Mat const &dy,
                                     cv::Mat &gradient)
{
    CV_Assert(dx.size() == dy.size());
    CV_Assert(dx.type() == CV_32FC1);
    CV_Assert(dy.type() == CV_32FC1);

    // TODO
    // Hint: use cv::magnitude.
        cv::magnitude(dx, dy, gradient);
    //

    CV_Assert(gradient.size() == dx.size());
    CV_Assert(gradient.type() == CV_32FC1);
}

void fsiv_compute_gradient_histogram(cv::Mat const &gradient, int n_bins, cv::Mat &hist, float &max_gradient)
{
    // TODO
    // Hint: use cv::minMaxLoc to get the gradient range {0, max_gradient}
        double temp_max_gradient = 0;
        cv::minMaxLoc(gradient, NULL, &temp_max_gradient);
        max_gradient = temp_max_gradient;
        std::vector<cv::Mat> images = {gradient};
        std::vector<int> channels = {0};
        std::vector<int> histSize = {n_bins};
        std::vector<float> ranges = {0, max_gradient};
        cv::calcHist(images, channels, cv::Mat(), hist, histSize, ranges);
    //
    CV_Assert(max_gradient > 0.0);
    CV_Assert(hist.rows == n_bins);
}

int fsiv_compute_histogram_percentile(cv::Mat const &hist, float percentile)
{
    CV_Assert(percentile >= 0.0 && percentile <= 1.0);
    CV_Assert(hist.type() == CV_32FC1);
    CV_Assert(hist.cols == 1);
    int idx = -1;
    // TODO
    // Hint: use cv::sum to compute the histogram area.
    // Remember: The percentile p is the first i that sum{h[0], h[1], ..., h[i]} >= p
        float total = cv::sum(hist)[0];

        if(percentile >= 1.0){
            return hist.rows - 1;
        }

        float sumatorio = 0;

        for(idx = 0; idx < hist.rows; idx++){
            sumatorio += hist.at<float>(idx, 0);
            if( sumatorio/total >= percentile){
                break;
            }
        }

        if( idx == hist.rows){
            idx = hist.rows - 1;
        }
    //
    CV_Assert(idx >= 0 && idx < hist.rows);
    CV_Assert(idx == 0 || cv::sum(hist(cv::Range(0, idx), cv::Range::all()))[0] / cv::sum(hist)[0] < percentile);
    CV_Assert(cv::sum(hist(cv::Range(0, idx + 1), cv::Range::all()))[0] / cv::sum(hist)[0] >= percentile);
    return idx;
}

float fsiv_histogram_idx_to_value(int idx, int n_bins, float max_value,
                                  float min_value)
{
    CV_Assert(idx >= 0);
    CV_Assert(idx < n_bins);
    float value = 0.0;
    // TODO
    // Remember: Map integer range [0, n_bins) into float
    // range [min_value, max_value)
        float rango_bin = (max_value - min_value)/n_bins;
        value = min_value + idx * rango_bin;
    //
    CV_Assert(value >= min_value);
    CV_Assert(value < max_value);
    return value;
}

cv::Mat fsiv_thinning_edge_map(cv::Mat const &edge_map)
{
    CV_Assert(edge_map.type() == CV_8UC1);
    cv::Mat thinned_edge_map;
    // TODO
    // We could use cv::ximgproc::thinning but you need to compile the separated OpenCV
    // extra module "ximgproc". We are going to implement a less effective but simpler
    // thinning algorithm based on distance transform and morphological dilation.
    //
    // Hint: Use distance L2 and kernel with size 5 in cv::distanceTransform()
    // to get the distance of a white pixel (edge) to the closest black pixel (non-edge).
    //
    // Hint: We want 8-connected thinning so use a 3x3 square structuring element in cv::dilate().
        cv::Mat dt;
    
        cv::distanceTransform(edge_map, dt, cv::DIST_L2, 5);

        cv::Mat dt_dilated;
        cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
        cv::dilate(dt, dt_dilated, element);

        cv::Mat local_maxima_mask = (dt == dt_dilated);

        thinned_edge_map = local_maxima_mask & edge_map;
    //
    CV_Assert(thinned_edge_map.type() == CV_8UC1);
    CV_Assert(thinned_edge_map.size() == edge_map.size());
    return thinned_edge_map;
}

void fsiv_percentile_edge_detector(cv::Mat const &gradient, cv::Mat &edges,
                                   float th, int n_bins)
{
    CV_Assert(gradient.type() == CV_32FC1);

    // TODO
    // Remember: user other fsiv_xxx to compute histogram and percentiles.
    // Remember: map histogram range {0, ..., n_bins} to the gradient range
    // {0.0, ..., max_grad}
    // Hint: use "operator >=" to threshold the gradient magnitude image.
        cv::Mat hist;
        float max_grad;
        fsiv_compute_gradient_histogram(gradient, n_bins, hist, max_grad);
        int idx = fsiv_compute_histogram_percentile(hist, th);
        float th_val = fsiv_histogram_idx_to_value(idx, n_bins, max_grad);
        edges = gradient >= th_val;
    //
    CV_Assert(edges.type() == CV_8UC1);
    CV_Assert(edges.size() == gradient.size());
}

void fsiv_otsu_edge_detector(cv::Mat const &gradient, cv::Mat &edges)
{
    CV_Assert(gradient.type() == CV_32FC1);

    // TODO
    // Hint: normalize input gradient into rango [0, 255] to use
    // cv::threshold properly.
    //  
        cv::Mat aux;
        cv::normalize(gradient, aux, 0.0, 255.0, cv::NORM_MINMAX);
        aux.convertTo(aux, CV_8UC1);
        cv::threshold(aux, edges, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
    //
    CV_Assert(edges.type() == CV_8UC1);
    CV_Assert(edges.size() == gradient.size());
}

void fsiv_canny_edge_detector(cv::Mat const &dx, cv::Mat const &dy, cv::Mat &edges,
                              float th1, float th2, int n_bins)
{
    CV_Assert(dx.size() == dy.size());
    CV_Assert(th1 < th2);

    // TODO
    // Hint: convert the intput derivatives to CV_16C1 to be used with canny.
    // Remember: th1 and th2 are given as percentiles so you must transform to
    //           gradient range to be used in canny method.
    // Remember: we compute gradients with L2_NORM so we must indicate this in
    //           the canny method too.
        cv::Mat dx_canny;
        cv::Mat dy_canny;

        dx.convertTo(dx_canny, CV_16SC1);
        dy.convertTo(dy_canny, CV_16SC1);

        cv::Mat gradient;
        fsiv_compute_gradient_magnitude(dx, dy, gradient);

        float max_grad;
        cv::Mat hist;
        fsiv_compute_gradient_histogram(gradient, n_bins, hist, max_grad);

        int idx1 = fsiv_compute_histogram_percentile(hist, th1);
        int idx2 = fsiv_compute_histogram_percentile(hist, th2);

        float th_1 = fsiv_histogram_idx_to_value(idx1, n_bins, max_grad);
        float th_2 = fsiv_histogram_idx_to_value(idx2, n_bins, max_grad);

        cv::Canny(dx_canny, dy_canny, edges, th_1, th_2, true);
    //
    CV_Assert(edges.type() == CV_8UC1);
    CV_Assert(edges.size() == dx.size());
}

void fsiv_compute_ground_truth_image(cv::Mat const &consensus_img,
                                     float min_consensus, cv::Mat &gt)
{
    //! TODO
    // Hint: use cv::normalize to normalize consensus_img into range (0, 100)
    // Hint: use "operator >=" to threshold the consensus image.
        cv::Mat consensus_normalized;
        cv::normalize(consensus_img, consensus_normalized, 0.0, 100.0, cv::NORM_MINMAX);
        gt = consensus_normalized >= min_consensus;
    //
    CV_Assert(consensus_img.size() == gt.size());
    CV_Assert(gt.type() == CV_8UC1);
}

void fsiv_compute_edge_detector_confusion_matrix(cv::Mat const &gt, cv::Mat const &pred, cv::Mat &cm)
{
    CV_Assert(gt.type() == CV_8UC1);
    CV_Assert(pred.type() == CV_8UC1);
    CV_Assert(gt.size() == pred.size());

    // TODO
    // Remember: a edge detector confusion matrix is a 2x2 matrix where the
    // rows are ground truth {Positive: "is edge", Negative: "is not edge"} and
    // the columns are the predictions labels {"is edge", "is not edge"}
    // A pixel value means edge if it is <> 0, else is a "not edge" pixel.
        cm = cv::Mat::zeros(2, 2, CV_32FC1);

        cv::MatConstIterator_<uint8_t> gt_it = gt.begin<uint8_t>();
        cv::MatConstIterator_<uint8_t> gt_end = gt.end<uint8_t>();
        cv::MatConstIterator_<uint8_t> pred_it = pred.begin<uint8_t>();

        while(gt_it != gt_end){

            int gt_idx = *gt_it ? 0 : 1;

            int pred_idx = *pred_it ? 0 : 1;

            cm.at<float>(gt_idx, pred_idx) += 1.0;

            gt_it++;
            pred_it++;
        }
    //
    CV_Assert(cm.type() == CV_32FC1);
    CV_Assert(cv::abs(cv::sum(cm)[0] - (gt.rows * gt.cols)) < 1.0e-6);
}

float fsiv_compute_sensitivity(cv::Mat const &cm)
{
    CV_Assert(cm.type() == CV_32FC1);
    CV_Assert(cm.size() == cv::Size(2, 2));
    float sensitivity = 0.0;
    // TODO
    // Hint: see https://en.wikipedia.org/wiki/Confusion_matrix
        return cm.at<float>(0, 0) / (cm.at<float>(0, 0) + cm.at<float>(0, 1));
    //
    return sensitivity;
}

float fsiv_compute_precision(cv::Mat const &cm)
{
    CV_Assert(cm.type() == CV_32FC1);
    CV_Assert(cm.size() == cv::Size(2, 2));
    float precision = 0.0;
    // TODO
    // Hint: see https://en.wikipedia.org/wiki/Confusion_matrix
        return cm.at<float>(0, 0) / (cm.at<float>(0, 0) + cm.at<float>(1, 0));
    //
    return precision;
}

float fsiv_compute_F1_score(cv::Mat const &cm)
{
    CV_Assert(cm.type() == CV_32FC1);
    CV_Assert(cm.size() == cv::Size(2, 2));
    float F1 = 0.0;
    // TODO
    // Hint: see https://en.wikipedia.org/wiki/Confusion_matrix
        return 2 * cm.at<float>(0, 0) / ( 2 * cm.at<float>(0, 0) + cm.at<float>(1, 0) + cm.at<float>(0, 1));
    //
    return F1;
}
