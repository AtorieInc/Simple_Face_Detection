#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    CascadeClassifier faceDetection;

    if(!faceDetection.load("/home/nstg/opencv_build/opencv/data/haarcascades/haarcascade_frontalface_default.xml")) {
        cout << "File not found [404]" << endl;
        exit(0);
    }
    VideoCapture cap(0);

    string winName = "WebCam Record";
    namedWindow(winName);

    
}