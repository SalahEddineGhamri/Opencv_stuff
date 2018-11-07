#include "gui_cv.hpp"
using namespace std;
using namespace cv;


/// Global Variables
const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;

/// Matrices to store images
Mat src1;
Mat src2;
Mat dst;

/// function implemntations
void help()
{
    cout
    << "--------------------------------------------------------------------------" << endl
    << "This program implements gui mechanism in opencv                           "  << endl
    << "Authon : Salah Eddine Ghamri"                                              << endl;
}

/**
 * @function on_trackbar
 * @brief Callback for trackbar
 */
void on_trackbar( int, void* ){
    alpha = (double) alpha_slider/alpha_slider_max ;
    beta = ( 1.0 - alpha );
    //dst = src1*alpha + src2*beta + gamma;
    addWeighted( src2, alpha, src1, beta, 0.0, dst);
    imshow( "Linear Blend", dst );
}