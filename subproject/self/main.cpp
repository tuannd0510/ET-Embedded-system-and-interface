#include <opencv2/highgui.hpp>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

int main(){
    // VideoCapture videoCapture;
    // Mat videoFrame;

    // // open camera
    // videoCapture.open(0);
    // namedWindow("VideoCapture", WINDOW_AUTOSIZE);

    // // check open camera open sucessed or failed
    // if(!videoCapture.isOpened())
    // {
    //     cout << "Can't open camera" << endl;
    // }
    // else
    // {
    //     while (true)
    //     {
    //         //read video frame from camera and show in windows
    //         videoCapture.read(videoFrame);
    //         imshow("VideoCapture", videoFrame);
    //         if(waitKey(30) >= 0) break;
    //     }
    // }



    Mat input, intermediate, iblur, edge, output;

    input = imread("/home/tuannd/workspace/Embedded-system-and-interface/subproject/Aswinth-Raj-21/src/aa.png", IMREAD_COLOR);
    if(! input.data){
        cout<<"Could not open file" << endl;
        return -1;
    } 
    
    namedWindow("input image", WINDOW_AUTOSIZE);
    imshow("input image", input);
    waitKey(0);

    resize(input, intermediate, Size(620,480)); //resize 620,480
    cvtColor(intermediate, intermediate, COLOR_BGR2GRAY); // gray
    bilateralFilter(intermediate, iblur, 15, 80, 80, BORDER_DEFAULT); // blur
    Canny(iblur, edge, 30,200); // perform edge detection

    // find contour
    threshold(edge, edge, 128, 255, THRESH_BINARY);

    vector<std::vector<cv::Point> > contours;
    Mat contourOutput = edge.clone();
    findContours(contourOutput,contours, RETR_TREE, CHAIN_APPROX_SIMPLE); // tim cac contour trong anh
    
    //Draw the contours
    cv::Mat contourImage(edge.size(), CV_8UC3, cv::Scalar(0,0,0));
    cv::Scalar colors[3];
    colors[0] = cv::Scalar(255, 0, 0);
    colors[1] = cv::Scalar(0, 255, 0);
    colors[2] = cv::Scalar(0, 0, 255);
    for (size_t idx = 0; idx < contours.size(); idx++) {
        cv::drawContours(contourImage, contours, idx, colors[idx % 3]);
    }

    imshow("Input Image", edge);
    moveWindow("Input Image", 0, 0);
    imshow("Contours", contourImage);
    moveWindow("Contours", 200, 0);
    waitKey(0);
    // sorted(); // sap xep dien tich contour giam dan

    // for (int i = 0; i < cnts; i++)
    // {
    //     Mat peri, approx;
    //     peri = arcLength(i, true);
    //     approxPolyDP(i,approx, 0.018 * peri, true);
        

    // }
    

    

    // imshow("intermediate",contours);
    // waitKey(0);
    destroyAllWindows();
    
    return 0;
}