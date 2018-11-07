/* 
C++ code to implement a trackbar
Author: Salah Eddine Ghamri.
 */
#include "gui_cv.hpp"
using std::cout;
using std::endl;

int main(){

    help();
    src1 = imread("C:\\Users\\Utilisateur\\Pictures\\photo_day.png");
    if(!src1.data){printf("Error loading src1 \n");}
    // src1.cols & src1.rows // src.size().width & src.size().height
    src2 = imread("C:\\Users\\Utilisateur\\Pictures\\photo_night.png");
    if(!src2.data){printf("Error loading src2 \n");}
    resize(src2, src2, Size(src1.cols, src1.rows));

    //int slider
    alpha_slider = 0;

    //create window
    //namedWindow( "Display window ", WINDOW_AUTOSIZE);

    /*
    namedWindow( "Day window", WINDOW_AUTOSIZE );
    namedWindow( "Night window", WINDOW_AUTOSIZE );
    imshow("Day window", src1);
    imshow("Night window", src2);
    */

    
    //create named widow 
    namedWindow( "Linear Blend", WINDOW_AUTOSIZE);

    //create a trackbar
    char TrackbarName[50]; //array of type char of 50 element
    sprintf_s( TrackbarName, "Alpha x %d", alpha_slider_max );
    createTrackbar( TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar);

    // show magic
    on_trackbar( alpha_slider, 0);
    
    waitKey(0);
    return EXIT_SUCCESS;
}