#include "cv.h"
#include <stdio.h>

int main(int argc, char** argv){
	IplImage* img;
	CvMat* imgMat;
	img = cvLoadImage(argv[1],-1);
	if(!img){
		printf("Failed to open image %s\n",argv[1]);
	}
	printf("Image %s opened.\n",argv[1]);
	if(img->depth > 8){
		printf("Image depth out of range.\n");
		return 0;
	}
	int type;
	if(img->nChannels == 3){
		type = CV_8UC3;
	}else if(img->nChannels == 4){
		type = CV_8UC4;
	}
	imgMat = cvCreateMat(img->width,img->height,type);
	cvReleaseMat(&imgMat);
	printf("imgMat released.\n");
	cvReleaseImage(&img);
	printf("Image %s released.\n",argv[1]);
}
