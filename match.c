#include "highgui.h"
#include "cv.h"
#include <stdio.h>

int main(int argc, char** argv){
	int i;
	if(argc != 4){
		printf("Error 1: 3 arguments expected, %d given.\n",argc-1);
		return 0;
	}
	IplImage* source = cvLoadImage(argv[1],CV_LOAD_IMAGE_COLOR);
	IplImage* tmpl   = cvLoadImage(argv[2],CV_LOAD_IMAGE_COLOR);
	//IplImage* replace= cvLoadImage(argv[3],CV_LOAD_IMAGE_COLOR);
	int ww = source->width - tmpl->width + 1;
	int hh = source->height - tmpl->height + 1;
	IplImage *result = cvCreateImage(cvSize(ww,hh),IPL_DEPTH_32F, 1);//source->nChannels);
	//IplImage* result = NULL;

	cvMatchTemplate(source, tmpl, result, CV_TM_SQDIFF);

	CvPoint minLoc;
	CvPoint maxLoc;
	//Point matchLoc;
	double minVal;
	double maxVal;
	//CvMat*  mat;
	cvMinMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, 0);
	cvRectangle(source, minLoc, cvPoint(minLoc.x+tmpl->width,minLoc.y+tmpl->height),cvScalar(0,0,255,1),1,8,0);

	cvNamedWindow("match",CV_WINDOW_AUTOSIZE);
	cvShowImage("match",source);
	cvWaitKey(0);
	cvReleaseImage(&source);
	cvReleaseImage(&tmpl);
	cvReleaseImage(&result);
	cvDestroyWindow("match");
}
