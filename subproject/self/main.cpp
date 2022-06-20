#include <opencv2/highgui.hpp>
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

bool compareContourAreas ( std::vector<cv::Point> contour1, std::vector<cv::Point> contour2 ) {
    double i = fabs( contourArea(cv::Mat(contour1)) );
    double j = fabs( contourArea(cv::Mat(contour2)) );
    return ( i < j );
}

//Compare the contour area (USB_Port_Lean is used for contour sorting)
bool Contour_Area(vector<Point> contour1, vector<Point> contour2)
{
  return contourArea(contour1)< contourArea(contour2);
}

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
    string a = "test.jpg";
    input = imread(a, IMREAD_COLOR);
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

    /* find contour */
    threshold(edge, edge, 128, 255, THRESH_BINARY);

    vector<vector<Point> > contours;
    Mat contourOutput = edge.clone();
    findContours(contourOutput,contours, RETR_TREE, CHAIN_APPROX_SIMPLE); // tim cac contour trong anh
    
    /* sort contours */
    sort(contours.begin(), contours.end(), compareContourAreas);

    /* grab contours */
    vector<Point> smallestContour = contours[contours.size()-1]; 
    vector<Point> biggestContour = contours[0]; 
    vector<Point> screenCnt;
    Mat approx, peri; 
    for (int i = 0; i < contours.size(); i++)
    {
        double peri = arcLength(contours[i],true);
        approxPolyDP(contours[i],approx, 0.018*peri,true);
        // cout << approx << endl;
        // cout << "ok" << endl;
        if (sizeof(approx) == 4){
            screenCnt = approx;
        }
        break;
    }

    // int detection =0;
    // if (screenCnt == )
    // {
    //     detection = 0;
    // }else
    // {
    //     detection = 1;
    // }
    
    // if (detection ==1 ){
    //     drawContours(input, screenCnt[],-1,(0,255,0),3);
    // }
    
    drawContours(input, screenCnt,-1,(0,255,0),3);
    

    /* Masking the part other than the number plate */
    Mat mask(480,620,CV_8UC3, Scalar(0,0,0));
    drawContours(mask, screenCnt, 0,255,-1);
    bitwise_and(input,input,mask=mask);

    /* Now crop */
    vector<vector<int>> xy;
    // for ( int i = 0; i <mask.rows; i ++)
    //     for ( int j = 0; j <mask.cols; j ++)
    //         if (mask.at <int> (i, j) == 255){
                
    //         }
    // int  ad[1000][1000];
    Mat a(480,620,CV_8UC3);
    
    // _OutputArray();
    // findNonZero(mask==255,a);

    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << ad[i][j];
    //     }
    // }
        
    /* Read the number plate */

    // imshow("intermediate",contours);
    waitKey(0);
    destroyAllWindows();
    
    return 0;
}