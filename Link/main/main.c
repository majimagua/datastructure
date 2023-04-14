#include <stdio.h>
#include <stdlib.h>
#include "Link.h"


//*********主调函数**********
int main(){
	
	//*********有头结点的链表***********

    printf("\n**********有头结点的链表**********\n");
	printf("\n");
	Link* p1=NULL;
	printf("初始化含头结点的链表为：\n");
	//创建含头结点的链表{1,2,3,4}
	p1=InitLink1();
	//输出链表中的数据
	LinkPrint(p1);
	
	//向含头结点的链表插入元素5
	printf("\n向含头结点的链表（位置为6）插入元素5\n");
	LinkInsert1(p1, 6, 5);
	//输出链表中的数据
	LinkPrint(p1);
	
	//从含头结点的链表中删掉元素1
	printf("\n从含头结点的链表中删掉元素1\n");
	LinkDelete1(p1, 1);
	//输出链表中的数据
	LinkPrint(p1);

	//从含头结点的链表中查找元素3
	printf("\n从含头结点的链表中查找元素3\n");
	int a1=LinkGet1(p1, 3);
	if (a1==-1){
		printf("查找的元素不存在\n");
	}
	else
	{
		printf("元素3的位置为：%d\n", a1);
	}

	//从含头结点的链表中替换元素6为7
	printf("\n从含头结点的链表中替换元素6为7\n");
	int b1=LinkAmend1(p1, 6, 7);
	if (b1==-1) {
		printf("替换的元素不存在\n");
	}
	else
	{
		//输出链表中的数据
		LinkPrint(p1);
	}

	
	//间隔
	printf("\n\n");

	//*********无头结点的链表************

	printf("\n**********无头结点的链表**********\n");
	printf("\n");
	Link* p2=NULL;
	printf("初始化无头结点的链表为：\n");
	//创建无头结点的链表{1,2,3,4}
	p2=InitLink2();
	//输出链表中的数据
	LinkPrint(p2);
	
	//向无头结点的链表插入元素5
	printf("\n向无头结点的链表（位置为1）插入元素5\n");
	p2=LinkInsert2(p2, 1, 5);
	//输出链表中的数据
	LinkPrint(p2);

	//从无头结点的链表中删除元素5
	printf("\n从无头结点的链表中删除元素5\n");
	LinkDelete2(&p2, 5);
	//输出链表中的数据
	LinkPrint(p2);

	//从无头结点的链表中查找元素3
	printf("\n从无头结点的链表中查找元素3\n");
	int a2=LinkGet2(p2, 3);
	if (a2==-1){
		printf("查找的元素不存在\n");
	}
	else
	{
		printf("元素3的位置为：%d\n", a2);
	}

	//从无头结点的链表中替换元素4为7
	printf("\n从无头结点的链表中替换元素4为7\n");
	int b2=LinkAmend2(p2, 4, 7);
	if (b2==-1) {
		printf("替换的元素不存在\n");
	}
	else
	{
		//输出链表中的数据
		LinkPrint(p2);
	}


	//释放链表
	LinkFree(p1);
	LinkFree(p2);

	return 0;
}




