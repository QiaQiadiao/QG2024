#include <stdio.h> 
#include <stdlib.h>
typedef struct node//单链表结构体 
{
	int data;
	struct node *next;
} node;
typedef struct Node//双链表结构体 
{	
	struct Node *prev;
	int data;
	struct Node *next;
} Node;
node* head1=NULL;//头节点 
Node* head2=NULL;
int n;//单链表节点总数 
int N;//双向链表节点总数 
void print()//输出单链表全部节点 
{
	node*p = head1;int i;
	if(head1!=NULL){
		printf("结果为：\n");
		for(i=0;i<n;i++){
			printf("节点%d的data值为%d\n",i+1,p->data);
			p = p->next;
		}		
	}else{
		printf("未构建单链表，请先构建链表\n");
	}
	system("pause");
}
void Print()//输出双向链表全部节点 
{
	Node*p = head2;int i;
	if(head2!=NULL){
		printf("结果为：\n");
		for(i=0;i<N;i++){
			printf("节点%d的data值为%d\n",i+1,p->data);
			p = p->next;
		}		
	}else{
		printf("未构建双向链表，请先构建链表\n");	
	}
	system("pause");
}
void createdan()//构建单链表 
{
	system("cls");
	if (head1 != NULL){
		printf("已构建过链表");
		system("pause");
		return;
	}
	int i;
	node* p=NULL; node* q=NULL;
	printf("请输入节点数：");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		p = (node* )malloc(sizeof(node));
		printf("请输入要第%d个节点的data值：",i+1);
		scanf("%d",&p->data);
		p->next = NULL;
		if(i==0){//第一次head指向头节点 
			head1 = p;
		}else{
			q->next = p;
		}
		q = p;
	} 
	print();
}
void createshuan()//构建双向链表 
{
	if (head2 != NULL){
		printf("已经构建过双向链表，请勿重复！");
		system("pause");
		return; 
	}
	system("cls");
	Node*p=NULL,*q;int i;
	printf("请输入要构建几个节点：");
	scanf("%d",&N);
	for(i=0;i<N;i++){
		p = (Node*)malloc(sizeof(Node));
		printf("请输入要第%d个节点的data值：",i+1);
		scanf("%d",&p->data);
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
void insertdan()//插入节点（单向链表） 
{
	system("cls");
	if (head1 == NULL){
		printf("请构建单链表后再进行此操作\n");
		system("pause");
		return;
	}
	int loc,i;node* q=head1;n++;
	node* p = (node*)malloc(sizeof(node));
	printf("请输入要插入节点的data值：");
	scanf("%d",&p->data);
	p->next = NULL;
	while(1){
		printf("请输入要插入的位置：(位置可选择范围1~总结点数加1)");
		scanf("%d",&loc);
		if(loc<=n+1&&loc>=1)
			break;
		else{
			printf("输入位置不规范，位置可选择范围1~总结点数加1,请重新输入\n");
			system("pause") ;
		}
	}
	if (loc == 1){
		p->next = head1;
		head1 = p;
	}else{
		for(i=0;i<loc-2;i++){
			q=q->next;//使q指向目标节点的前一个节点 
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
		printf("请构建完链表后再选择此操作\n");
		system("pause");
		return;
	}
	int loc,i;
	Node* p = head2,*q;N++;
	q = (Node*)malloc(sizeof(Node));
	printf("请输入要插入节点的data值：");
	scanf("%d",&q->data);
	q->prev = NULL;
	q->next = NULL;
	while(1){
			printf("请输入要插入的位置：(位置可选择范围1~总结点数加1)");
			scanf("%d",&loc);
			if(loc<=n+1&&loc>=1)
				break;
			else{
				printf("输入位置不规范，位置可选择范围1~总结点数加1,请重新输入\n");
				system("pause") ;
			}
		}
	if(loc==1){//插入位置为头部 
		q->next = head2;
		head2->prev = q;
		head2 = q;
	}else if(loc == N){//插入位置为中间 
		for(i=0;i<loc-2;i++){//找到尾节点 
			p = p->next;
		}
		p->next = q;
		q->prev = p;
	}else{//插入位置为最后边 
		for(i=0;i<loc-1;i++){//找到对应位置节点 
			p = p->next;
		}
		p->prev->next=q;
		q->prev=p->prev;
		q->next=p;
		p->prev=q;	
	}
	Print();
	
}
void deletedan()//删除节点（单向链表） 
{
	system("cls");
	if (head1 == NULL){
		printf("请构建单链表后再进行此操作\n");
		system("pause");
		return;
	}
	n--;int loc,i;
	node*q=head1,*p;
	printf("请输入要删除的节点：（可选择范围：1~总结点数）");
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
void deleteshuan()//删除双向链表中的节点 
{
	system("cls");
	if (head2 == NULL){
		printf("请构建单链表后再进行此操作\n");
		system("pause");
		return;
	}
	int loc,i;N--;
	Node* p = head2;
	printf("请输入要删除的节点的位置：(范围：1~总结点数)");
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
void findmid()//找单链表中的中点 
{
	system("cls");
	if (head1 == NULL){
		printf("请构建单链表后再进行此操作\n");
		system("pause");
		return;
	}
	if (n%2 == 0){
		printf("节点数为偶数，无中点\n");
		system("pause");
		return; 
	}
	node*fast=head1,*slow=head1;
	while(fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	printf("中间点data为：%d\n",slow->data);
	system("pause");
}
void menue()
{
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("*                                   *\n");
	printf("* 请选择：                          *\n");
	printf("*                                   *\n");
	printf("*       1.构建单链表                *\n");
	printf("*                                   *\n");
	printf("*       2.插入节点到单链表          *\n");
	printf("*                                   *\n");
	printf("*       3.删除单链表节点            *\n");
	printf("*                                   *\n");
	printf("*       4.找到单链表中点            *\n");
	printf("*                                   *\n");
	printf("*       5.构建双向链表              *\n");
	printf("*                                   *\n");
	printf("*       6.插入节点到双向链表        *\n");
	printf("*                                   *\n");
	printf("*       7.删除双向链表中的节点      *\n");
	printf("*                                   *\n");
	printf("*       8.单链表奇偶互换            *\n");
	printf("*                                   *\n");
	printf("*       9.输出单链表                *\n");
	printf("*                                   *\n");
	printf("*       10.输出双向链表             *\n");	
	printf("*                                   *\n");	
	printf("*       11.退出                     *\n");
	printf("*                                   *\n");	
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
void exchange()
{
	system("cls");
	if (head1 == NULL){
		printf("请构建单链表后再进行此操作\n");
		system("pause");
		return;
	}
	if(n%2!=0){
		printf("单链表节点数为奇数，无法实现调换");
		system("pause");
		return;
	}
	node*p=head1,*q,*t;int i;
	head1 = p->next;
	for(i=0;i<n/2;i++){//对换次数为n/2 
		q=p->next;
		p->next = q->next;
		q->next = p;
		if (i!=0){//第一次之后要进行特殊操作 
			t->next=q;
		}
		t = p;
		p=p->next;
	}
	print();
}
int main()
{
	char choice[10];int flag = 0;
	while (1){
		system("cls");
		menue();
		scanf("%s",&choice);
		if (strcmp(choice,"1")==0)
				createdan();
		else if(strcmp(choice,"2")==0)
				insertdan();
		else if(strcmp(choice,"3")==0)
				deletedan();
		else if(strcmp(choice,"4")==0)
				findmid();
		else if(strcmp(choice,"5")==0)
				createshuan();
		else if(strcmp(choice,"6")==0)
				insertshuan();
		else if(strcmp(choice,"7")==0)
				deleteshuan();
		else if(strcmp(choice,"8")==0)
				exchange(); 
		else if(strcmp(choice,"9")==0)
				print();
		else if(strcmp(choice,"10")==0)
				Print();
		else if(strcmp(choice,"11")==0){
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

