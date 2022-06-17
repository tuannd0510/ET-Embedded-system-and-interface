#include <opencv2/highgui.hpp>
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(){
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
    Mat cnts; 
    // findContours(edge,cnts, RETR_TREE, CHAIN_APPROX_SIMPLE); // tim cac contour trong anh
    
    
    // sorted(); // sap xep dien tich contour giam dan

    // for (int i = 0; i < cnts; i++)
    // {
    //     Mat peri, approx;
    //     peri = arcLength(i, true);
    //     approxPolyDP(i,approx, 0.018 * peri, true);
        

    // }
    

    

    imshow("intermediate",edge);
    waitKey(0);
    destroyAllWindows();
    
    return 0;
}