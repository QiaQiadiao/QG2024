#include <stdio.h>
#include <stdlib.h>
int main()
{
	unsigned int i,n=10000, a;
	FILE *fp1 = fopen("10000data.txt","w");
	FILE *fp2 = fopen("50000data.txt","w");
	FILE *fp3 = fopen("200000data.txt","w");
	if(fp1 != NULL)
	{
		srand((unsigned)time(NULL));//写10000的文件 
		for(i=0;i<n;i++)
		{
			a = rand() % 60000;
			fprintf(fp1,"%u\n",a);
		}
		fclose(fp1);
	}
	n = 50000; 
	if(fp2 != NULL)//写50000的文件
	{
		for(i=0;i<n;i++)
		{
			a = rand() % 60000;
			fprintf(fp2,"%u\n",a);
		}
		fclose(fp2);
	}
	int j;
	if(fp3 != NULL)	
	{
		for(j=0;j<4;j++){
			for(i=0;i<n;i++){
				a = rand() % 60000;
				fprintf(fp3,"%u\n",a);
			}
		}
		fclose(fp3);
	}
	printf("随机数生成完毕\n");
 } 
