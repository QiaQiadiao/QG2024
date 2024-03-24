#include <stdio.h>
#include <string.h>
#include "Stack_h_character.h" 
char b[100];//用于存储中缀表达式 
char d[100];//用于存储后缀表达式 
void menue()
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("*                               *\n");
	printf("* 请选择；                      *\n");
	printf("*                               *\n");
	printf("*      1.输入                   *\n");
	printf("*                               *\n");
	printf("*      2.计算并输出             *\n");
	printf("*                               *\n");
	printf("*      3.清除                   *\n");
	printf("*                               *\n");
	printf("*      4.退出                   *\n");
	printf("*                               *\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
int getpriority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;  // 默认优先级为0
}
int mend(char s)
{
	if(s<=127&&s>=0)
	{
		return (int)(s-'0');
	}else{
		return (int)(s+129+127-'0');
	}
}
void shuru(LinkStack*stack)
{
	if(isemptyStack(stack)){    
		system("cls");
		printf("请输入标准的中缀表达式：(末尾不用输入等于号)");
		scanf("%s",&b);
		int i,j=0;
		for(i=0;i<strlen(b);i++)//遍历中缀表达式
		{
			if(b[i]<='9'&&b[i]>='0')//当遇到数字
			{
				d[j++]=b[i];//直接输出
			 }
			else if(b[i]=='(')//遇到左括号
			{  
				pushStack(stack,b[i]);//压入栈 
			 }
			else if(b[i]==')')//遇到右括号 
			{
				do{
					d[j++]=peekStack(stack);
					popStack(stack);	
				}while(peekStack(stack)!='(');	
				if(peekStack(stack)=='(')
					popStack(stack);
			 }
			else if(b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/')//遇到运算符 
			{
				if(isemptyStack(stack)||getpriority(b[i])>getpriority(peekStack(stack))){
					pushStack(stack,b[i]);
				}else if(getpriority(b[i])<=getpriority(peekStack(stack)))
				{
					//栈顶弹出，再比较新栈顶运算符，直到运算符大于栈顶运算符 ,再压入栈。
					do{
						d[j++]=peekStack(stack);
						popStack(stack);
					}while(!isemptyStack(stack)||getpriority(b[i])<=getpriority(peekStack(stack)));
					pushStack(stack,b[i]);
				 }
			}
			else//当遇到啥也不是的 
			{
				printf("输入有误，请规范输入\n");
				system("pause");
				destroyStack(stack);
				for(i=0;i<strlen(b);i++){
					b[i]='\0';
				}
				break;
			}
		 } 
		 while(!isemptyStack(stack))
		 {
		 	d[j++]=peekStack(stack);
		 	popStack(stack);
		 }
	}else{
		printf("请先清除上次输入的记录再进行此操作\n");
		system("pause");
	}
	return;
}
void shuchu(LinkStack*stack)
{
	if(b[0]=='\0'){
		printf("请进行输入操作后再进行此操作。\n");
		system("pause");//6+(4-2)*3+9/3
		return;
	}
	int i;char choice;int t1,t2,result=0;
	for(i=0;i<strlen(d);i++){
		if(d[i]<='9'&&d[i]>='0')
		{
			pushStack(stack,d[i]);
		}else if(d[i]=='+'||d[i]=='-'||d[i]=='*'||d[i]=='/')
		{
			t2=mend(peekStack(stack));
			popStack(stack);
			t1=mend(peekStack(stack));
			popStack(stack);
			choice=d[i];
			switch (choice)
			{
				case '+':
					result=t1+t2;
					break;
				case '-':
					result=t1-t2;
					break;
				case '*':
					result=t1*t2;
					break;
				case '/':
					result=t1/t2;
					break;
			}
			pushStack(stack,(char)(result+48));
		}	
	}
	printf("计算结果为：%d\n",mend(peekStack(stack)));
	system("pause");
}
void qingchu(LinkStack*stack)
{
	if(b[0]=='\0')
	{
		printf("已清除干净，无需重复此操作\n");
		system("pause");
	}else{
		int i;
		for(i=0;i<strlen(b);i++)
		{
			b[i]='\0';
		}
		for(i=0;i<strlen(d);i++)
		{
			d[i]='\0';
		}
		destroyStack(stack);
		printf("清除成功！\n");
		system("pause");
	}
	return;
}
int main()
{
	char choice[15];int flag=0;
	LinkStack stack;
	initStack(&stack);//初始化栈 
	while (1){
		system("cls");
		menue();
		scanf("%s",&choice);
		if (strcmp(choice,"1")==0)
				shuru(&stack);
		else if(strcmp(choice,"2")==0)
				shuchu(&stack);
		else if(strcmp(choice,"3")==0)
				qingchu(&stack);
		else if(strcmp(choice,"4")==0){
				printf("感谢使用！");
				flag = 1;
				system("pause");
		}
		else{
				printf("无效选择请重试...");
				system("pause");
		}	
		if (flag == 1)
			break;
	}
}
