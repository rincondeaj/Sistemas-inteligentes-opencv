
#include "common_code.hpp"

void 
fsiv_find_min_max_loc_1(cv::Mat const& input,
    std::vector<cv::uint8_t>& min_v, std::vector<cv::uint8_t>& max_v,
    std::vector<cv::Point>& min_loc, std::vector<cv::Point>& max_loc)
{
    CV_Assert(input.depth()==CV_8U);

    //! TODO: do a rows/cols scanning to find the first min/max values. 
    // Hint: use cv::split to get the input image channels.
        std::vector<cv::Mat> output;
        cv::split(input, output);
        
        // IMPORTANTE: Redimensionar vectores de salida
        //min_v.resize(output.size());
        //max_v.resize(output.size());
        //min_loc.resize(output.size());
        //max_loc.resize(output.size());

        for(size_t i=0; i<output.size(); i++){
            cv::uint8_t min_aux = output[i].at<uint8_t>(0,0);
            cv::uint8_t max_aux = output[i].at<uint8_t>(0,0);
            cv::Point min_loc_aux = cv::Point(0,0);
            cv::Point max_loc_aux = cv::Point(0,0);
            for(int row=0; row<input.rows; row++){
                for(int col=0; col<input.cols; col++){
                    if(output[i].at<uint8_t>(row,col) < min_aux){
                        min_aux = output[i].at<uint8_t>(row,col);
                        min_loc_aux = cv::Point(col,row);
                    }
                    else if(output[i].at<uint8_t>(row,col) > max_aux){
                        max_aux = output[i].at<uint8_t>(row,col);
                        max_loc_aux = cv::Point(col,row);
                    }
                }
            }
            min_v[i] = min_aux;
            max_v[i] = max_aux;
            min_loc[i] = min_loc_aux;
            max_loc[i] = max_loc_aux;
        }
    //

    CV_Assert(input.channels()==min_v.size());
    CV_Assert(input.channels()==max_v.size());
    CV_Assert(input.channels()==min_loc.size());
    CV_Assert(input.channels()==max_loc.size());
}

void 
fsiv_find_min_max_loc_2(cv::Mat const& input,
    std::vector<double>& min_v, std::vector<double>& max_v,
    std::vector<cv::Point>& min_loc, std::vector<cv::Point>& max_loc)
{

    //! TODO: Find the first min/max values using cv::minMaxLoc function.    
    // Hint: use cv::split to get the input image channels.
        
        std::vector<cv::Mat> output;
        cv::split(input, output);
        
        // IMPORTANTE: Redimensionar vectores de salida
        min_v.resize(output.size());
        max_v.resize(output.size());
        min_loc.resize(output.size());
        max_loc.resize(output.size());

        for(int i=0; i<output.size(); i++){
            cv::minMaxLoc(output[i], &min_v[i], &max_v[i], &min_loc[i], &max_loc[i]);
        }

    //

    CV_Assert(input.channels()==min_v.size());
    CV_Assert(input.channels()==max_v.size());
    CV_Assert(input.channels()==min_loc.size());
    CV_Assert(input.channels()==max_loc.size());

}