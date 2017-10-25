#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include "Header.h"
using namespace cv;
using namespace std;




int main() {
	Mat img = imread("lena.jpg",CV_LOAD_IMAGE_COLOR);
	Mat pic,pic1;
	int Width = img.rows;
	int Height = img.cols;
	int matrix[4][4] = { 0, 8, 2,10,
						12, 4,14, 6,
						 3,11, 1, 9,
						15, 7,13,5 };

	

	img = gray(img, Width, Height);

	pic = tran(img, Width, Height);

	pic1 = dith(img, Width, Height, matrix);
	//pic1 = draw(pic1, Width, Height);

	namedWindow("Display gray", WINDOW_AUTOSIZE);
	imshow("Display gray", img);
	namedWindow("Display", WINDOW_AUTOSIZE);
	imshow("Display", pic);
	namedWindow("Display1", WINDOW_AUTOSIZE);
	imshow("Display1", pic1);
	waitKey(0);

	return 0;
}


