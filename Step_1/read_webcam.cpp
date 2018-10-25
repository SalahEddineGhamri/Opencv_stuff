#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main(int, char**)
{
    VideoCapture cap(0);
    if(!cap.isOpened())
        return -1;

    Mat edges;
    Mat normal;
    namedWindow("edges",1);
    namedWindow("normal", 1);
    for(;;)
    {
        Mat frame;
        cap >> frame;
        cvtColor(frame, edges, COLOR_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);
        imshow("normal", frame);
        if(waitKey(30) >= 0) break;
    }

    return 0;
}