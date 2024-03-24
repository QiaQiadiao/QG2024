#include <stdio.h>
#include <string.h>
#include "Stack_h_character.h" 
char b[100];//���ڴ洢��׺���ʽ 
char d[100];//���ڴ洢��׺���ʽ 
void menue()
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("*                               *\n");
	printf("* ��ѡ��                      *\n");
	printf("*                               *\n");
	printf("*      1.����                   *\n");
	printf("*                               *\n");
	printf("*      2.���㲢���             *\n");
	printf("*                               *\n");
	printf("*      3.���                   *\n");
	printf("*                               *\n");
	printf("*      4.�˳�                   *\n");
	printf("*                               *\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
int getpriority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;  // Ĭ�����ȼ�Ϊ0
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
		printf("�������׼����׺���ʽ��(ĩβ����������ں�)");
		scanf("%s",&b);
		int i,j=0;
		for(i=0;i<strlen(b);i++)//������׺���ʽ
		{
			if(b[i]<='9'&&b[i]>='0')//����������
			{
				d[j++]=b[i];//ֱ�����
			 }
			else if(b[i]=='(')//����������
			{  
				pushStack(stack,b[i]);//ѹ��ջ 
			 }
			else if(b[i]==')')//���������� 
			{
				do{
					d[j++]=peekStack(stack);
					popStack(stack);	
				}while(peekStack(stack)!='(');	
				if(peekStack(stack)=='(')
					popStack(stack);
			 }
			else if(b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/')//��������� 
			{
				if(isemptyStack(stack)||getpriority(b[i])>getpriority(peekStack(stack))){
					pushStack(stack,b[i]);
				}else if(getpriority(b[i])<=getpriority(peekStack(stack)))
				{
					//ջ���������ٱȽ���ջ���������ֱ�����������ջ������� ,��ѹ��ջ��
					do{
						d[j++]=peekStack(stack);
						popStack(stack);
					}while(!isemptyStack(stack)||getpriority(b[i])<=getpriority(peekStack(stack)));
					pushStack(stack,b[i]);
				 }
			}
			else//������ɶҲ���ǵ� 
			{
				printf("����������淶����\n");
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
		printf("��������ϴ�����ļ�¼�ٽ��д˲���\n");
		system("pause");
	}
	return;
}
void shuchu(LinkStack*stack)
{
	if(b[0]=='\0'){
		printf("���������������ٽ��д˲�����\n");
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
	printf("������Ϊ��%d\n",mend(peekStack(stack)));
	system("pause");
}
void qingchu(LinkStack*stack)
{
	if(b[0]=='\0')
	{
		printf("������ɾ��������ظ��˲���\n");
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
		printf("����ɹ���\n");
		system("pause");
	}
	return;
}
int main()
{
	char choice[15];int flag=0;
	LinkStack stack;
	initStack(&stack);//��ʼ��ջ 
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
				printf("��лʹ�ã�");
				flag = 1;
				system("pause");
		}
		else{
				printf("��Чѡ��������...");
				system("pause");
		}	
		if (flag == 1)
			break;
	}
}
