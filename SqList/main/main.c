#include <stdio.h>
#include <stdlib.h> //malloc, realloc, free
#include "SqList.h"
#define MAXSIZE 5 //宏定义数组最大容量


//主函数
int main(void){
	//定义一个顺序表，名为L，初始化
	SqList L={NULL, 0, MAXSIZE}; //逗号隔开，不是分号
	//调用函数，创建顺序表
	InitList(&L);
	//写入元素
	for(int i=0; i<L.size; i++){
		L.array[i]=i+1;
		L.length++;
	}	
	//调用函数，打印顺序表
	ListPrint(L);
	printf("\n");

	//调用函数，在第三个位置插入元素6
	printf("在第三个位置插入元素6\n");
	ListInsert(&L, 3, 6);
				
	//调用函数，打印顺序表
	ListPrint(L);
	printf("\n");

	//调用函数，删除第6个元素
	printf("删除第6个元素\n");
	ListDelete(&L, 6);
	
	//调用函数，打印顺序表
	ListPrint(L);
	printf("\n");

	//调用函数，查找元素5所在位置
	printf("元素5所在位置:");
	int index = ListSelect(L, 5);
	if (index==-1){
		printf("查找的元素不存在\n\n");
	}
	else
	printf("%d\n", index);
	
	//调用函数，把元素1改成9
	printf("把元素1改成9\n");
	ListAmend(&L, 1, 9);

	//调用函数，打印顺序表
	ListPrint(L);
	printf("\n");


	//释放内存
	free(L.array);
	return 0;	
}






