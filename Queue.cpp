#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define dim 8
#define dim 8
#define plotvaX 0
#define plotvaY 0
#define geraltX 7
#define geraltY 7

typedef struct Node
{
	int x;
	struct Node* next;
}NODE;

typedef struct Queue
{
	NODE* front;
	NODE* rear;
}QUEUE;

int IsQEmpty(QUEUE* queue) {
	if (queue->front==NULL)    return(1);
	else  return(0);
}
void Enqueue(QUEUE* queue, int x)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->x = x;
	newNode->next = NULL;
	if (IsQEmpty(queue))
	{
		queue->front = newNode;
		queue->rear = newNode;
	}
	else 
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
}
void Dequeue(QUEUE* queue)
{
	NODE* p = queue->front;
	queue->front = queue->front->next;
	free(p);
}
void PrintQueue(const QUEUE* queue)
{
	NODE* p = queue->front;
	while (p != NULL) {
		printf(" %i", p->x);
		p = p->next;
	}
}
//-----------------------------------------------------------------------------

int main()
{
	int i = 0;
	QUEUE queue = { NULL,NULL };
	QUEUE* p_queue = &queue;
	return 0;
}