#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace std;
using namespace cv;


void main() {

	// Blank img
	Mat img(512, 512, CV_8UC3, Scalar(0, 0, 0));

	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), 3);
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);


	putText(img, "Ozgur Emre", Point(160, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(11, 11, 11), 2);

	imshow("Resim", img);

	waitKey(0);








}