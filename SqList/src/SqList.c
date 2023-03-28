#include <stdio.h>
#include <stdlib.h> //malloc, realloc, free

//创建结构体表示顺序表
typedef struct SqList{
    int *array;
    int length; //顺序表长度
    int size; //数组容量
}SqList; //分号

//函数定义

//创建空白顺序表
void InitList(SqList *list){
	//分配内存空间
	list->array=(int *)malloc(list->size*sizeof(int));
	//判断内存分配是否成功，失败则提示并正常退出
	if(!list->array){
		printf("内存分配失败！\n");
		exit(0);
	}

}

//打印顺序表
void ListPrint(SqList list){
	printf("打印顺序表如下：\n");
	for(int i=0; i<list.length; i++){
		printf("%d ", list.array[i]);
	}
	printf("\n");
}

//插入元素
//add为要插入元素的位置，elem为要插入的元素的值
void ListInsert(SqList *list, int add, int elem){
	//判断位置是否合理
	if(add<1 || add>list->length+1){
		printf("插入位置有问题\n");
		return;				
	}
	//判断是否有剩余空间，无则重新分配空间
	if(list->length==list->size){
		list->array=(int *)realloc(list->array, (list->length+1)*sizeof(int));
		if(!list->array){
			printf("内存分配失败");
			return;
		}
	}
	//插入的位置及其后的元素后移
	for(int i=list->length-1; i>=(add-1); i--){
		list->array[i+1]=list->array[i];
	}
	//插入元素，顺序表长度增加	
	list->array[add-1]=elem;
	list->length++;
}

//删除元素
void ListDelete(SqList *list, int dele){
	//判断删除位置是否合理
	if(dele<1 || dele>list->length){
		printf("删除位置有问题\n");
		return;	
	}
	//删除位置后面的元素往前移
	for(int i=dele; i<list->length; i++){
		list->array[i-1]=list->array[i];
	}
	//顺序表长度减一
	list->length--;
}

//查找元素所在位置
int ListSelect(SqList list, int elem){
	//顺序查找算法
	for (int i=0; i<list.length; i++){
		if(list.array[i]==elem){
			return i+1;		
		}			
	return -1; //如果查找失败，返回-1
	}
}

//更改元素值
void ListAmend(SqList *list, int elem, int newelem){
	//查找元素所在位置
	int index=ListSelect(*list, elem);
	//判断所找元素是否存在
	if (index==-1){
		printf("顺序表中没有找到目标元素\n");
		return;
	}
	list->array[index-1]=newelem;
}
