#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


using namespace std;
using namespace cv;


void main() {
	string path = "resimler/WallpaperDog-20497814.jpg";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDia, imgErode;

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(3, 3), 3, 0 );
	Canny(imgBlur, imgCanny, 50, 150);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
	dilate(imgCanny, imgDia, kernel);
	erode(imgDia, imgErode, kernel);


	imshow("image2", imgCanny);
	imshow("image3", imgDia);
	imshow("image4", imgErode);
	
	
	waitKey(0);




}