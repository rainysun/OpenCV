#include "highgui.h"
#include <stdio.h>

void main(int argc, char** argv){
	IplImage* img = cvLoadImage(argv[1],CV_LOAD_IMAGE_COLOR);
	printf("Image Size: %d*%d\n", img->width, img->height);
	cvReleaseImage(&img);
}
