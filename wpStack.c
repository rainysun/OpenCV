//#include "highgui.h"
//#include "cv.h"
#include "stack.c"
#include <stdio.h>
#include <math.h>

void wpStack(IplImage* img, Stack* stack);
void backgroundMask(IplImage* img, CvScalar bg, Stack* stack);
void parseBGR(uchar* data, CvScalar* bg);
int	 rangeBGR(CvScalar source, CvScalar comp, int pixels);
void subTmpl(IplImage* tmpl, const Stack stack, IplImage* subtmpl);


void wpStack(IplImage* img, Stack* stack){
	CvScalar bg;
	initStack(stack);

	uchar* data = (uchar*)img->imageData;
	printf("Parsing background color to BGR...\n");
	parseBGR(data,&bg);
	printf("Background color BGR: [%.f,%.f,%.f]\n",bg.val[0],bg.val[1],bg.val[2]);
	backgroundMask(img, bg, stack);
	printf("Background masked into stack!\n");
}
void parseBGR(uchar* data, CvScalar* bg){
	int i;
	double b,g,r;
	b=g=r=0;
	for(i=0;i<5;i++){
		b += data[i*3];
		g += data[i*3+1];
		r += data[i*3+2];
	}
	*bg = cvScalar(b/5., g/5., r/5., 0);
}
int rangeBGR(CvScalar source, CvScalar comp, int pixels){
	int i;
	int flag = 1;
	for(i = 0; i < 3; i++){
		if(fabs(source.val[i] - comp.val[i]) > pixels){
			flag = 0;
			break;
		}
	}
	return flag;
}
void backgroundMask(IplImage* img, CvScalar bg, Stack* stack){
	int i,j;
	int step,width,height,channels;
	int b,g,r;
	CvScalar tmp;

	step= img->widthStep;
	width=img->width;
	height=img->height;
	channels=img->nChannels;
	uchar* odata = (uchar*)img->imageData;
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			b = odata[i*step+j*channels];
			g = odata[i*step+j*channels+1];
			r = odata[i*step+j*channels+2];
			tmp = cvScalar(b,g,r,0);
			if(!rangeBGR(bg, tmp, 5))
				Push(stack, cvPoint(j,i));
		}
	}
}
void subTmpl(IplImage* tmpl, const Stack stack, IplImage* subtmpl){
	CvPoint min,max;
	int i;

	min = cvPoint(stack.base->x, stack.base->y);
	max = cvPoint((stack.top-1)->x, (stack.top-1)->y);
	for(i=0;i<stack.top-stack.base;i++){
		if((stack.base+i)->x < min.x)
			min.x = (stack.base+i)->x;
		if((stack.base+i)->x > max.x)
			max.x = (stack.base+i)->x;
	}
	printf("tmplate content size: (%d, %d)~(%d, %d)\n", min.x, min.y, max.x, max.y);
	cvSetImageROI(tmpl, cvRect(min.x+5, min.y+5, max.x-min.x-5, max.y-min.y-5));
	cvSaveImage("../img/subtmpl/wp-001.jpg",tmpl,0);
	//cvRectangle(tmpl, min, max, cvScalar(0,0,255,1),1,8,0);

	//subtmpl = cvCreateImage(cvSize(max.x-min.x, max.y-min.y),IPL_DEPTH_8U,3);
	//subtmpl = tmpl;
	printf("Set subtmpl.\n");
	/*
	cvNamedWindow("subtmpl", CV_WINDOW_AUTOSIZE);
	cvShowImage("subtmpl", tmpl);
	cvWaitKey(0);
	cvDestroyWindow("subtmpl");
	//cvResetImageROI(tmpl);
	*/
}
