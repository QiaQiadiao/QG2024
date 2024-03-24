#include <stdio.h>
#include "LQueue.h"
void menue()
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("*                          *\n");
	printf("*请选择：                  *\n");
	printf("*                          *\n");
	printf("*      1.初始化队列        *\n");
	printf("*                          *\n");
	printf("*      2.入队              *\n");
	printf("*                          *\n");
	printf("*      3.出队              *\n");
	printf("*                          *\n");
	printf("*      4.销毁              *\n");
	printf("*                          *\n");
	printf("*      5.查看队头          *\n");
	printf("*                          *\n");
	printf("*      6.判空              *\n");
	printf("*                          *\n");
	printf("*      7.队列长度          *\n");
	printf("*                          *\n");
	printf("*      8.输出队列          *\n");
	printf("*                          *\n");
	printf("*      9.退出              *\n");
	printf("*                          *\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");	
}
int main()
{
	char choice[10];
	int choice1,flag=0,flag1=0,flag2;
	int intdata;char chardata; float floatdata;
	LinkQueue Q;
	while (1)
	{
		system("cls");
		menue();
		scanf("%s",&choice);
		if (strcmp(choice,"1")==0)
		{
			InitLQueue(&Q);
			printf("初始化队列成功\n");
			system("pause");
		}
		else if(strcmp(choice,"2")==0)
		{
			while(1)
			{
				system("cls");
				printf("请输入数据类型：\n1.整型\n2.浮点型\n3.字符型\n4.退出\n");
				scanf("%d",&choice1);
				switch (choice1)
				{
					case 1:
						printf("请输入数据:");
						scanf("%d",&intdata);
						EnLQueue(&Q,&intdata);
						flag1=1;
						break;
					case 2:
						printf("请输入数据:");
						scanf("%f",&floatdata);
						EnLQueue(&Q,&floatdata);
						flag1=1;
						break;
					case 3:
						printf("请输入数据:");
						scanf("%c",&chardata);
						EnLQueue(&Q,&chardata);
						flag1=1;
						break;
					case 4:
						flag1 = 1;
						break;
					default:
						printf("无效选择，请重试\n");
						system("pause");
						break;
				}
				if(flag1 == 1)
				{
					flag1=0;break;
				}
			}
			system("pause");
		}
		else if(strcmp(choice,"3")==0)
		{
			if(DeLQueue(&Q)){
				printf("操作成功\n");
			}else{
				printf("操作失败\n");
			}
			system("pause");
		}
		else if(strcmp(choice,"4")==0)
		{
			DestroyLQueue(&Q);
			system("pause");
		}
		else if(strcmp(choice,"5")==0)
		{
			printf("搞不出来，没搞明白无类型指针...\n");
			system("pause");
		}
		else if(strcmp(choice,"6")==0)
		{
			if(IsEmptyLQueue(&Q))
				printf("为空\n");
			else
				printf("不为空\n");
			system("pause");
		}	
		else if(strcmp(choice,"7")==0)
		{
			printf("队列长度为：%d",LengthLQueue(&Q));
			system("pause");
		}
		else if(strcmp(choice,"8")==0)
		{
			printf("搞不出来，没搞明白无类型指针...\n");
			system("pause");
		}
		else if(strcmp(choice,"9")==0){
				printf("感谢使用！");
				flag = 1;
				system("pause");
		}else{
				printf("无效选择请重试...");
				system("pause");
		}	
		if (flag == 1)
			break;
	}
}
