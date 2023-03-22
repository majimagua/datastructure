#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

//创建结构体表示顺序表
typedef struct SqList{
	int *array;
	int length; //顺序表长度
	int size; //数组容量
}SqList; //分号

//函数声明
void InitList(SqList *list); //创建顺序表，分号
void ListPrint(SqList list); //打印顺序表，分号

//主函数
int main(void){
	SqList L={NULL, 0, 0};
	InitList(&L); //创建顺序表
	printf("打印顺序表如下： \n");
	ListPrint(L); //打印顺序表
	free(L.array); //释放申请的内存空间

	return 0;
}

//函数定义，创建顺序表
void InitList(SqList *list){
	list->array=(int *)malloc(MAXSIZE*sizeof(int)); //为数组分配动态内存
	//内存分配失败，则作出提示并退出
	if(!list->array){
		printf("内存初始化失败！\n");
		exit(0);
	}
	list->size=MAXSIZE;
	for(int i=0; i<MAXSIZE; i++ ){
		list->array[i]=i+1;
		list->length++;
	}
}

//函数定义，打印顺序表
void ListPrint(SqList list){
	for(int i=0; i<list.length; i++){
	printf("%d ", list.array[i]);
	}
	printf("\n");
}

