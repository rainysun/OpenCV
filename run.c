#include "stack.c"

void fun(Stack* stack);
int main(){
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	initStack(stack);
	//CvPoint p = {111,255};
	CvPoint p1;
	fun(stack);
	fun(stack);
	fun(stack);
	//Push(stack, p);
	printf("Stack len: %d\n",stack->top-stack->base);
	Pop(stack, &p1);
	printf("P1.x: %d, P1.y: %d\n",p1.x,p1.y);
	dieStack(stack);
}
void fun(Stack* stack){
	CvPoint p = {1,1};
	Push(stack, p);
};

