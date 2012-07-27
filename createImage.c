#include "highgui.h"
#include <stdio.h>

int main(int argc, char** argv){
	char* text = "rainy";
	int width  = 51;//(int)argv[2];
	int height = 92;//(int)argv[1];
	char* fp = "replace.jpg";
	CvFont font;
	IplImage* img = cvCreateImage(cvSize(height,width),IPL_DEPTH_8U,1);
	double hScale=1.0;
	double vScale=1.0;
	int    lineWidth=1;
	cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX|CV_FONT_ITALIC, hScale,vScale,0,1,lineWidth);
	cvPutText (img,text,cvPoint((int)(width/2),(int)(height/2)), &font, cvScalar(255,255,0,1));

	cvNamedWindow("E1",CV_WINDOW_AUTOSIZE);
	cvShowImage("E1",img);
	cvWaitKey(0);
	cvSaveImage(fp,img,0);
	cvReleaseImage(&img);
	cvDestroyWindow("E1");
}
