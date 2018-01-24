#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <cstdio>
#include <opencv2/opencv.hpp>
#define N 16.0
#define S 31.0


using namespace cv;
using namespace std;
double MAD(IplImage * C, IplImage *R, int i, int j, int X0, int Y0, int X, int Y);

void Sequential(IplImage * C, IplImage *R,Mat ip2, int x, int y);

void TwoD_logarithm(IplImage * C, IplImage *R, Mat ip2, int x0, int y0);
void SNR();
int P = (S - 1) / 2;


int main() {

	char FReference[] = "i1.pgm"; 
	char FTarget[] = "i2.pgm"; 

	IplImage *image_R; 
	IplImage *image_C; 

	image_R = cvLoadImage(FReference, CV_LOAD_IMAGE_UNCHANGED); 
	image_C = cvLoadImage(FTarget, CV_LOAD_IMAGE_UNCHANGED); 


	Mat MatC = cvarrToMat(image_C);
	Mat MatR = cvarrToMat(image_R);

	Mat ip2_1 (MatR.rows, MatR.cols, CV_8U);
	Mat ip2_2 (MatR.rows, MatR.cols, CV_8U);

	int u, v;


	int y0 = N / 2; int x0 = N / 2; 

	for (x0 = N / 2; x0 < image_C->height; x0 = x0 + N) {
		
		for (y0 = N / 2; y0 < image_C->width; y0 = y0 + N) {
		
		    Sequential(image_C, image_R, ip2_1, x0, y0);

			TwoD_logarithm(image_C, image_R, ip2_2, x0, y0);
			
	}
	}


	namedWindow("Sequential", WINDOW_AUTOSIZE);
	imshow("Sequential", ip2_1);

	namedWindow("TwoD_logarithm", WINDOW_AUTOSIZE);
	imshow("TwoD_logarithm", ip2_2);


	


	imwrite("Sequential.pgm", ip2_1);
	imwrite("TwoD_logarithm.pgm", ip2_2);
	SNR();
	cvShowImage("Reference", image_R); 
	cvShowImage("Target", image_C);
	cvWaitKey(0);		


	cvDestroyWindow("Reference"); 
	cvDestroyWindow("Target"); 
	cvReleaseImage(&image_R); 
	cvReleaseImage(&image_C); 
	return EXIT_SUCCESS;
}

double MAD(IplImage * C, IplImage *R, int i, int j,int X0,int Y0,int X ,int Y ) {


	int x = X0 - (N / 2.0), y = Y0 - (N / 2.0);

	int xx = X - (N / 2.0),yy = Y - (N / 2.0);

	Mat matC = cvarrToMat(C);
	Mat matR = cvarrToMat(R);

	double a = 1 / (N * N);
	double mad = 0;
	double add = 0;
	
	for (int k = 0; k < N - 1; k++) {
		for (int l = 0; l < N - 1; l++) {

			int xC = xx + k + P;
			int yC = yy + l + P;

			if (xC >= matC.rows - 1) xC = matC.rows - 1;
			if (yC >= matC.cols - 1) yC = matC.cols - 1;
			

			double Cvalue =  matC.at<uchar>(xC, yC);

			int xR = x + i + k + P;
			int yR = y + j + l + P;

			if (xR >= matC.rows - 1) xR = matC.rows - 1;
			if( yR >= matC.cols - 1) yR = matC.cols - 1;
			

			double Rvalue = matR.at<uchar>(xR, yR);

			add += abs(Cvalue - Rvalue);

		}
	}

	mad = a * add;
	return mad;
}

void Sequential(IplImage * C, IplImage *R, Mat ip2, int x0, int y0) {

	int u = 0, v = 0;

	Mat matR = cvarrToMat(R);

	double cur_MAD = 0;
	double min_MAD = 10000.0;

	for (int i = -P; i <= P; i++) {
		for (int j = -P; j <= P; j++) {

			cur_MAD = MAD(C, R, i, j, x0, y0, x0, y0);

			if (cur_MAD < min_MAD) {

				min_MAD = cur_MAD;

				u = i, v = j;
			}
		}
	}
	int x = x0 - (N / 2.0), y = y0 - (N / 2.0);

	for (int q = 0; q < N; q++) {
		for (int p = 0; p < N; p++) {
			if (x >= ip2.rows - 1) x = ip2.rows - 1;

			if (y >= ip2.cols - 1) y = ip2.cols - 1;

			int n = x + u + P;

			int m = y + v + P;

			if (n >= ip2.rows - 1) n = ip2.rows - 1;

			if (m >= ip2.cols - 1) m = ip2.cols - 1;

			ip2.at<uchar>(x, y) = matR.at<uchar>(n, m);



			y++;
		}
		x++;
		y = y0 - (N / 2.0);
	}



}


void TwoD_logarithm(IplImage * C, IplImage *R, Mat ip2, int x0, int y0) {

	int u = 0, v = 0;
	int k = x0; int l = y0;

	Mat matR = cvarrToMat(R);

	double cur_MAD = 0;
	double min_MAD = 10000.0; 
	double p = P; 
	int a = p;

	while (a != 1) {

		a = ceil(p / 2.0);
		double min_MAD = 10000.0;
		double cur_MAD = 0;
		for (int i = -a; i <= a; i = i + a) {
			for (int j = -a; j <= a; j = j + a) {
				
				cur_MAD = MAD(C, R, i, j, x0, y0,k,l);
			   
					 
				if (cur_MAD < min_MAD) {

					min_MAD = cur_MAD;

					u = i, v = j;
					
				}

			}
		}
	
		x0 = x0 + u; y0 = y0 + v;
		p = p / 2.0;
	}


	
	int x = k - (N / 2.0), y = l - (N / 2.0);
    int yy = y = l - (N / 2.0);
	k = x0 - k; l = y0 - l;
	


	

	for (int q = 0; q <= N; q++) {
		for (int p = 0; p <= N; p++) {
		
			if (x >= ip2.rows - 1) x = ip2.rows - 1;

			if (y >= ip2.cols - 1) y = ip2.cols - 1;
			
			if (x <= 0) x = 0;
			if (y <= 0) y = 0;

			int n = x + k + P;

			int m = y + l + P;

			if (n >= ip2.rows - 1) n = ip2.rows - 1;

			if (m >= ip2.cols - 1) m = ip2.cols - 1;
	

			ip2.at<uchar>(x, y) = matR.at<uchar>(n, m);
			y++;
		}
		x++;
		y = yy;
	}

	
	
}


void SNR() {

	IplImage *src1 = cvLoadImage("Sequential.pgm");
	IplImage *src2 = cvLoadImage("TwoD_logarithm.pgm");
	IplImage *target = cvLoadImage("i2.pgm");

	long long int sigma1 = 0;
	long long int squre1 = 0;
    long long int sigma2 = 0;
	long long int squre2 = 0;
	double SNR1 = 0.0;
    double SNR2 = 0.0;
	int frameSize = src1->height*src1->width * 3;
	int blue1 = 0, blue2 = 0, blue3 = 0;
	int green1 = 0, green2 = 0, green3 = 0;
	int red1 = 0, red2 = 0, red3 = 0;


	for (int i = 0; i<target->height; i++) {
		for (int j = 0; j<target->widthStep; j = j + 3) {

			blue1 = (int)(uchar)target->imageData[i*target->widthStep + j];
			green1 = (int)(uchar)target->imageData[i*target->widthStep + j + 1];
			red1 = (int)(uchar)target->imageData[i*target->widthStep + j + 2];

			blue2 = (int)(uchar)src1->imageData[i*src1->widthStep + j];
			green2 = (int)(uchar)src1->imageData[i*src1->widthStep + j + 1];
			red2 = (int)(uchar)src1->imageData[i*src1->widthStep + j + 2];

			blue3 = (int)(uchar)src2->imageData[i*src2->widthStep + j];
			green3 = (int)(uchar)src2->imageData[i*src2->widthStep + j + 1];
			red3 = (int)(uchar)src2->imageData[i*src2->widthStep + j + 2];



			sigma1 += (blue1 - blue2)*(blue1 - blue2) +(green1 - green2)*(green1 - green2) +(red1 - red2)*(red1 - red2);

			squre1 += blue2*blue2 + green2*green2 + red2*red2;


			sigma2 += (blue1 - blue3)*(blue1 - blue3) + (green1 - green3)*(green1 - green3) + (red1 - red3)*(red1 - red3);

			squre2 += blue3*blue3 + green3*green3 + red3*red3;
		}
	}



	
	SNR1 = 10 * log10(squre1 / sigma1);
	SNR2 = 10 * log10(squre2 / sigma2);

	cout << "SNR1: " << setprecision(3) << SNR1 << endl;;
	cout << "SNR2: " << setprecision(3) << SNR2 << endl;;




}