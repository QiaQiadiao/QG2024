#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#include <stdlib.h>
//链式队列结构
typedef struct node
{
    void *data;//数据域指针
    struct node *next;//指向当前结点的下一结点
} node,*QueuePtr;
typedef struct Lqueue
{
    QueuePtr head;//队头
    QueuePtr tail;//队尾
    int length;//队列长度
} LinkQueue;
typedef enum
{
    FALSE=0, TRUE=1
} Status;
void InitLQueue(LinkQueue *Q)
{
	Q->head = NULL;
	Q->tail = NULL;
	Q->length  =0;	
} 

Status IsEmptyLQueue(LinkQueue *Q)
{
	if (Q->length == 0)
		return TRUE;
	else
		return FALSE;
}

void DestroyLQueue(LinkQueue *Q)
{
	if (IsEmptyLQueue(Q))
		return;
	QueuePtr p ;
	while(Q->length!=1)
	{
		p = Q->head;
		Q->head = Q->head->next;
		free(p);
		Q->length--; 
	}
	p = Q->head;
	Q->head = NULL;
	Q->tail = NULL;
	free(p);
	Q->length = 0;
}

//Status GetHeadLQueue(LinkQueue *Q, int choice)
//{
//	if(IsEmptyLQueue(Q))
//		return FALSE;
//	else 
//	{
//		switch (choice)
//		{
//			case 1:
//				(int*)(Q->head);
//				printf("%d",*(Q->head->data));
//				break;
//			case 2:
//				printf("%f",*(Q->head->data));
//				break;
//			case 3;
//				printf("%c",*(Q->head->data));
//				break;
//		}
//		return TRUE;
//	}
//}

int LengthLQueue(LinkQueue *Q)
{
	return Q->length;
}

Status EnLQueue(LinkQueue *Q, void *data)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(node));
	p->data = data;
	p->next = NULL;
	if(IsEmptyLQueue(Q))
	{
		Q->head = p;
		Q->tail = p;
	}else{
		Q->tail->next = p;
		Q->tail = p;
	}
	Q->length++;
}

Status DeLQueue(LinkQueue *Q)
{
	if(IsEmptyLQueue(Q))
	{
		return FALSE;
	}else{
		QueuePtr p = Q->head;
		Q->head = Q->head->next;
		free(p);
		Q->length--;
		return TRUE;
	}
}

//void LPrint(LinkQueue *Q,int choice)
//{
//	QueuePtr p = Q->head;
//	switch (choice)
//	{
//		case 1:
//			while(p!=NULL)
//			{
//				printf("%d ",*(p->data));
//				p = p->next;
//			}
//		case 2:
//			while(p!=NULL)
//			{
//				printf("%f ",*(p->data));
//				p = p->next;
//			}
//		case 3;
//			while(p!=NULL)
//			{
//				printf("%c ",*(p->data));
//				p = p->next;
//			}
//	}
//	
//}


#endif // LQUEUE_H_INCLUDED


