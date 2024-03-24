#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED
#include <stdlib.h>
//��ʽ���нṹ
typedef struct node
{
    void *data;//������ָ��
    struct node *next;//ָ��ǰ������һ���
} node,*QueuePtr;
typedef struct Lqueue
{
    QueuePtr head;//��ͷ
    QueuePtr tail;//��β
    int length;//���г���
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


