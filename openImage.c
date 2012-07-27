#include "highgui.h"

int main(int argc, char** argv){
	IplImage* img = cvLoadImage(argv[1],CV_LOAD_IMAGE_COLOR);
<<<<<<< HEAD
	cvNamedWindow("E1",CV_WINDOW_AUTOSIZE);
	cvShowImage("E1",img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("E1");
=======
	cvNamedWindow("win",CV_WINDOW_AUTOSIZE);
	cvShowImage("win",img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("win");
>>>>>>> 6f6c25d4948c1934d3e3bd21b08b86bd8efda252
}
