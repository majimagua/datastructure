#ifndef _LINK_REVERSE_H
#define _LINK_REVERSE_H

//**********函数声明**********

Link *Iteration_Reverse1(Link *p);  //有头结点单链表，迭代反转法
Link *Iteration_Reverse2(Link *p);  //无头结点单链表，迭代反转法

Link *Recursive_Reverse2(Link *p);  //无头结点单链表，递归反转法

Link *Head_Reverse1(Link *p);  //有头结点单链表，头插法反转链表
Link *Head_Reverse2(Link *p);  //无头结点单链表，头插法反转链表

Link *Local_Reverse1(Link *p);  //有头结点单链表，就地反转法
Link *Local_Reverse2(Link *p);  //无头结点单链表，就地反转法


#endif
