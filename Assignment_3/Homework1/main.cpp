#include <iostream>
#include <cv.h>
#include <highgui.h>

#define N 16.0
#define S 31.0


using namespace cv;
using namespace std;
double MAD(IplImage * C, IplImage *R, int i, int j);
void Sequential(IplImage * C, IplImage *R);
int P = (S - 1) / 2;
int X0 = S / 2;
int Y0 = S / 2;

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
	Sequential(image_C, image_R);
	cvShowImage("Reference", image_R); 
	cvShowImage("Target", image_C);
	cvWaitKey(0);		
	cvDestroyWindow("Reference"); 
	cvDestroyWindow("Target"); 
	cvReleaseImage(&image_R); 
	cvReleaseImage(&image_C); 
	return EXIT_SUCCESS;
}

double MAD(IplImage * C, IplImage *R, int i, int j) {

	int x = X0 - (N / 2.0), y = Y0 - (N / 2.0);

	Mat matC = cvarrToMat(C);
	Mat matR = cvarrToMat(R);
	//Mat mat(C, 0);
	double a = 1 / (N * N);
	double mad = 0;
	double add = 0;

	for (int k = 0; k < N - 1; k++) {
		for (int l = 0; l < N - 1; l++) {


			double Cvalue = matC.at<uchar>(x + k + P, y + l + P);

			int n = x + i + k + P;
			int m = y + j + l + P;

			double Rvalue = matR.at<uchar>(n, m);

			add += abs(Cvalue - Rvalue);
		}
	}

	mad = a * add;
	return mad;
}

void Sequential(IplImage * C, IplImage *R) {

	int u, v = 0;

	//Mat matC = cvarrToMat(C);
	//Mat matR = cvarrToMat(R);

	double cur_MAD = 0;
	double min_MAD = 10000.0;

	for (int i = -P; i <= P; i++) {
		for (int j = -P; j <= P; j++) {

			cur_MAD = MAD(C, R, i, j);

			//printf("%f\n", cur_MAD);


			if (cur_MAD < min_MAD) {

				min_MAD = cur_MAD; //printf("%f\n", min_MAD);
				u = i; v = j;

			}
		}
	}
	printf("%d %d", u, v);
}

