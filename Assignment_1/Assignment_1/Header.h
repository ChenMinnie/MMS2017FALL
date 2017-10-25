#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

Mat gray(Mat, int, int);
Mat tran(Mat, int, int);
Mat dith(Mat, int, int, int[4][4]);
Mat draw(Mat, int, int);