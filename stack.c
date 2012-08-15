#include "highgui.h"
#include "cv.h"
#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 10
#define INCREMENT 1

/*
typedef struct{
	int x;
	int y;
}Point;
*/
typedef struct{
	CvPoint *base;
	CvPoint *top;
	int size;
}Stack;
void initStack(Stack* S){
	S->base = (CvPoint*)malloc(STACK_INIT_SIZE*sizeof(CvPoint));
	if(!S->base)exit(0);
	S->top  = S->base;
	S->size = STACK_INIT_SIZE;
}
void Push(Stack* S, CvPoint p){
	if(S->top - S->base > S->size)
	{
		S->base = (CvPoint*)realloc(S->base,
				(S->size + INCREMENT)*sizeof(CvPoint)
				);
		if(!S->base){
			printf("Failed to realloc memory!\n");
			exit(0);
		}
		S->top = S->base + S->size;
		S->size += INCREMENT;
	}
	*S->top++ = p;
}
void Pop(Stack* S, CvPoint* p){
	if(S->top == S->base){
		printf("Stack Empty!\n");
		exit(0);
	}
	*p = *--S->top;
}
void dieStack(Stack* S){
	//S->base = S->top = NULL;
	//free(S->top);
	free(S->base);
	free(S);
	//free(&(S->stacksize));
}
int main(){
	Stack* S = (Stack*)malloc(sizeof(Stack));
	initStack(S);
	CvPoint p1 = {1,2};
	CvPoint p2 = {3,4};
	CvPoint p3;
	Push(S,p1);
	Push(S,p2);
	printf("S->base->x: %d, S->top->x: %d, S->size: %d\n",S->base->x,(S->top-1)->x,S->size);
	printf("Stack len: %d\n",S->top-S->base);
	Pop(S,&p3);
	printf("S->base->x: %d, S->top->x: %d, S->size: %d\n",S->base->x,(S->top-1)->x,S->size);
	printf("Stack len: %d\n",S->top-S->base);
	printf("p3.x: %d, S->top->x: %d, S->size: %d\n",p3.x,(S->top-1)->x,S->size);
	dieStack(S);
}
