#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

float w = 500, h = 350;

Mat matrix, imgWarp;

void main() {

	string path = "resimler/012ee5102429589.5f362d0a2ea4d.jpg";
	Mat img = imread(path);

	Point2f src[4] = { {284, 159}, {471, 366}, {97, 239}, {274, 476} };
	Point2f dst[4] = { {0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	for (int i = 0; i < 4; i++)
		circle(img, src[i], 10, Scalar(0, 0, 0), FILLED);

	imshow("Resim", img);
	imshow("warped", imgWarp);

	waitKey(0);






}