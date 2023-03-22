#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

//结构体表示顺序表
typedef struct SqList{
	int *array;
	int length;
	int size;
}SqList;

//函数声明
void InitList(SqList *list); //创建顺序表
void ListPrint(SqList list); //打印顺序表

//主函数
int main(void){
	SqList L={NULL, 0, 0};
	InitList(&L);
	printf("打印顺序表如下: \n");
	ListPrint(L);
	free(L.array); //释放申请的内存
	return 0;
}

//创建顺序表，定义函数
void InitList(SqList *list){
	list->array=(int *)malloc(MAXSIZE*sizeof(int)); //为数组分配动态内存
	//如果申请失败，则作出提示并正常退出程序
	if(!list->array){
		printf("初始化失败");
		exit(0);	
	}
	list->size=MAXSIZE;
	for(int i=1; i<=MAXSIZE; i++ ){
		list->array[i-1]=i;
		list->length++;
	}
}

//打印顺序表，定义函数
void ListPrint(SqList list){
	for(int i=0; i<list.length; i++){
		printf("%d ", list.array[i]);
	}
	printf("\n");
}
