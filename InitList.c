#include <stdio.h> 
#include <stdlib.h> //标准函数库，malloc()，free()
#define MAXSIZE 5 //宏定义数组最大容量，全字母大写

//用一个结构体表示顺序表，全局
typedef struct{
	int *array; //定义一个名为array的长度不确定的动态数组
	int length; //记录当前顺序表的长度
	int size; //数组的长度 
}SqList; //将这个结构体命名为SqList,分号勿漏

//声明函数
void InitList(SqList *list);//勿漏分号
void ListPrint(SqList list);

int main(){
	int i;
	SqList list = {NULL, 0, 0}; //创建一个结构类型为SqList名为list的变量，并初始化
	InitList(&list); //调用函数，建立顺序表
	//向顺序表中添加{1, 2, 3, 4, 5}
	for (i=1;i<=MAXSIZE;i++){
		list.array[i-1]=i;
		list.length++;
	}  //此处没有分号
	printf("顺序表中存储的元素分别是：\n");
	ListPrint(list); //调用函数，打印顺序表
	free(list.array); //释放申请的内存
	return 0;
}

//定义函数InitList，作用：建立顺序表
//参数在函数内需要被改动，所以需要传递指向这个参数的指针
void InitList(SqList *list){
	//构造一个空的顺序表，动态申请存储空间
	list->array=(int *)malloc(MAXSIZE*sizeof(int));
	//如果申请失败，作出提示并直接退出程序
	if (!list->array){
		printf("初始化失败");
		exit(0); //正常退出
	}
	//空表的长度初始化为0
	list->length=0;
	//空表的初始存储空间为MAXSIZE
	list->size=MAXSIZE;
}

//定义函数ListPrint，打印顺序表中的元素
//参数在函数内不需要被改动，所以可以直接传递这个参数
void ListPrint(SqList list){
	int i;
	for (i = 0; i < list.length; i++){
		printf("%d ", list.array[i]);
	}
	printf("\n");
}

