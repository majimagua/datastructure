#include <stdio.h>
#include <stdlib.h>

//用结构体表示链表中的结点
typedef struct link{
	int elem; //数据域
	struct link *next; //指针域
}Link;


//******函数声明******
Link* InitLink1(int length); //创建含头结点的链表
Link* InitLink2(int length); //创建不含头结点的链表
void LinkPrint(Link* p);  //打印链表中的数据
void LinkFree(Link *p); //释放链表


//******主调函数******

int main(){
	Link *p1=NULL;
	Link *p2=NULL;

	p1=InitLink1(6);
	LinkPrint(p1);

	printf("\n\n");

	p2=InitLink2(6);
	LinkPrint(p2);

	LinkFree(p1);	
	LinkFree(p2);

	return 0;
}


//******函数定义******

//创建一个自定义长度的含头结点的单链表
Link* InitLink1(int length){
	printf("创建一个存储%d个数字的含头结点的单链表\n", length);
	//1、创建头指针
	Link* p=NULL;
	//2、创建头结点
	Link* temp=(Link* )malloc(sizeof(Link));
	temp->elem=0;
	temp->next=NULL;
	//头指针指向头结点
	p=temp;
	//3、每创建一个结点，都令其直接前驱结点的指针指向它
	for (int i=1; i<length+1; i++){
		int num;
		printf("请输入第%d个数字：", i);
		scanf("%d", &num);
		//创建一个结点
		Link* a=(Link*)malloc(sizeof(Link));
		a->elem=num;
		a->next=NULL;
		//每次temp指向的结点就是a的直接前驱结点
		temp->next=a;
		//temp指向下一个结点（也就是a），为下次添加结点做准备
		temp=temp->next;
	}
	printf("全部数据输入完毕，链表创建成功\n");
	return p;
}

//创建一个自定义长度的无头结点的单链表
Link *InitLink2(int length){
	printf("创建一个存储%d个数字的无头结点的单链表\n\n", length);
	printf("请输入第1个数字：");
	int num;
	scanf("%d", &num);
	//创建头指针
	Link *p=NULL;
	//创建首元结点
	Link *temp=(Link *)malloc(sizeof(Link));
	temp->elem=num;
	temp->next=NULL;
	//头指针指向首元结点
	p=temp;
	//每创建一个结点，都令其直接前驱结点的指针指向它
	for (int i=2; i<length+1; i++){
		printf("请输入第%d个数字：", i);
		scanf("%d", &num);
		//创建一个结点
		Link *a=(Link *)malloc(sizeof(Link));
		a->elem=num;
		a->next=NULL;
		//每次temp指向的结点就是a的直接前驱结点
		temp->next=a;
		//temp指向下一个结点（也就是a），为下次添加结点做准备
		temp=temp->next;
	}
	printf("全部数据输入完毕，链表创建成功\n");
	return p;
}


//打印链表中存储的数据
void LinkPrint(Link* p){
	//p=p->next;//
	//只要p指向结点的next值不是NULL，就执行输出语句
	while(p){
		printf("%d ", p->elem);
		p=p->next;
	}
	printf("\n");
}

//释放链表
void LinkFree(Link *p){
	Link *fr=NULL;
	while (p->next)
	{
		fr=p->next;
		p->next=p->next->next;
		free(fr);
	}
	free(p);
}
