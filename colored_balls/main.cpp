/* 
C++ code to implement color filtering is HSV colorspace
Author: Salah Eddine Ghamri.
 */
#include "hsv_balls.hpp"
using std::cout;
using std::endl;

int main(){

    help();
    input_img = imread("C:\\Users\\Utilisateur\\Pictures\\colored_balls.jpg");
    if(!input_img.data){printf("Error loading image \n");}
    resize(input_img, input_img, cv::Size(), 0.5, 0.5);

    //create named widows
    namedWindow( window_capture_name, WINDOW_NORMAL);
    namedWindow( window_detection_name, WINDOW_NORMAL);

    resizeWindow(window_capture_name, 300, 300);
    //resizeWindow(window_detection_name, 300, 300);

    //create a trackbar
    createTrackbar("Low H", window_detection_name, &low_H, max_value_H, on_low_H_thresh_trackbar);
    createTrackbar("High H", window_detection_name, &high_H, max_value_H, on_high_H_thresh_trackbar);
    createTrackbar("Low S", window_detection_name, &low_S, max_value, on_low_S_thresh_trackbar);
    createTrackbar("High S", window_detection_name, &high_S, max_value, on_high_S_thresh_trackbar);
    createTrackbar("Low V", window_detection_name, &low_V, max_value, on_low_V_thresh_trackbar);
    createTrackbar("High V", window_detection_name, &high_V, max_value, on_high_V_thresh_trackbar);
    
    // convert from BGR to HSV colorspace
    cvtColor(input_img, HSV_img, COLOR_BGR2HSV);
    while(true){
        // Detect the object based on HSV Range Values
        inRange(HSV_img, Scalar(low_H, low_S, low_V), Scalar(high_H, high_S, high_V), output_img);
        
        //show stuff
        imshow( window_capture_name, input_img);
        imshow( window_detection_name, output_img);
        
        //Make loop stop-> programme exit
        char key = (char) waitKey(30);
        if (key == 'q' || key == 27)
        {
            break;
        }
    }
    return EXIT_SUCCESS;
}