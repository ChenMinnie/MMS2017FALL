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
			float translate = (r + g + b) / 3;
			int fin = round(translate);
			gray_image.at<char>(i, j) = fin;
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


			float a = src.at<char>(i, j);
			a = (a + 255) / 2 / 51;
			a = floor(a);


			check = a;
			x = i * 2; y = j * 2;
			switch (check)
			{
			case 0:
				image.at<char>(x, y) = 0;
				image.at<char>(x + 1, y) = 0;
				image.at<char>(x, y + 1) = 0;
				image.at<char>(x + 1, y + 1) = 0;
				break;

			case 1:
				image.at<char>(x, y) = 255;
				image.at<char>(x + 1, y) = 0;
				image.at<char>(x, y + 1) = 0;
				image.at<char>(x + 1, y + 1) = 0;
				break;
			case 2:
				image.at<char>(x, y) = 255;
				image.at<char>(x + 1, y) = 0;
				image.at<char>(x, y + 1) = 0;
				image.at<char>(x + 1, y + 1) = 255;
				break;
			case 3:
				image.at<char>(x, y) = 255;
				image.at<char>(x + 1, y) = 255;
				image.at<char>(x, y + 1) = 0;
				image.at<char>(x + 1, y + 1) = 255;
				break;
			case 4:
				image.at<char>(x, y) = 255;
				image.at<char>(x + 1, y) = 255;
				image.at<char>(x, y + 1) = 255;
				image.at<char>(x + 1, y + 1) = 255;
				break;

			default:
				break;
			}

		}
	}
	return image;
}