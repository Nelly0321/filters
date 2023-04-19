#include "filter.h"


std::vector<std::string> paths_to_paintings{
"",
"../art/Screenshot 2023-04-13 at 15.48.50.png", 
"../art/Screenshot 2023-04-14 at 22.07.08.png",
"../art/Screenshot 2023-04-18 at 16.06.42.png",
"../art/Screenshot 2023-04-18 at 19.20.24.png",
"../art/glasses_blue.png"
};


void regulate_size(cv::Mat& _image1,cv::Mat& _image2){
    if(_image1.rows>_image2.rows){
        cv::resize(_image1, _image1, cv::Size(_image1.cols, _image2.rows), cv::INTER_LINEAR);
        }else if(_image1.rows<_image2.rows){
        cv::resize(_image2, _image2, cv::Size(_image2.cols, _image1.rows), cv::INTER_LINEAR);
        }
    if(_image1.cols>_image2.cols){
        cv::resize(_image1, _image1, cv::Size(_image2.cols, _image1.rows), cv::INTER_LINEAR);
    }else if(_image1.cols<_image2.cols){
        cv::resize(_image2, _image2, cv::Size(_image1.cols, _image2.rows), cv::INTER_LINEAR);
    }
}

cv::Mat get_painting(Paintings p){
    std::string _path = paths_to_paintings[p];
    cv::Mat art = cv::imread(_path);
    return art;
}

void to_black(cv::Mat& _art, cv::Mat& _image){
    cv::cvtColor(_image, _image, CV_RGB2GRAY);
    cv::cvtColor(_art, _art, CV_RGB2GRAY);
}

void _AdamHands(cv::Mat& _image){
    cv::Mat _art = get_painting(AdamHands);
    to_black(_art, _image);
    regulate_size(_art, _image);
    cv::addWeighted(_image, 0.7, _art, 0.5, 0.0, _image);
    return;
}

void _add_rain(cv::Mat& _image){
    std::string rain_path = "/Users/NellyVardanyan/ACA/filter2/art/rain-texture-on-black-background-vector-31712235.jpg";
    cv::Mat rain = cv::imread(rain_path);
    regulate_size(rain, _image);
    cv:: addWeighted(_image, 0.9, rain, 0.7, 0.0, _image);
}
void _add_snow(cv::Mat& _image){
    std::string snow_path = "/Users/NellyVardanyan/ACA/filter2/art/Image Preview rain.jpg";
    cv::Mat snow = cv::imread(snow_path);
    regulate_size(snow,_image);
    cv:: addWeighted(_image, 0.9, snow, 0.7, 0.0, _image);
}
void _add_sparkles(cv::Mat& _image){
    std::string sparkles_path = "/Users/NellyVardanyan/ACA/filter2/art/skynews-star-sky-night-somerset_4641946.jpg";
    cv::Mat sparkles = cv::imread(sparkles_path);
    regulate_size(sparkles,_image);
    cv:: addWeighted(_image, 0.9, sparkles, 0.7, 0.0, _image);
}