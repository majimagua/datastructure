#include <stdio.h>
#include <stdlib.h>
#include "Link.h"

//**********函数定义**********

//***有头结点的单链表，迭代反转法***

Link *Iteration_Reverse1(Link *p){
	if(p==NULL || p->next==NULL){
		return p;
	}
	else{
		Link *bgn=NULL;
		Link *mid=p->next;
		Link *end=p->next->next;
		//一直遍历
		while(1){
			//修改mid所指结点的指向
			mid->next=bgn;
			//此时判断end是否为NULL，如果成立则退出循环
			if(end==NULL){
				break;
			}
			//整体向后移动3个指针
			bgn=mid;
			mid=end;
			end=end->next;
		}
		//最后修改头结点的指向
		p->next=mid;
		return p;
	}
}

//***无头结点单链表，迭代反转法***

Link *Iteration_Reverse2(Link *p){
	if(p==NULL || p->next==NULL){
		return p;
	}
	else{
		Link *bgn=NULL;
		Link *mid=p;
		Link *end=p->next;
		//一直遍历
		while(1){
			//修改mid所指结点的指向
			mid->next=bgn;
			//此时判断end是否为NULL，如果成立则退出循环
			if(end==NULL){
				break;
			}
			//整体向后移动3个指针
			bgn=mid;
			mid=end;
			end=end->next;
		}
		//最后修改头指针的指向
		p=mid;
		return p;
	}
}



//***无头结点单链表，递归反转法***

Link *Recursive_Reverse2(Link *p){
	//递归的出口
	if(p==NULL || p->next==NULL){
		return p;
	} //空链或只有一个结点，直接返回头指针
	else{
		//一直递归，找到链表中最后一个结点
		Link *new_p=Recursive_Reverse2(p->next);
		//当逐层退出时，new_p的指向都不变，一直指向原链表中最后一个结点
		//递归每退出一层，函数中p指针的指向都会发生改变，都指向上一个结点
		//每退出一层，都需要改变p->next结点指针域的指向，同时令p所指向结点的指针域为NULL
		p->next->next=p;
		p->next=NULL;
		//每一层递归结束，都要将新的头指针返回给上一层。由此，即可保证整个递归过程中，能够一直找得到新链表的表头
		return new_p;
	}
}


//***有头结点单链表，头插法反转链表***

Link *Head_Reverse1(Link *p){
	Link *new_p=NULL;
	Link *temp=NULL;
	if(p==NULL || p->next==NULL){
		return p;
	}
	temp=p;
	//将头结点从p中摘除
	p=p->next;
	//将头结点插入new_p后面
	temp->next=new_p;
	new_p=temp;
	//从首元结点开始摘除，放置在头结点后面
	while(p!=NULL){
		temp=p;
		//将temp从p中摘除
		p=p->next;
		//将temp插入到new_p头结点的后面
		temp->next=new_p->next;
		new_p->next=temp;
	}
	return new_p;

}


//***无头结点单链表，头插法发转链表***

Link *Head_Reverse2(Link *p){
	Link *new_p=NULL;
	Link *temp=NULL;
	if(p==NULL || p->next==NULL){
		return p;
	}
	while(p!=NULL){
		temp=p;
		//将temp从p中摘除
		p=p->next;
		//将temp插入到new_p的头部
		temp->next=new_p;
		new_p=temp;
	}
	return new_p;

}


//***有头结点单链表，就地反转法

Link *Local_Reverse1(Link *p){
	Link *bgn=NULL;
	Link *end=NULL;
	if(p==NULL || p->next==NULL){
		return p;
	}
	bgn=p->next;
	end=p->next->next;
	while(end!=NULL){
		//将end从链表中摘除
		bgn->next=end->next;
		//将end移动至链表头结点后
		end->next=p->next;
		p->next=end;
		//调整end的指向，令其指向bgn后的一个结点，为反转下一个结点做准备
		end=bgn->next;
	}
	return p;
}


//***无头结点单链表，就地反转法

Link *Local_Reverse2(Link *p){
	Link *bgn=NULL;
	Link *end=NULL;
	if(p==NULL || p->next==NULL){
		return p;
	}
	bgn=p;
	end=p->next;
	while(end!=NULL){
		//将end从链表中摘除
		bgn->next=end->next;
		//将end移动至链表头
		end->next=p;
		p=end;
		//调整end的指向，令其指向bgn后的一个结点，为反转下一个结点做准备
		end=bgn->next;
	}
	return p;
}


