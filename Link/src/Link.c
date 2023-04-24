#include <stdio.h>
#include <stdlib.h>
#include "Link.h"

//******函数定义********

//创建一个存储{1,2,3,4}且含头结点的链表
Link* InitLink1(){
	
	//1、创建头指针
	Link* p=NULL;
	//2、创建头结点
	Link* temp=(Link* )malloc(sizeof(Link));
	temp->elem=0;
	temp->next=NULL;
	//头指针指向头结点
	p=temp;
	//3、每创建一个结点，都令其直接前驱结点的指针指向它
	for (int i=1; i<5; i++){
		//创建一个结点
		Link* a=(Link*)malloc(sizeof(Link));
		a->elem=i;
		a->next=NULL;
		//每次temp指向的结点就是a的直接前驱结点
		temp->next=a;
		//temp指向下一个结点（也就是a），为下次添加结点做准备
		temp=temp->next;
	}
	return p;
}

//创建一个存储{1,2,3,4}且无头结点的链表
Link *InitLink2(){
	//创建头指针
	Link *p=NULL;
	//创建首元结点
	Link *temp=(Link *)malloc(sizeof(Link));
	temp->elem=1;
	temp->next=NULL;
	//头指针指向首元结点
	p=temp;
	//每创建一个结点，都令其直接前驱结点的指针指向它
	for (int i=2; i<5; i++){
		//创建一个结点
		Link *a=(Link *)malloc(sizeof(Link));
		a->elem=i;
		a->next=NULL;
		//每次temp指向的结点就是a的直接前驱结点
		temp->next=a;
		//temp指向下一个结点（也就是a），为下次添加结点做准备
		temp=temp->next;
	}
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

//向有头结点的链表插入元素
void LinkInsert1(Link *p, int add, int elem){
	Link *c=NULL;
	Link *temp=p; //创建临时结点temp
	//首先找到要插入位置的上一个结点
	for (int i=1; i<add;i++){
		temp=temp->next;
		if(temp==NULL){
			printf("插入位置无效\n");
			return;
		}
	}
	//创建插入结点c
	c=(Link *)malloc(sizeof(Link));
	c->elem=elem;
	//将新节点的next指针指向插入位置后的结点
	c->next=temp->next;
	//将插入位置前结点的next指针指向插入结点
	temp->next=c;
}

//向无头结点的链表插入元素
Link *LinkInsert2(Link *p, int add, int elem){
	if(add==1){
		//创建插入结点c
		Link *c=(Link*)malloc(sizeof(Link));
		c->elem=elem;
		c->next=p;
		p=c;
		return p;
	} //当add==1成立时，形参指针p的值会发生变化，因此需要将它的新值作为函数的返回值返回
	else{
		Link *c=NULL;
		Link* temp=p; //创建临时结点temp
		//首先找到要插入位置的上一个结点
		for (int i=1; i<add-1; i++){
			temp=temp->next;
			if(temp==NULL){
				printf("插入位置无效\n");
				return p;
			}
		}
		//创建插入结点c
		c=(Link *)malloc(sizeof(Link));
		c->elem=elem;
		//向链表中插入结点
		c->next=temp->next;
		temp->next=c;
		return p;
	}
}

//从有头结点的链表删除元素
int LinkDelete1(Link *p, int elem){
	Link *del=NULL;
	Link *temp=p;
	int find=0;
	//1、找到目标元素的直接前驱结点
	while (temp->next){
		if(temp->next->elem==elem){
			find=1;
			break;
		}
		temp=temp->next;
	}
	if (find==0){
		return -1; //删除失败
	}
	else
	{
		//标记要删除的结点
		del=temp->next;
		//2、将目标结点从链表上摘除
		temp->next=temp->next->next;
		//3、释放目标结点
		free(del);
		return 1;
	}
}

//从无头结点的链表删除元素
//注意，该函数的形参p为二级指针，调用时需要传递链表头指针的地址
int LinkDelete2(Link **p, int elem){
	Link *del=NULL;
	Link *temp=*p;
	//删除首元结点需要单独考虑
	if(temp->elem==elem){
		(*p)=(*p)->next;
		free(temp);
		return 1;
	}
	else
	{
		int find=0;
		//1、找到目标元素的直接前驱结点
		while (temp->next){
			if (temp->next->elem==elem){
				find=1;
				break;
			}
			temp=temp->next;
		}
		if (find==0){
			return -1; //删除失败
		}
		else
		{
			//标记要删除的结点
			del=temp->next;
			//2、将目标结点从链表上摘除
			temp->next=temp->next->next;
			//3、释放目标结点
			free(del);
			return 1;
		}
	}
}

//在有头结点的链表中查找元素所在位置
int LinkGet1(Link *p, int elem){
	int i=1;
	//带头结点，p指向首元结点
	p=p->next;
	while(p){
		if (p->elem==elem){
			return i;
		}
		p=p->next;
		i++;
	}
	return -1; //返回-1，表示未找到
}


//在无头结点的链表中查找元素所在位置
int LinkGet2(Link *p, int elem){
	int i=1;
	while(p){
		if (p->elem==elem){
			return i;
		}
		p=p->next;
		i++;
	}
	return -1; //返回-1，表示未找到
}

//在含头结点的链表中替换元素
int LinkAmend1(Link *p, int old, int new){
	p=p->next;
	while (p){
		if(p->elem==old){
			p->elem=new;
			return 1;
		}
		p=p->next;
	}
	return -1;
}

//在无头结点的链表中替换元素
int LinkAmend2(Link *p, int old, int new){
	while (p){
		if(p->elem==old){
			p->elem=new;
			return 1;
		}
		p=p->next;
	}
	return -1;
}
