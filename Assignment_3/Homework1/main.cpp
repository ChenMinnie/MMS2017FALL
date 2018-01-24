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

void TwoD_logarithm(IplImage * C, IplImage *R, Mat ip2, int x0, int y0);

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

	Mat ip2 (MatR.rows, MatR.cols, CV_8U);

	int u, v;


	int y0 = N / 2; int x0 = N / 2; 

	for (x0 = N / 2; x0 < image_C->height; x0 = x0 + N) {
		
		for (y0 = N / 2; y0 < image_C->width; y0 = y0 + N) {
		//	printf("%d,%d\n", x0, y0);
		//    Sequential(image_C, image_R, ip2, x0, y0);
			//TwoD_logarithm(image_C, image_R, ip2, 8, 8);
			TwoD_logarithm(image_C, image_R, ip2, x0, y0);
			printf("\n");
		}
	}
	

	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", ip2);
	imwrite("output.jpg", ip2);
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
//	printf("%d,%d\n", X0, Y0);

	int x = X0 - (N / 2.0), y = Y0 - (N / 2.0);

	Mat matC = cvarrToMat(C);
	Mat matR = cvarrToMat(R);

	double a = 1 / (N * N);
	double mad = 0;
	double add = 0;

	for (int k = 0; k < N - 1; k++) {
		for (int l = 0; l < N - 1; l++) {

			int xC = x + k + P;
			int yC = y + l + P;

			if (xC >= matC.rows - 1) xC = matC.rows - 1;
			if (yC >= matC.cols - 1) yC = matC.cols - 1;
			if (xC <=0) xC = 0;
			if (yC <=0) yC = 0;

			double Cvalue =  matC.at<uchar>(xC, yC);

			int xR = x + i + k + P;
			int yR = y + j + l + P;

			if (xR >= matC.rows - 1) xR = matC.rows - 1;
			if( yR >= matC.cols - 1) yR = matC.cols - 1;
			if (xR <= 0) xR = 0;
			if (yR <= 0) yR = 0;

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

			cur_MAD = MAD(C, R, i, j, x0, y0);

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
	while (a > 1) {
		a = ceil(p / 2.0);
	//	printf("%d\n",a);
		for (int i = -a; i <= a; i = i + a) {
			for (int j = -a; j <= a; j = j + a) {
				//	printf("%d,%d\n", i, j);
				
				cur_MAD = MAD(C, R, i, j, x0, y0);

					//cur_MAD = MAD(C, R, i, j, u, v);

				if (cur_MAD < min_MAD) {

					min_MAD = cur_MAD;

					u = i, v = j;
				}

			}
		}

		x0 = x0 + u; y0 = y0 + v;
		//printf("%d,%d\n", u, v);
		//printf("---%d,%d\n", x0, y0);
		p = p / 2.0;
	}

	int x = k - (N / 2.0), y = l - (N / 2.0);

	k = x0 - k; l = y0 - l;
	//printf("%d,%d\n", k, l);


	printf("%d,%d\n", x, y);

	for (int q = 0; q < N; q++) {
		for (int p = 0; p < N; p++) {
			if (x >= ip2.rows - 1) x = ip2.rows - 1;

			if (y >= ip2.cols - 1) y = ip2.cols - 1;
			
			if (x <= 0) x = 0;
			if (y <= 0) y = 0;

			int n = x + k + P;

			int m = y + l + P;

			if (n >= ip2.rows - 1) n = ip2.rows - 1;

			if (m >= ip2.cols - 1) m = ip2.cols - 1;
			if (n <= 0) n = 0;
			if (m <= 0) m = 0;
			ip2.at<uchar>(x, y) = matR.at<uchar>(n, m);



			y++;
		}
		x++;
		y = y0 - (N / 2.0);
	}

	
	
}