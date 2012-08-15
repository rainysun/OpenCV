#include "highgui.h"
#include "cv.h"
#include <stdio.h>

void parseTmpl(CvPoint** tmplMat);
int main(int argc, char** argv){
	IplImage* source;
	IplImage* tmpl;
	IplImage* replace;
	//CvPoint region,minMatch;
	//CvRect ROIrect;
	//CvMat tmplMask;
	//int movex,movey;
	//int regionx,regiony;
	//int deta;//diff between source and tmpl
	CvPoint **tmplMat = 0;
	//source = cvLoadImage(argv[1],CV_LOAD_IMAGE_COLOR);
	//tmpl   = cvLoadImage(argv[2],CV_LOAD_IMAGE_COLOR);
	//uchar* sdata = (uchar* )source->data;
	//uchar* tdata = (uchar* )tmpl->data;
	//region = cvPoint(source->width-tmpl->width, source->height-tmpl->height);
	//tmplMask = cvCreateMat(tmpl->height, tmpl->width, CV_8UC1);
	parseTmpl(tmplMat);
	printf("%d\n",(*tmplMat)->y);
	//printf("%d\n",tmplMat[1].x);
	//for(movey=0;movey<region->y;movey++){
	//	for(movex=0;movex<region->x;movex++){
	//		//ROIrect = cvRect(movex,movey,tmpl->width,tmpl->height);
	//		for(regiony=0;regiony<tmpl->height;regiony++){
	//			for(regionx=0;region<tmpl->width;regionx++){
	//				CvScalar sp = cvGet2D(source, regiony+movey, regionx+movex);
	//				CvScalar tp = cvGet2D(tmpl, regiony+movey, regionx+movex);
	//				//cvmSet(tmplMask, regionx, regiony, deta);
	//				//tdata[]
	//			}
	//		}
	//		//cvSetImageROI(source, ROIrect);
	//	}
	//}
	//cvReleaseImage(&source);
	//cvReleaseImage(&tmpl);
	//cvReleaseImage(&replace);
}

void parseTmpl(CvPoint** tmplMat){
	CvPoint pixel;
	pixel = cvPoint(1,1);
	*tmplMat = &pixel;
//	
//	int i;
//	//printf("%x\n",**tmplMat);
//	for(i=0;i<10;i++){
//		tmplMat[i] = cvPoint(i,i);
//	}
}
