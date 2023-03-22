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
void ListInsert(SqList *list, int add, int elem); //顺序表插入元素，分号
//主函数
int main(void){
	SqList L={NULL, 0, 0};
	InitList(&L); //创建顺序表
	printf("打印顺序表如下： \n");
	ListPrint(L); //打印顺序表

	//在第3位插入元素6
	ListInsert(&L, 3, 6);
	printf("插入元素后，打印顺序表如下：\n");
	ListPrint(L);

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

//函数定义，顺序表插入元素
//elem为要插入的元素，add为要插入到顺序表的位置
void ListInsert(SqList *list, int add, int elem){
	//判断插入位置是否合理。如果插入元素位置比整张表的长度+1还大（如果相等，是尾随的情况），或者插入的位置本身不存在，程序作出提示并自动退出
	if(add > list->length+1 || add<1){
		printf("插入位置有问题\n");
		return;
	}
	//判断空间是否足够。做插入操作时，首先需要看顺序表是否有多余的存储空间提供给插入的元素，如果没有，需要申请
	if(list->length+1 > list->size){
		list->array=(int *)realloc(list->array, (list->size+1)*sizeof(int));
		if(!list->array){
			printf("重新分配内存失败\n");
			return;	
		}
		list->size++;
	}
	//插入操作，需要将自插入位置之后的所有元素全部后移以为
	for(int i=list->length-1; i>=add-1; i--){
		list->array[i+1]=list->array[i];
	}
	//后移完成后，直接插入元素
	list->array[add-1]=elem;
	list->length++;

}
