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

    while(true) {
        Mat img;
        bool success = cap.read(img);
        if(success == false) {
            cout << "Video camera is disconnected" << endl;
            cin.get(); //Wiat for any key press
            break;
        }
        vector<Rect> faces;
        faceDetection.detectMultiScale(img, faces); //detects faces

        for(int i = 0; i < faces.size(); i ++) {
            Point p1(faces[i].x, faces[i].y);
            Point p2((faces[i].x + faces[i].height), (faces[i].y + faces[i].width));
            rectangle(img, p1, p2, Scalar(0, 0, 255), 2, 8, 0)
        }

        imshow("FACES", img);
        if(waitKey(10) == 27) {
            cout << "Escape has been pressed. stopping..." << endl;
            break;
        }
    }

    return 0;
}