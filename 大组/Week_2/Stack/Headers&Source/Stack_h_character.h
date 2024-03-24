#ifndef Stack_h_character 
#define Stack_h_character
#include <stdlib.h>

typedef enum Status 
{
    ERROR = 0, 
	SUCCESS = 1
} Status;
typedef struct StackNode
{
	char data;
	struct StackNode*next;
}StackNode,*LinkStackPtr;//�൱��StackNode* 
typedef struct LinkStack
{
	LinkStackPtr top;//Ϊһ��ָ�룬ָ��stacknode���ͽڵ��β�ڵ� 
	int count;
}LinkStack;
Status initStack(LinkStack*stack)
{
	stack->count=-1;
	stack->top=NULL;
	return SUCCESS;
}
int isfullStack(LinkStack*stack)
{
	return stack->count==99;//����ֻ�ܴ�һ�ٸ��ڵ� 
}
int isemptyStack(LinkStack*stack)
{
	return stack->count==-1;
}
Status pushStack(LinkStack*stack,char c)
{
	if (isfullStack(stack)){
		return ERROR;
	}else{
		LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));//�����½ڵ� 
		p->data=c;//�����½ڵ������ 
		if(stack->count!=-1)
			p->next=stack->top;//���½ڵ����ӵ�ԭ���Ķ��ڵ� 
		stack->count++;//ջ������1 
		stack->top=p;//ջ��ָ��ָ���½ڵ� 
		return SUCCESS;
	}
}
Status popStack(LinkStack*stack)
{
	if (isemptyStack(stack)){
		return ERROR;
	}else{
		LinkStackPtr p = stack->top;
		if (stack->count!=0)
			stack->top=p->next;
		free(p);
		stack->count--;
		return SUCCESS;
	} 
}
int lengthStack(LinkStack*stack)
{
	return stack->count;
}
char peekStack(LinkStack*stack)
{
	return stack->top->data;
}
Status emptyStack(LinkStack*stack)
{
	if (isemptyStack(stack)){//��ջΪ��
		return ERROR;
	}else{
		LinkStackPtr p = stack->top;
		while(stack->count!=-1)
		{
			stack->top->data='\0';
			stack->top=stack->top->next;
		}
		stack->top = p;
		return SUCCESS;
	}
}
Status destroyStack(LinkStack*stack)
{
	if(isemptyStack(stack)){
		return ERROR;
	}else{
		LinkStackPtr  p;
		while(stack->count != -1)
		{
			p = stack->top;
			stack->top = stack->top->next;
			free(p);
			stack->count--;
		}
		return SUCCESS;
	}
}
#endif//Stack_h_character
