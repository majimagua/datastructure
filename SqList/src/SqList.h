#ifndef _SQLIST_H
#define _SQLIST_H

//创建结构体表示顺序表
typedef struct SqList{
	int *array;
	int length; //顺序表长度
	int size; //数组容量
}SqList; //分号

//函数声明
void InitList(SqList *list); //创建空的顺序表，分号
void ListPrint(SqList list); //打印顺序表，分号
void ListInsert(SqList *list, int add, int elem);  //插入元素，分号
void ListDelete(SqList *list, int dele); //删除元素，分号
int ListSelect(SqList list, int elem); //查找目标元素所在位置
void ListAmend(SqList *list, int elem, int newelem); //更改目标元素

#endif
