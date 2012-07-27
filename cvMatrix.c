#include "cv.h"
#include <stdio.h>
int main(){
	float Array[]={1,2,3,4,5,6,7,8,9,10,11,12};
	CvMat Matrix1;
	Matrix1=cvMat(3,4,CV_32FC1,Array);
	printf("The type is : %d\n",Matrix1.type);
	//printf("The depth is : %d\n",cvCvToIplDepth(Matrix1.type));
	printf("The step is : %d\n",Matrix1.step);
	printf("The rows is : %d\n",Matrix1.rows);
	printf("The cols is : %d\n",Matrix1.cols);
}
