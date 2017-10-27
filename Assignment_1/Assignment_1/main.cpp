#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include "Header.h"
using namespace cv;
using namespace std;




int main() {
	Mat img = imread("lena256.jpg",CV_LOAD_IMAGE_COLOR);
	Mat pic,pic1,pic2,pic_gray;
	int Width = img.rows;
	int Height = img.cols;
	int matrix_origin[4][4] = { 0, 8, 2,10,
						12, 4,14, 6,
						 3,11, 1, 9,
						15, 7,13,5 };

	int matrix_test[4][4] = { 0, 11, 2, 15,
						 5, 10, 1, 7,
						 6, 9, 4, 13,
						 8, 3,12, 14};
	

	pic_gray = gray(img, Width, Height);

	pic = tran(pic_gray, Width, Height);

	pic1 = dith(pic_gray, Width, Height, matrix_origin);
    //pic1 = draw(pic1, Width, Height);
	pic2 = dith(pic_gray, Width, Height, matrix_test);
	

	namedWindow("Display origin", WINDOW_AUTOSIZE);
	imwrite("Origin.jpg", img);
	imshow("Display origin", img);

	namedWindow("Display gray image", WINDOW_AUTOSIZE);
	imwrite("Gray image.jpg", pic_gray);
	imshow("Display gray image", pic_gray);

	namedWindow("Display method one", WINDOW_AUTOSIZE);
	imwrite("Method one.jpg", pic);
	imshow("Display method one", pic);
	
	namedWindow("Display method two", WINDOW_AUTOSIZE);
	imwrite("Method two.jpg", pic1);
	imshow("Display method two", pic1);
	
	namedWindow("Display method two test", WINDOW_AUTOSIZE);
	imwrite("Method two test.jpg", pic2);
	imshow("Display method two test", pic2);
	waitKey(0);

	return 0;
}


