#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <cstdio>
#include <opencv2/opencv.hpp>
#define N 16.0
#define S 31.0


using namespace cv;
using namespace std;
double MAD(IplImage * C, IplImage *R, int i, int j,int X0,int Y0);
void Sequential(IplImage * C, IplImage *R,Mat ip2, int x, int y);

int P = (S - 1) / 2;


int main() {

	char FReference[] = "i1.pgm"; 
	char FTarget[] = "i2.pgm"; 

	IplImage *image_R; 
	IplImage *image_C; 

	image_R = cvLoadImage(FReference, CV_LOAD_IMAGE_UNCHANGED); 
	image_C = cvLoadImage(FTarget, CV_LOAD_IMAGE_UNCHANGED); 
															 //if (!image) {
															 //	cout << "Error: Couldn't open the image file.\n";
															 //}
								 //	Mat mat2 = cvarrToMat(image_R);
	Mat MatC = cvarrToMat(image_C);
	Mat MatR = cvarrToMat(image_R);
	Mat ip2 = cvarrToMat(image_R);
	int u, v;

	int y0 = N / 2; int x0 = N / 2; 

	for (x0 = N / 2; x0 < image_C->width; x0 = x0 + N) {
		
		for (y0 = N / 2; y0 < image_C->height; y0 = y0 + N) {
 
		    Sequential(image_C, image_R, ip2, x0, y0);
	
		}
	}
	
	//Sequential(image_C, image_R, x,y);
	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", ip2);

	cvShowImage("Reference", image_R); 
	cvShowImage("Target", image_C);
	cvWaitKey(0);		
	cvDestroyWindow("Reference"); 
	cvDestroyWindow("Target"); 
	cvReleaseImage(&image_R); 
	cvReleaseImage(&image_C); 
	return EXIT_SUCCESS;
}

double MAD(IplImage * C, IplImage *R, int i, int j,int X0,int Y0) {

	int x = X0 - (N / 2.0), y = Y0 - (N / 2.0);

	Mat matC = cvarrToMat(C);
	Mat matR = cvarrToMat(R);
	
	double a = 1 / (N * N);
	double mad = 0;
	double add = 0;

	for (int k = 0; k < N - 1; k++) {
		for (int l = 0; l < N - 1; l++) {

			int nC = x + k + P;
			int mC = y + l + P;

			if (nC >= matC.rows - 1) nC = matC.rows - 1;
			if (mC >= matC.cols - 1) mC = matC.cols - 1;
			
			//printf("x%d\n", nC);
			//printf("y%d\n", mC);

			double Cvalue =  matC.at<uchar>(nC, mC);

			int nR = x + i + k + P;
			int mR = y + j + l + P;

			if (nR >= matC.rows - 1) nR = matC.rows - 1;
			if( mR >= matC.cols - 1) mR = matC.cols - 1;
			

			double Rvalue = matR.at<uchar>(nR, mR);

			add += abs(Cvalue - Rvalue);
		}
	}

	mad = a * add;
	return mad;
}

void Sequential(IplImage * C, IplImage *R, Mat ip2,int x0,int y0) {

	
	int u=0, v = 0;
	//Mat matC = cvarrToMat(C);
	Mat matR = cvarrToMat(R);
	Mat dst(matR.rows, matR.cols, CV_8U);
	double cur_MAD = 0;
	double min_MAD = 10000.0;

	for (int i = -P; i <= P; i++) {
		for (int j = -P; j <= P; j++) {
			
			cur_MAD = MAD(C, R, i, j, x0, y0);

			if (cur_MAD < min_MAD) {

				min_MAD = cur_MAD; 

				u = i, v = j;
			}
		}
	}
	










	
}

