#include "cv.h"
#include "highgui.h"
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
	printf("Size: %d*%d\n",img->width,img->height);
	printf("Channels: %d\n",img->nChannels);
	printf("Step: %d\n",img->widthStep);
	if(img->nChannels == 3){
		type = CV_8UC3;
	}else if(img->nChannels == 4){
		type = CV_8UC4;
	}
	imgMat = cvCreateMat(img->width,img->height,type);
	int i,j;
	CvScalar s;
	uchar* data = (uchar* )img->imageData;
	for(i=0;i<img->height;i++){
		for(j=0;j<img->width;j++){
			s=cvGet2D(img,i,j);
			//if(s.val[0] != 255){
			printf("[%.0f %.0f %.0f] ",s.val[0],s.val[1],s.val[2]);
			//}
		}
		printf("\n");
	}
	//for(i=0;i<100;i++){
	//	printf("%d ",data[i]);
	//}
	printf("\n");
	cvReleaseMat(&imgMat);
	printf("imgMat released.\n");
	cvReleaseImage(&img);
	printf("Image %s released.\n",argv[1]);
}
