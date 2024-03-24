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
}StackNode,*LinkStackPtr;//相当于StackNode* 
typedef struct LinkStack
{
	LinkStackPtr top;//为一个指针，指向stacknode类型节点的尾节点 
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
	return stack->count==99;//假设只能存一百个节点 
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
		LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));//开辟新节点 
		p->data=c;//完善新节点的数据 
		if(stack->count!=-1)
			p->next=stack->top;//把新节点链接到原来的顶节点 
		stack->count++;//栈总数加1 
		stack->top=p;//栈顶指针指向新节点 
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
	if (isemptyStack(stack)){//当栈为空
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
