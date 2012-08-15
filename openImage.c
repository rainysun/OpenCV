#include "highgui.h"

int main(int argc, char** argv){
	IplImage* img = cvLoadImage(argv[1],1);
	int i;
	uchar* data = (uchar* )img->imageData;
	for(i=0;i<100;i++)
		printf("%d ",data[i]);
	cvNamedWindow("win",CV_WINDOW_AUTOSIZE);
	cvShowImage("win",img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("win");
}
