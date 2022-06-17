#include <opencv2/highgui.hpp>
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(){
    Mat input, intermediate , output;
    input = imread("test.jpg", IMREAD_COLOR);
    if(! input.data){
        cout<<"Could not open file" << endl;
        return -1;
    } 
    
    namedWindow("input image", WINDOW_AUTOSIZE);
    imshow("input image", input);
    waitKey(0);

    resize(input, intermediate, Size(620,480)); //resize 620,480
    cvtColor(intermediate, intermediate, COLOR_BGR2GRAY); // gray
    bilateralFilter(intermediate, intermediate, 11, 17, 17, BORDER_DEFAULT); // blur
    // Canny(intermediate, intermediate, 30,200); // perform edge detection

    // find contour
    // findContours(intermediate, intermediate, RETR_TREE, CHAIN_APPROX_SIMPLE);



    

    imshow("intermediate",intermediate);
    waitKey(0);
    destroyAllWindows();
    
    return 0;
}