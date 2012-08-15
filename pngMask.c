#include "highgui.h"
#include "cv.h"
#include <stdio.h>
int mask(IplImage* img);
void main(int argc, char** argv){
	IplImage* img = cvLoadImage(argv[1],1);
	mask(img);
	cvReleaseImage(&img);
}

int mask(IplImage* img){
	//IplImage* img = NULL;
	int i,j;
	int step,width,height,channels;
	int blue,green,red;
	//img = cvLoadImage(argv[1],1);
	step= img->widthStep;
	width=img->width;
	height=img->height;
	channels=img->nChannels;
	int mask[height][width];
	uchar* odata = (uchar*)img->imageData;
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			blue = odata[i*step+j*channels];
			green= odata[i*step+j*channels+1];
			red  = odata[i*step+j*channels+2];
			if(blue <= 5 && green >=250 && red <=5)
				mask[i][j] = 0;
			else
				mask[i][j] = 1;
			printf("%d",mask[i][j]);
		}
		printf("\n");
	}
}
