#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
unsigned int a[200000];
char Choice[10];
void menue()
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("* #����Ĭ��Ϊ��������      *\n");
	printf("* ��ѡ��                 *\n");
	printf("*                          *\n");
	printf("*      1.��������          *\n");
	printf("*                          *\n");
	printf("*      2.�鲢����          *\n");
	printf("*                          *\n");
	printf("*      3.��������          *\n");
	printf("*                          *\n");
	printf("*      4.��������          *\n");
	printf("*                          *\n");
	printf("*      5.��������          *\n");
	printf("*                          *\n");
	printf("*      6.���              *\n");
	printf("*                          *\n");
	printf("*      7.�˳�              *\n");	
	printf("*                          *\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
int load()
{
	FILE *fp;unsigned int i = 0;
	
	while(1)
	{
		system("cls");
		printf("��������Ҫ��������:\n1.10000\n2.50000\n3.200000\n");
		scanf("%s",&Choice); 
		
		if (strcmp(Choice,"1") == 0)
			fp = fopen("10000data.txt","r");
		else if(strcmp(Choice,"2") == 0)
			fp = fopen("50000data.txt","r");
		else if(strcmp(Choice,"3") == 0)
			fp = fopen("200000data.txt","r");
		else{
			printf("�������������");
			system("pause");	
		}
		
		if (strcmp(Choice,"1") == 0 || strcmp(Choice,"2") == 0 || strcmp(Choice,"3") == 0)
			break;
			
	}
	
	if(fp == NULL)
	{
		printf("���س���������\n");
		system("pause");
		return 0;
	}
	
	while(fscanf(fp,"%u",&a[i++]) == 1)
	{
		while(fgetc(fp) != '\n');
	 } 
	 
	if(feof(fp)){
		printf("���ݼ��سɹ���\n"); 
		system("pause");		
	}else if(ferror(fp)){
		printf("���ݼ���ʧ�ܣ�������\n");
		system("pause");
		return 0;
	}
	
	fclose(fp);
	return 1;
}
void charu()
{
	unsigned int i,n,key;int j;
	 
	if (strcmp(Choice,"1") == 0)
		n = 10000;
	else if(strcmp(Choice,"2") == 0)
		n = 50000;
	else if(strcmp(Choice,"3") == 0)
		n = 200000;
		
	for(i=1; i<n ; i++)
	{
		key = a[i];
		j = i-1;
		
		while(a[j] > key && j >= 0)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
	
	printf("����ɹ���\n");
	system("pause");
}
void merge2(int a[200000],int left, int mid, int right)
{
	int n1 = mid-left+1;//����������������� 
	int n2 = right-mid;
	
	int L[n1],R[n2],i,j,k;
	for(i = 0; i < n1; i++){L[i] = a[left+i];}
	for(j = 0; j < n2; j++){R[j] = a[mid+1+j];}
	
	i=0;j=0;k=left;//�ֱ�ָ��������飬�ұ����飬�ϲ�������� 
	while(i < n1 && j < n2 )
	{
		if(L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}else{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1)//����ʣ�ಿ�� 
		a[k++] = L[i++];
	while(j < n2)
		a[k++] = R[j++];
}
void merge1(int a[200000],int left, int right)
{
	if(right > left)
	{
		int mid = left + (right-left)/2;
		
		merge1(a,left,mid);
		merge1(a,mid+1,right);
		
		merge2(a,left,mid,right);
	}
}
void guibin()
{
	int right,left = 0;
	
	if (strcmp(Choice,"1") == 0)
		right = 10000;
	else if(strcmp(Choice,"2") == 0)
		right = 50000;
	else if(strcmp(Choice,"3") == 0)
		right = 200000;
	
	merge1(a,left,right);
	
	printf("����ɹ���");
	system("pause");
}
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int quick2(int a[200000],int left,int right)
{
	int i = left-1, j, pivot = a[right];
	
	for(j = left; j < right; j++)
	{
		if(a[j] <= pivot)
			swap(&a[++i],&a[j]);
	}
	
	swap(&a[i+1],&a[right]);
	return i+1;
}
void quick1(int a[200000],int left,int right)
{
	if(left < right)
	{
		int pi = quick2(a,left,right);
		
		quick1(a,left,pi-1);
		quick1(a,pi+1,right);
	}
}
void kuaisu()
{
	int right,left = 0;
	
	if (strcmp(Choice,"1") == 0)
		right = 10000;
	else if(strcmp(Choice,"2") == 0)
		right = 50000;
	else if(strcmp(Choice,"3") == 0)
		right = 200000;
		
	quick1(a,left,right-1);
	
	printf("����ɹ���");
	system("pause");
}
void jishu1()
{
	int length,max=a[0],min=a[0];
	int n,i,j=0;
	
	if (strcmp(Choice,"1") == 0)
		n = 10000;
	else if(strcmp(Choice,"2") == 0)
		n = 50000;
	else if(strcmp(Choice,"3") == 0)
		n = 200000;
		
	for(i = 0;i < n; i++)
	{
		if(a[i] > max)
			max = a[i];
		if(a[i] < min)
			min = a[i];
	}
	
	length = max-min+1;
	int *count = (int*)malloc(length * sizeof(int));//������count[length]����������Ĵ�С 
	if (count == NULL)
	{
		printf("�ڴ�������������\n");
		system("pause");
		return;
	}
	for(i = 0; i < length; i++) count[i]=0;
	
	for(i = 0; i < n; i++) count[a[i]-min]++;
	for(i = 0; i < length; i++)
	{
		while(count[i] > 0)
		{
			a[j++] = i+min;
			count[i]--;
		}
	}
	
	free(count);
	printf("����ɹ���");
	system("pause");
}
void jishu2()
{
	int n;
	if (strcmp(Choice,"1") == 0)
		n = 10000;
	else if(strcmp(Choice,"2") == 0)
		n = 50000;
	else if(strcmp(Choice,"3") == 0)
		n = 200000;
		
	int width=0,bucket1[10][n],bucket2[10]={0},bucket3[10]={0};
	int max = a[0],i,j,k=0,w,digit;
	
	for(i = 0; i < n; i++)
	{
		if(a[i] > max)
			max = a[i];
	}
	while(max != 0)
	{
		max /= 10;
		width++;
	}
	
	for(i = 0; i < width; i++)
	{
		for(j = 0; j < 10; j++) bucket2[j] = 0;//����Ͱ����
		
		for(j = 0; j < n; j++)
		{
			digit = (a[j]/(int)pow(10,i)) % 10;
			bucket2[digit]++;
		 } 
		
		for(j = 0; j < 10; j++) bucket3[j] = bucket2[j];
		
		for(j = n-1; j >= 0; j--)
		{
			digit = (a[j]/(int)pow(10,i)) % 10;
			bucket1[digit][bucket2[digit]-1] = a[j];
			bucket2[digit]--;
		}
		
		for(k = 0,j = 0,w = 0; j < n; j++)
		{
			if(bucket3[w] > 0)
			{
				a[j] = bucket1[w][k++];
				bucket3[w]--;
			}else{
				w++;
				k = 0;
			}
		 } 
	}
    printf("����ɹ���\n");
	system("pause");
}
void print()
{
	system("cls");
	unsigned int n,i;
	
	if (strcmp(Choice,"1") == 0)
		n = 10000;
	else if(strcmp(Choice,"2") == 0)
		n = 50000;
	else if(strcmp(Choice,"3") == 0)
		n = 200000;
	
	printf("������Ϊ��\n");	
	for(i = 0; i < n; i++)
	{
		printf("%d\t",a[i]);
		if( (i+1)%10 == 0 && i != 0)
			printf("\n");
	}
	printf("\n");
	system("pause");
}
int main()
{
	char choice[10];int flag = 0;
	if( !load() )
		return 0;
	while (1)
	{
		system("cls");
		menue();
		scanf("%s",&choice);
		if (strcmp(choice,"1") == 0)
			charu();
		else if(strcmp(choice,"2")==0)
			guibin();
		else if(strcmp(choice,"3")==0)
			kuaisu();
		else if(strcmp(choice,"4")==0)
			jishu1();
		else if(strcmp(choice,"5")==0)
			jishu2();
		else if(strcmp(choice,"6")==0)
			print();
		else if(strcmp(choice,"7")==0)
			flag = 1;	
		else{
			printf("��Чѡ��������");
			system("cls"); 
		}
		
		if(flag == 1)
			break;
	}
}
