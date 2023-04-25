#ifndef _LINK_H
#define _LINK_H

//用结构体表示链表中的结点
typedef struct link{
	int elem; //数据域
	struct link *next; //指针域
}Link;


//*******函数声明**********

Link* InitLink1(); //创建含头结点的链表
Link *InitLink2(); //创建不含头结点的链表

void LinkInsert1(Link *p, int add, int elem); //向含头结点的链表插入元素
Link *LinkInsert2(Link *p, int add, int elem); //向无头结点的链表插入元素

int LinkDelete1(Link *p, int elem); //从含头结点的链表删除元素
int LinkDelete2(Link **p, int elem); //从无头结点的链表删除元素

int LinkGet1(Link *p, int elem); //在含头结点的链表中查找元素所在位置
int LinkGet2(Link *p, int elem); //在无头结点的链表中查找元素所在位置

int LinkAmend1(Link *p, int old, int new); //在含头结点的链表中替换元素
int LinkAmend2(Link *p, int old, int new); //在无头结点的链表中替换元素

void LinkPrint(Link* p);  //打印链表中的数据
void LinkFree(Link *p); //释放链表

#endif
