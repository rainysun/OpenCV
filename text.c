#include "highgui.h"

int main(int argc, char** argv){
	IplImage* img = cvLoadImage(argv[1],CV_LOAD_IMAGE_COLOR);
	CvFont font;
	double hScale=1.0;
	double vScale=1.0;
	int    lineWidth=8;
	cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX|CV_FONT_ITALIC, hScale,vScale,0,1,lineWidth);
	cvPutText (img,"Rainy",cvPoint(200,200), &font, cvScalar(255,255,0,1));
	cvNamedWindow("E1",CV_WINDOW_AUTOSIZE);
	cvShowImage("E1",img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("E1");
}
