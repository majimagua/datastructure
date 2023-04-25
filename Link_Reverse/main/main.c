#include <stdio.h>
#include <stdlib.h>
#include "Link.h"
#include "Link_Reverse.h"

//**********主调函数***********
int main(){
	//*****有头结点的单链表*****
	Link *p1=NULL;
	p1=InitLink1(5);
	LinkPrint(p1);
	printf("迭代法反转链表\n");
	p1=Iteration_Reverse1(p1);
	LinkPrint(p1);
	printf("头插法反转链表\n");
	p1=Head_Reverse1(p1);
	LinkPrint(p1);
	printf("就地反转法反转链表\n");
	p1=Local_Reverse1(p1);
	LinkPrint(p1);


	printf("\n\n");
	//*****无头结点的单链表*****
	Link *p2=NULL;
	p2=InitLink2(5);
	LinkPrint(p2);
	printf("迭代法反转链表\n");
	p2=Iteration_Reverse2(p2);
	LinkPrint(p2);
	printf("头插法反转链表\n");
	p2=Head_Reverse2(p2);
	LinkPrint(p2);
	printf("就地反转法反转链表\n");
	p2=Local_Reverse2(p2);
	LinkPrint(p2);
	printf("递归反转法\n");
	p2=Recursive_Reverse2(p2);
	LinkPrint(p2);


	//释放链表
	LinkFree(p1);
	LinkFree(p2);
}

