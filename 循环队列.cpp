#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct {
	int* base;
	int front;
	int rear;
}SqQueue;
int init(SqQueue &e)
{
	e.base=(int*)malloc(sizeof(int)*MAXSIZE);
	if(!e.base) return -1;
	e.front=e.rear=0;
	return 1;
}
int GetSqQueueSize(SqQueue &e)
{
	return (e.rear-e.front+MAXSIZE)%MAXSIZE;	
}
int EnQueue(SqQueue &e,int s)
{
	if((e.rear+1)%MAXSIZE==e.front)	return -1;
	e.base[e.rear]=s;
	e.rear=(e.rear+1)%MAXSIZE;
	return 1;
}
int DeQueue(SqQueue &e,int &n)
{
	if(e.front==e.rear) return -1;
	n=e.base[e.front];
	e.front=(e.front+1)%MAXSIZE;
	return 1;	
}
int GetQueueHead(SqQueue &e)
{
	if(e.front!=e.rear) return e.base[e.front];
}
int main()
{
	SqQueue e;
	init(e);
	int n;
	printf("please input the number which you want:\n");
	scanf("%d",&n);
	EnQueue(e,n);
	scanf("%d",&n);
	EnQueue(e,n);
	n=0;
	printf("%d",GetQueueHead(e));
//	DeQueue(e,n);
//	printf("%d\n",n);
//	DeQueue(e,n);
//	printf("%d\n",n);
	return 0;
}