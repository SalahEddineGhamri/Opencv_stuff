#ifndef GUI_CV
#define GUI_CV
//C++
#include <iostream>
//Opencv
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;

//variables declarations:
extern int alpha_slider;
extern const int alpha_slider_max;
extern Mat src1;
extern Mat src2;
extern Mat dst;

//functions declarations:
void help();
void on_trackbar( int, void* );
#endif GUI_CV