#pragma once
#include <iostream>
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <vector>

enum Paintings{
    MonaLisa = 1,
    AdamHands,
    Pearl,
    BlackGlasses,
    BlueGlasses,
    Snow,
    Sparkles,
    Rain,
    Grain,
    Date,
    FiveColors,
    Panorama
};
  
void _AdamHands(cv::Mat&);
void _add_rain(cv::Mat&);
void _add_snow(cv::Mat&);
void _add_sparkles(cv::Mat&);