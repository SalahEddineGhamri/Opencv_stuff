#include <iostream>
#include <stdio.h>

#include <opencv2/opencv.hpp>
#include <opencv2/video.hpp>

using namespace std;
using namespace cv;


int main( int argc, const char** argv ){

    Mat frame;
    //Read video stream
    VideoCapture capture(0);
    namedWindow("frame", 1);

    if ( capture.isOpened() ){
        while( true ){
            //capture >> frame;
            // capture frame by frame :
            capture.read(frame);
            // apply something 
            if ( !frame.empty() ){
                imshow("frame", frame);
                //printf(" Cam is on baby !!!");
            }else{
                printf(" no captured frame !!!");
                break;
            }

            int c = waitKey( 10 );
            if( (char) c == 'c' ){
                break;
            }
        }
    }
    return 0;
}