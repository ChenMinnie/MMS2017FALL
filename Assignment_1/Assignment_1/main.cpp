#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include "Header.h"
using namespace cv;
using namespace std;




int main() {
	Mat img = imread("lena1.jpg",CV_LOAD_IMAGE_COLOR);
	Mat pic;

	int Width = img.rows;
	int Height = img.cols;
	img = gray(img, Width, Height);

	pic = tran(img, Width, Height);
	
	namedWindow("Display gray", WINDOW_AUTOSIZE);
	imshow("Display gray", img);
	namedWindow("Display", WINDOW_AUTOSIZE);
	imshow("Display", pic);
	waitKey(0);

	return 0;
}


