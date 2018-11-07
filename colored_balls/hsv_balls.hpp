#ifndef HSV_BALLS
#define HSV_BALLS
//C++
#include <iostream>
#include <string>
//Opencv
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;

//variables declarations:
extern Mat input_img, HSV_img, output_img;
extern const int max_value_H;
extern const int max_value;
extern const String window_capture_name;
extern const String window_detection_name;
extern int low_H, low_S, low_V;
extern int high_H, high_S, high_V;

//functions declarations:
void help();
void on_low_H_thresh_trackbar(int, void *);
void on_high_H_thresh_trackbar(int, void *);
void on_low_S_thresh_trackbar(int, void *);
void on_high_S_thresh_trackbar(int, void *);
void on_low_V_thresh_trackbar(int, void *);
void on_high_V_thresh_trackbar(int, void *);

#endif HSV_BALLS