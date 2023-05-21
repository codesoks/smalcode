#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1010
typedef int SElemType;
typedef int Status;
typedef struct {
	int* base;
	int* top;
	int stacksize;
}SqStack;
int initSqStack(SqStack &e)
{
	e.base=(int*)malloc(sizeof(int)*MAXSIZE);
	if(!e.base) return -1;
	e.top=e.base;
	e.stacksize=MAXSIZE;
}
int Push(SqStack &e,int s)
{
	if(e.top-e.base==e.stacksize) return -1;
	*e.top++=s;
	return 1;
}
int pop(SqStack &e,SElemType &s)
{
	if(e.base==e.top) return -1;
	s=*--e.top;
	return 1;
}
Status GetTop(SqStack &e)
{
	if(e.top!=e.base) return *(e.top-1);
}
int Print(SqStack &e)
{
	if(e.base== e.top)	return -1;
	int *a=e.top;
	while(a!=e.base) printf("%d ",*--a);
	printf("\n");
	return 1;
}
int main()
{
	SqStack e;
	initSqStack(e);
	int n;
	printf("Please input number which you want:\n");
	scanf("%d",&n);
//	printf("-----");
	Push(e,n);
	scanf("%d",&n);
	Push(e,n);
	scanf("%d",&n);
	Push(e,n);
	scanf("%d",&n);
	Push(e,n);
	int u=Print(e);	
	printf("u:%d ",u);
	return 0;
}