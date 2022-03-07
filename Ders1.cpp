#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>


using namespace std;
using namespace cv;
//
// Resim //
//void main() {
//
//	string path = "resimler/unnamed.jpg";
//	Mat img = imread(path);
//	imshow("Resim", img);
//	waitKey(0);
//
//
//
//
//}
// Video //
//void main() {
//
//	string path = "resimler/20191205_215707.mp4";
//	VideoCapture cap(path);
//	Mat img;
//
//	while (true)
//	{
//		cap.read(img);
//		imshow("Video", img);
//		waitKey(20);
//
//
//	}
//
//
//
//	}
// WebCam//

void main() {

	
	VideoCapture cap(0);
	Mat img;

	while (true)
	{
		cap.read(img);
		imshow("Video", img);
		waitKey(1);


	}



}