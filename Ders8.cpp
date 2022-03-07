#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat imgGray, imgBlur, imgCanny, imgDil;


void getContours(Mat imgDil, Mat img) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);


	for (int i = 0; i < contours.size(); i++) {
		int area = contourArea(contours[i]);
		cout << area << endl;

		vector<vector<Point>> conPoly(contours.size());
		vector<Rect> boundRect(contours.size());
		string objectType;
		if (area > 2000) {
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
		
			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);
	
			int objCor = (int)conPoly[i].size();

			if (objCor == 3) {
				objectType = "Ucgen";
			}
			if (objCor == 4) {

				float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
				if (aspRatio > 0.95 && aspRatio < 1.05) {
					objectType = "Kare";
					}else
					objectType = "Dortgen";
			}
			if (objCor > 5) {
				objectType = "Daire";
			}

			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 0, 0), 5);
			putText(img, objectType, { boundRect[i].x, boundRect[i].y - 5 }, FONT_HERSHEY_DUPLEX, 0.75, Scalar(11, 11, 11), 2);





				
		}
	}
}


void main() {

	string path = "resimler/cQEAu.png";
	Mat img = imread(path);

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);
	getContours(imgDil, img);

	imshow("Resim", img);
	
	waitKey(0);
}