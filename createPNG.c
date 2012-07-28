#include "highgui.h"
#include <stdio.h>

int main(int argc, char** argv){
	int width,height;
	char* fileName;
	width = (argc > 1 && argv[1]) ? (int)argv[1] : 100;
	height= (argc > 2 && argv[2]) ? (int)argv[2] : 100;
	fileName = (argc > 3) ? argv[3] : "Default.jpg";
	IplImage* pngImg = cvCreateImage(cvSize(width,height),IPL_DEPTH_8U,3);
	uchar* data    = (uchar *)pngImg->imageData;
	int i,j;
	int step = pngImg->widthStep;
	printf("Image Size: %d*%d\n",pngImg->width,pngImg->height);
	printf("Step: %d\n", step);
	for(i=0;i<pngImg->height;i++){
		for(j=0;j<pngImg->width;j++){
			data[i*step+j*3] = 28;
			data[i*step+j*3+1] = 128;
			data[i*step+j*3+2] = 28;
			//data[i*step+j*3+3] = 255;
		}
	}
	for(i=0;i<100;i++){
		printf("%d ",data[i]);
	}
	printf("\n");
	cvRectangle(pngImg, cvPoint(40,40), cvPoint(60,60),cvScalar(0,0,255,1),1,8,0);

	if(!cvSaveImage(fileName,pngImg,0)){
		printf("Could not save: %s\n", fileName);
	}
	cvReleaseImage(&pngImg);
}
