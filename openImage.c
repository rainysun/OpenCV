#include "highgui.h"

int main(int argc, char** argv){
	IplImage* img = cvLoadImage(argv[1],CV_LOAD_IMAGE_COLOR);
	cvNamedWindow("win",CV_WINDOW_AUTOSIZE);
	cvShowImage("win",img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("win");
}
