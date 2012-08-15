#include "wpStack.c"

typedef struct{
	CvPoint pos;
	double sdd[2];
}sddPos;
int main(int argc, char** argv){
	IplImage* source = cvLoadImage(argv[1],1);
	IplImage* tmpl   = cvLoadImage(argv[2],1);
	IplImage subtmpl;

	CvPoint minLoc;
	CvPoint maxLoc;
	double minVal;
	double maxVal;

	int i,j,k;
	int sw,sh,tw,th;
	int sdb,sdg,sdr;
	int wpx,wpy;
	int sstep,tstep;
	double sdd;
	sddPos sp = {{0,0},{0.0,0.0}};
	sw = source->width;
	sh = source->height;
	tw = tmpl->width;
	th = tmpl->height;
	sstep = source->widthStep;
	tstep = tmpl->widthStep;
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	initStack(stack);
	wpStack(tmpl, stack);
	subTmpl(tmpl, *stack, &subtmpl);
	IplImage *result = cvCreateImage(cvSize(source->width-tmpl->width+1,source->height-tmpl->height+1),IPL_DEPTH_32F, 1);

	printf("Matching subtmpl with source...\n");

	printf("tmpl->whidth: %d, tmpl->height: %d\n",tmpl->width,tmpl->height);
	cvNamedWindow("subtmpl", CV_WINDOW_AUTOSIZE);
	cvShowImage("subtmpl", tmpl);
	cvWaitKey(0);
	cvDestroyWindow("subtmpl");

	//cvMatchTemplate(source, tmpl, result, CV_TM_SQDIFF);
	/*
	cvMinMaxLoc(&result, &minVal, &maxVal, &minLoc, &maxLoc, 0);
	cvRectangle(source, minLoc, cvPoint(minLoc.x+tmpl->width,minLoc.y+tmpl->height),cvScalar(0,0,255,1),1,8,0);
	*/
	

	//uchar* sdata = (uchar*)source->imageData;
	//uchar* tdata = (uchar*)tmpl->imageData;

	//printf("sh-th: %d,sw-tw: %d\n",sh-th,sw-tw);
	//for(i=0;i<sh-th;i++){
	//	for(j=0;j<sw-tw;j++){
	//		sdd = 0;
	//		for(k=20;k<30;k++){
	//			wpx = (stack->base+k)->x;
	//			wpy = (stack->base+k)->y;
	//			sdb = pow(sdata[(i+wpy)*sstep+(j+wpx)*3]-tdata[wpy*tstep+wpx*3],2);
	//			//sdg = pow(sdata[(i+wpy)*sstep+(j+wpx)*3+1]-tdata[wpy*tstep+wpx*3+1],2);
	//			//sdr = pow(sdata[(i+wpy)*sstep+(j+wpx)*3+2]-tdata[wpy*tstep+wpx*3+2],2);
	//			sdd += (sdb);//+sdg+sdr);
	//		}
	//		if(i < 1 && j < 1){
	//			sp.pos = cvPoint(j,i);
	//			sp.sdd[0] = sdd;
	//		}
	//		if(sdd < sp.sdd[0]){
	//			sp.sdd[0] = sdd;
	//			sp.pos = cvPoint(j,i);
	//		}
	//		printf("sdd: %.f\n",sdd);
	//	}
	//}
	

	/*
	printf("sp.pos = [%d, %d], min sdd = %.f. \n", sp.pos.x, sp.pos.y, sp.sdd[0]);
	printf("Stack len: %d, Stack size: %d.\n",stack->top-stack->base, stack->size);
	cvRectangle(source, sp.pos, cvPoint(sp.pos.x+tw,sp.pos.y+th),cvScalar(0,0,255,1),1,8,0);

	cvNamedWindow("result", CV_WINDOW_AUTOSIZE);
	cvShowImage("result", source);
	cvWaitKey(0);
	cvDestroyWindow("result");
	*/

	dieStack(stack);
	cvReleaseImage(&result);
	cvResetImageROI(tmpl);
	cvReleaseImage(&source);
	cvReleaseImage(&tmpl);
}
