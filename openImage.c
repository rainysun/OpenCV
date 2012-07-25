#include "highgui.h"

int main(int argc, char** argv){
	IplImage* img = cvLoadImage(argv[1],CV_LOAD_IMAGE_COLOR);
	cvNamedWindow("E1",CV_WINDOW_AUTOSIZE);
	cvShowImage("E1",img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("E1");
}
