#include "hsv_balls.hpp"
using namespace std;
using namespace cv;

/// Global Variables
/// H: low=0->high=180, S: low=0->high=255, V: low=0->high=255
const int max_value_H = 360/2;
const int max_value = 255;
const String controlWindow = "Controls";
const String window_capture_name = "Image";
const String window_detection_name = "Filtered_image";
int low_H = 0, low_S = 0, low_V = 0;
int high_H = max_value_H, high_S = max_value, high_V = max_value;

/// Matrices to store images
Mat input_img, HSV_img, output_img;

/// function implemntations
void help()
{
    cout
    << "--------------------------------------------------------------------------" << endl
    << "This programs applies a color filterig on a image                        "  << endl
    << "Authon : Salah Eddine Ghamri"                                               << endl;
}

void on_low_H_thresh_trackbar(int, void *)
{
    low_H = min(high_H-1, low_H);
    setTrackbarPos("Low H", controlWindow, low_H);
}

void on_high_H_thresh_trackbar(int, void *)
{
    high_H = max(high_H, low_H+1);
    setTrackbarPos("High H", controlWindow, high_H);
}

void on_low_S_thresh_trackbar(int, void *)
{
    low_S = min(high_S-1, low_S);
    setTrackbarPos("Low S", controlWindow, low_S);
}

void on_high_S_thresh_trackbar(int, void *)
{
    high_S = max(high_S, low_S+1);
    setTrackbarPos("High S", controlWindow, high_S);
}

void on_low_V_thresh_trackbar(int, void *)
{
    low_V = min(high_V-1, low_V);
    setTrackbarPos("Low V", controlWindow, low_V);
}

void on_high_V_thresh_trackbar(int, void *)
{
    high_V = max(high_V, low_V+1);
    setTrackbarPos("High V", controlWindow, high_V);
}