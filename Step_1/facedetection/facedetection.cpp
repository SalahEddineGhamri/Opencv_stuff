#include <iostream>
#include <stdio.h>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/video.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

/** Fucntion headers */ 
void detectAndDisplay( Mat frame );

/** Global variables for face and eyes detection */
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
String face_cascade_name = "C:/Users/Utilisateur/Opencv/opencv-3.4.3/data/haarcascades/haarcascade_frontalface_alt.xml";
String eyes_cascade_name = "C:/Users/Utilisateur/Opencv/opencv-3.4.3/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";

int main( int argc, const char** argv ){

    Mat frame;

    //--1. load the cascades
    if( !face_cascade.load( face_cascade_name) ){
        printf("--(!) Error loading face cascade \n");
        return -1;
    }

    if( !eyes_cascade.load( eyes_cascade_name) ){
        printf("--(!) Error loading eyes cascade \n");
        return -1;
    }
    //--2. Read video stream
    VideoCapture capture(0);

    if ( capture.isOpened() ){
        while( true ){
            //capture >> frame;
            // capture frame by frame :
            capture.read(frame);
            // apply something 
            if ( !frame.empty() ){
                detectAndDisplay( frame );
                //printf(" Cam is on baby !!!");
            }else{
                printf(" no captured frame !!!");
                break;
            }

            if(waitKey(30) >= 0) break;
        }
    }
    return 0;
}

void detectAndDisplay( Mat frame ){
    // turn image to gray
    Mat frame_gray;
    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray);

    //--detect face
    vector<Rect> faces;
    face_cascade.detectMultiScale( frame_gray, faces);

    for ( size_t i=0; i<faces.size(); i++){
        Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2);
        Point P1(faces[i].x, faces[i].y);
        Point P2(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
        //ellipse( frame, center, Size(faces[i].width/2, faces[i].height/2), 0, 0, 360, Scalar( 0, 191, 255), 2);
        rectangle( frame, P1, P2, Scalar(0, 255, 0), 2);
        //Mat faceROI = frame_gray( faces[i] );
    }

    imshow( " image ", frame);
}