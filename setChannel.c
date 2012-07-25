#include "highgui.h"
#include <stdio.h>
int main(){
	IplImage* img = cvCreateImage(cvSize(100,100),IPL_DEPTH_8U,1);
	CvScalar s;
	s=cvGet2D(img,50,50);
	printf("intensity=%f\n",s.val[0]);
	s.val[0]=255;
	cvSet2D(img,50,50,s);
	cvNamedWindow("E1",CV_WINDOW_AUTOSIZE);
	cvShowImage("E1",img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("E1");
}
