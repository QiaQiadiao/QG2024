#include <stdio.h>
#include "LQueue.h"
void menue()
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("*                          *\n");
	printf("*��ѡ��                  *\n");
	printf("*                          *\n");
	printf("*      1.��ʼ������        *\n");
	printf("*                          *\n");
	printf("*      2.���              *\n");
	printf("*                          *\n");
	printf("*      3.����              *\n");
	printf("*                          *\n");
	printf("*      4.����              *\n");
	printf("*                          *\n");
	printf("*      5.�鿴��ͷ          *\n");
	printf("*                          *\n");
	printf("*      6.�п�              *\n");
	printf("*                          *\n");
	printf("*      7.���г���          *\n");
	printf("*                          *\n");
	printf("*      8.�������          *\n");
	printf("*                          *\n");
	printf("*      9.�˳�              *\n");
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
			printf("��ʼ�����гɹ�\n");
			system("pause");
		}
		else if(strcmp(choice,"2")==0)
		{
			while(1)
			{
				system("cls");
				printf("�������������ͣ�\n1.����\n2.������\n3.�ַ���\n4.�˳�\n");
				scanf("%d",&choice1);
				switch (choice1)
				{
					case 1:
						printf("����������:");
						scanf("%d",&intdata);
						EnLQueue(&Q,&intdata);
						flag1=1;
						break;
					case 2:
						printf("����������:");
						scanf("%f",&floatdata);
						EnLQueue(&Q,&floatdata);
						flag1=1;
						break;
					case 3:
						printf("����������:");
						scanf("%c",&chardata);
						EnLQueue(&Q,&chardata);
						flag1=1;
						break;
					case 4:
						flag1 = 1;
						break;
					default:
						printf("��Чѡ��������\n");
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
				printf("�����ɹ�\n");
			}else{
				printf("����ʧ��\n");
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
			printf("�㲻������û������������ָ��...\n");
			system("pause");
		}
		else if(strcmp(choice,"6")==0)
		{
			if(IsEmptyLQueue(&Q))
				printf("Ϊ��\n");
			else
				printf("��Ϊ��\n");
			system("pause");
		}	
		else if(strcmp(choice,"7")==0)
		{
			printf("���г���Ϊ��%d",LengthLQueue(&Q));
			system("pause");
		}
		else if(strcmp(choice,"8")==0)
		{
			printf("�㲻������û������������ָ��...\n");
			system("pause");
		}
		else if(strcmp(choice,"9")==0){
				printf("��лʹ�ã�");
				flag = 1;
				system("pause");
		}else{
				printf("��Чѡ��������...");
				system("pause");
		}	
		if (flag == 1)
			break;
	}
}
