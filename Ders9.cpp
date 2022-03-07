#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>


using namespace std;
using namespace cv;

void main() {


	VideoCapture cap(0);
	Mat img;
	CascadeClassifier faceCascade;
	faceCascade.load("resimler/haarcascade_frontalface_default.xml");

	if (faceCascade.empty()) {
		cout << "XML file not loaded" << endl;
	}
	vector<Rect> faces;


	while (true)
	{
		cap.read(img);
		faceCascade.detectMultiScale(img, faces, 1.1, 10);

		for (int i = 0; i < faces.size(); i++)
		{
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 255, 255), 3);
			putText(img, "Insan", { faces[i].x, faces[i].y - 5 }, FONT_HERSHEY_DUPLEX, 0.75, Scalar(11, 11, 11), 2);
		}
		
		imshow("Video", img);
		waitKey(1);


	}



}
