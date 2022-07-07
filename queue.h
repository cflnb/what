#ifndef  _QUEUE_H
#define  _QUEUE_H
#define MAX 1000
#include <stdio.h>
#include <stdlib.h>

typedef  int Item;
typedef struct SqQueue
{
	Item d[MAX];
	int front, rear;
}SqQueue;

void InitQueue(SqQueue** q)
{
	*q = (SqQueue*)malloc(sizeof(SqQueue));
	(*q)->front = (*q)->rear = 0;
}

void DestoryQueue(SqQueue* p)
{
	free(p);
}

int QueueEmpty(SqQueue* p)
{
	return p->front == p->rear;
}

Item enQueue(SqQueue* p, Item k)
{
	if ((p->rear+1)%MAX== p->front)
	{
		return 0;
	}
	else
	{
		p->rear = (p->rear + 1) % MAX;
		p->d[p->rear] = k;
		return 1;
	}
}
Item deQueue(SqQueue* p, Item* k)
{
	if (p->front == p->rear)
	{
		return 0;
	}
	else
	{
		p->front = ((p->front) + 1)%MAX;
		*k = p->d[p->front];
		return 1;
	}
}
#endif
