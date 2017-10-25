#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;


Mat gray(Mat src, int Width, int Height) {

	Mat gray_image = Mat(Width, Height, CV_8U);


	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			float b = src.at<Vec3b>(i, j)[0];// 取出彩色圖像中i行j列藍色的顏色點
			float g = src.at<Vec3b>(i, j)[1];// 取出彩色圖像中i行j列綠色的顏色點
			float r = src.at<Vec3b>(i, j)[2];// 取出彩色圖像中i行j列紅色的顏色點
			float average = (r + g + b) / 3;
			int fin = round(average);
			gray_image.at<uchar>(i, j) = fin;
		}
	}
	return gray_image;
}



Mat tran(Mat src, int Width, int Height)
{
	Mat image = Mat(Width * 2, Height * 2, CV_8U);
	int check, x, y;

	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			
			float a = src.at<uchar>(i, j);
			a = a / 51;
			a = floor(a);

			check = a;
			x = i * 2; y = j * 2;

			switch (check)
			{
			case 0:
				image.at<uchar>(x, y) = 0;
				image.at<uchar>(x + 1, y) = 0;
				image.at<uchar>(x, y + 1) = 0;
				image.at<uchar>(x + 1, y + 1) = 0;
				break;

			case 1:
				image.at<uchar>(x, y) = 255;
				image.at<uchar>(x + 1, y) = 0;
				image.at<uchar>(x, y + 1) = 0;
				image.at<uchar>(x + 1, y + 1) = 0;
				break;
			case 2:
				image.at<uchar>(x, y) = 255;
				image.at<uchar>(x + 1, y) = 0;
				image.at<uchar>(x, y + 1) = 0;
				image.at<uchar>(x + 1, y + 1) = 255;
				break;
			case 3:
				image.at<uchar>(x, y) = 255;
				image.at<uchar>(x + 1, y) = 255;
				image.at<uchar>(x, y + 1) = 0;
				image.at<uchar>(x + 1, y + 1) = 255;
				break;
			case 4:
				image.at<uchar>(x, y) = 255;
				image.at<uchar>(x + 1, y) = 255;
				image.at<uchar>(x, y + 1) = 255;
				image.at<uchar>(x + 1, y + 1) = 255;
				break;

			default:
				break;
			}

		}
	}
	return image;
}

Mat dith(Mat src, int Width, int Height,int matrix[4][4]) {

	
	

	Mat image = Mat(Width, Height, CV_8U);

	
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
		
			int m = i % 4;
			int n = j % 4;
			int p, q;
			float x = src.at<uchar>(i, j);
			x = x / 256 * 16;
			x = floor(x);

			if (x > matrix[m][n]) {
				image.at<uchar>(i, j) = 255;
			}
			else {
				image.at<uchar>(i, j) = 0;
			}
		}
	}

	return image;
}

Mat draw(Mat src, int Width, int Height) {

	Mat image = Mat(Width, Height, CV_8U);
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{


			float x = src.at<uchar>(i, j);
			x = x * 255;
			x = floor(x);
			image.at<uchar>(i, j) = x;
			
		}
	}

	return image;


}