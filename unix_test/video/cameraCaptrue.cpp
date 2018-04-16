#include<stdio.h>  
#include<math.h>  
#include "highgui.h"  
#include <cv.h>  
#include <opencv2/opencv.hpp>  
#include <opencv2/highgui/highgui.hpp>  
  
//#include <cvaux.h>  
//#include <highgui\highgui_c.h>  
//#include <core\types_c.h>  
//#include <photo\photo_c.h>  
//#include <imgproc\imgproc_c.h>  
//#include <photo\photo  
  
using namespace cv;  
  
  
int main( int argc, char** argv )  
{  
    printf("I am start \n");  
    VideoCapture cap(0); // open the default camera  
    if(!cap.isOpened())  // check if we succeeded  
        return -1;  
  
    printf("%f, %f\n",cap.get(CV_CAP_PROP_FRAME_WIDTH),cap.get(CV_CAP_PROP_FRAME_HEIGHT));  
    cap.set(CV_CAP_PROP_FRAME_WIDTH, 320);  
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 240);  
    cap.set(CV_CAP_PROP_FPS, 15);  
    printf("%f, %f\n",cap.get(CV_CAP_PROP_FRAME_WIDTH),cap.get(CV_CAP_PROP_FRAME_HEIGHT));  
    Mat src_gray;  
    cvNamedWindow( "video", CV_WINDOW_AUTOSIZE );  
  
    while(1)  
    {  
        Mat frame;  
        cvWaitKey(10);  
        cap >> frame;  
        imshow("video", frame);  
    }  
  
  
    return 0;  
}  
