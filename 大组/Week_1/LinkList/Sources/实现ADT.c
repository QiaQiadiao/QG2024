#include <stdio.h> 
#include <stdlib.h>
typedef struct node//������ṹ�� 
{
	int data;
	struct node *next;
} node;
typedef struct Node//˫����ṹ�� 
{	
	struct Node *prev;
	int data;
	struct Node *next;
} Node;
node* head1=NULL;//ͷ�ڵ� 
Node* head2=NULL;
int n;//������ڵ����� 
int N;//˫������ڵ����� 
void print()//���������ȫ���ڵ� 
{
	node*p = head1;int i;
	printf("���Ϊ��\n");
	for(i=0;i<n;i++){
		printf("�ڵ�%d��dataֵΪ%d\n",i+1,p->data);
		p = p->next;
	}
	system("pause");
}
void Print()//���˫������ȫ���ڵ� 
{
	Node*p = head2;int i;
	printf("���Ϊ��\n");
	for(i=0;i<N;i++){
		printf("�ڵ�%d��dataֵΪ%d\n",i+1,p->data);
		p = p->next;
	}
	system("pause");
}
void createdan()//���������� 
{
	system("cls");
	if (head1 != NULL){
		printf("�ѹ���������");
		system("pause");
		return;
	}
	int i;
	node* p=NULL; node* q=NULL;
	printf("������ڵ�����");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		p = (node* )malloc(sizeof(node));
		p->data = 0;//Ĭ��ֵΪ0 
		p->next = NULL;
		if(i==0){//��һ��headָ��ͷ�ڵ� 
			head1 = p;
		}else{
			q->next = p;
		}
		q = p;
	} 
	print();
}
void createshuan()//����˫������ 
{
	if (head2 != NULL){
		printf("�Ѿ�������˫�����������ظ���");
		system("pause");
		return; 
	}
	system("cls");
	Node*p=NULL,*q;int i;
	printf("������Ҫ���������ڵ㣺");
	scanf("%d",&N);
	for(i=0;i<N;i++){
		p = (Node*)malloc(sizeof(Node));
		p->data = 1;//Ĭ��Ϊ1
		p->next= NULL;
		if(i == 0){
			p->prev = NULL;
			head2 = p;
		} else{
			p->prev = q;
			q->next = p;
		}
		q=p;	
	}
	Print();
}
void insertdan()//����ڵ㣨�������� 
{
	system("cls");
	if (head1 == NULL){
		printf("�빹����������ٽ��д˲���\n");
		system("pause");
		return;
	}
	int loc,i;node* q=head1;n++;
	node* p = (node*)malloc(sizeof(node));
	p->data = 1;
	p->next = NULL;
	printf("������Ҫ�����λ�ã�(λ�ÿ�ѡ��Χ1~�ܽ������1)");
	scanf("%d",&loc);
	if (loc == 1){
		p->next = head1;
		head1 = p;
	}else{
		for(i=0;i<loc-2;i++){
			q=q->next;//ʹqָ��Ŀ��ڵ��ǰһ���ڵ� 
		}
		if (loc==n){
			q->next=p;
		}else{
			p->next = q->next;
			q->next = p;
		}
	}
	print();
}
void insertshuan()
{
	system("cls");
	if(head2 == NULL){
		printf("�빹�����������ѡ��˲���\n");
		system("pause");
		return;
	}
	int loc,i;
	Node* p = head2,*q;N++;
	q = (Node*)malloc(sizeof(Node));
	q->data = 0;
	q->prev = NULL;
	q->next = NULL;
	printf("������Ҫ�����λ�ã���Χ��1~�ڵ�����+1����");
	scanf("%d",&loc);
	if(loc==1){//����λ��Ϊͷ�� 
		q->next = head2;
		head2->prev = q;
		head2 = q;
	}else if(loc == N){//����λ��Ϊ�м� 
		for(i=0;i<loc-2;i++){//�ҵ�β�ڵ� 
			p = p->next;
		}
		p->next = q;
		q->prev = p;
	}else{//����λ��Ϊ���� 
		for(i=0;i<loc-1;i++){//�ҵ���Ӧλ�ýڵ� 
			p = p->next;
		}
		p->prev->next=q;
		q->prev=p->prev;
		q->next=p;
		p->prev=q;	
	}
	Print();
	
}
void deletedan()//ɾ���ڵ㣨�������� 
{
	system("cls");
	if (head1 == NULL){
		printf("�빹����������ٽ��д˲���\n");
		system("pause");
		return;
	}
	n--;int loc,i;
	node*q=head1,*p;
	printf("������Ҫɾ���Ľڵ㣺����ѡ��Χ��1~�ܽ������");
	scanf("%d",&loc);
	if (loc==1){
		head1 = q->next;
		free(q);
	}else{
		for(i=0;i<loc-2;i++){
			q = q->next;
		}
		p = q->next;
		q->next = q->next->next;
		free(p);
	}
	print();
}
void deleteshuan()//ɾ��˫�������еĽڵ� 
{
	system("cls");
	if (head2 == NULL){
		printf("�빹����������ٽ��д˲���\n");
		system("pause");
		return;
	}
	int loc,i;N--;
	Node* p = head2;
	printf("������Ҫɾ���Ľڵ��λ�ã�(��Χ��1~�ܽ����)");
	scanf("%d",&loc);
	if(loc==1){
		p->next->prev = NULL;
		head2 = p->next;
		free(p);
	}else{
		for(i=0;i<loc-1;i++){
			p = p->next;
		}
		if(p->next == NULL){
			p->prev->next =NULL;
			free(p);
		}else{
			p->prev->next = p->next;
			p->next->prev = p->prev;
			free(p);
		}
	}
	Print();
}
void findmid()//�ҵ������е��е� 
{
	system("cls");
	if (head1 == NULL){
		printf("�빹����������ٽ��д˲���\n");
		system("pause");
		return;
	}
	if (n%2 == 0){
		printf("�ڵ���Ϊż�������е�\n");
		system("pause");
		return; 
	}
	node*fast=head1,*slow=head1;
	while(fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("�м��dataΪ��%d\n",slow->data);
	system("pause");
}
void menue()
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("*                                   *\n");
	printf("* ��ѡ��                          *\n");
	printf("*                                   *\n");
	printf("*       1.����������                *\n");
	printf("*                                   *\n");
	printf("*       2.����ڵ㵽������          *\n");
	printf("*                                   *\n");
	printf("*       3.ɾ��������ڵ�            *\n");
	printf("*                                   *\n");
	printf("*       4.�ҵ��������е�            *\n");
	printf("*                                   *\n");
	printf("*       5.����˫������              *\n");
	printf("*                                   *\n");
	printf("*       6.����ڵ㵽˫������        *\n");
	printf("*                                   *\n");
	printf("*       7.ɾ��˫�������еĽڵ�      *\n");
	printf("*                                   *\n");
	printf("*       8.��������ż����            *\n");
	printf("*                                   *\n");
	printf("*       9.���������                *\n");
	printf("*                                   *\n");
	printf("*       10.���˫������             *\n");	
	printf("*                                   *\n");	
	printf("*       11.�˳�                     *\n");
	printf("*                                   *\n");	
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void exchange()
{
	system("cls");
	if (head1 == NULL){
		printf("�빹����������ٽ��д˲���\n");
		system("pause");
		return;
	}
	if(n%2!=0){
		printf("������ڵ���Ϊ�������޷�ʵ�ֵ���");
		system("pause");
		return;
	}
	node*p=head1,*q,*t;int i;
	head1 = p->next;
	for(i=0;i<n/2;i++){//�Ի�����Ϊn/2 
		q=p->next;
		p->next = q->next;
		q->next = p;
		if (i!=0){//��һ��֮��Ҫ����������� 
			t->next=q;
		}
		t = p;
		p=p->next;
	}
	print();
}
int main()
{
	int choice;
	while (1){
		system("cls");
		menue();
		scanf("%d",&choice);
		switch (choice){
			case 1:
				createdan();
				break;
			case 2:
				insertdan();
				break;
			case 3:
				deletedan();
				break;
			case 4:
				findmid();
				break;
			case 5:
				createshuan();
				break;
			case 6:
				insertshuan();
				break;
			case 7:
				deleteshuan();
				break; 
			case 8:
				exchange(); 
				break;
			case 9:
				print();
				break;
			case 10:
				Print();
				break; 
			case 11:
				printf("��лʹ�ã�");
				choice = -1;
				system("pause");
				break;
			default:
				printf("��Чѡ��������...");
				system("pause");
		}		
		if (choice == -1)
			break;
	}
}

