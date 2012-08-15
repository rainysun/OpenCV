#include "cv.h"
#include "highgui.h"
#include "stack.c"
#include <stdio.h>

void parseBGR(uchar* data, CvScalar* bg);


int main(int argc, char** argv){
	if(argc != 2){
		printf("1 argument only!\n");
		return 0;
	}

	CvScalar bg;
	IplImage* tmpl = NULL;
	Stack *stack   = (Stack*)malloc(sizeof(Stack));
	initStack(stack);
	if(!(tmpl = cvLoadImage(argv[1], 1))){
		printf("No such file!\n");
		return 0;
	}
	uchar* tdata   = (uchar*)tmpl->imageData;

	printf("parsing bckground color...\n");
	parseBGR(tdata, &bg);
	printf("background bgr: (%.f,%.f,%.f)\n",bg.val[0],bg.val[1],bg.val[2]);

	dieStack(stack);
	cvReleaseImage(&tmpl);
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
