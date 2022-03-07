#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//Resize and Crop

void main() {
	string path = "resimler/WallpaperDog-20497814.jpg";
	Mat img = imread(path);
	Mat imgResized, imgCrop;
	resize(img, imgResized, Size(780, 600));

	Rect roi(100, 100, 300, 250);
	imgCrop = img(roi);

	imshow("resim", img);
	imshow("resim2", imgResized);
	imshow("resim3", imgCrop);
	waitKey(0);






}