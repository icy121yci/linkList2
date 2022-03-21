#include "dulinkedlist.h" 
# include <stdio.h>
#include <stdlib.h> 

Status InitList_DuL(DuLinkedList *L){
	*L=(DuLinkedList)malloc(sizeof(DuLNode));
	if(!(*L))
		return 	ERROR;
	
	(*L)->prior=NULL;
	(*L)->next=NULL; 
	
	return SUCCESS;
}
//创建双向链表 尾插法 
Status BuildList_DuL(DuLinkedList *L,int num){
	int i; 
	DuLinkedList p,r;
	r=*L;//r为尾部指针 
	for (i=1;i<=num;i++){
		p=(DuLinkedList)malloc(sizeof(DuLNode));
		//p为新结点指针 
		printf("请输入第%d个数据:\n",i) ;
		scanf("%d",&(p->data) );
		r->next =p;//前后 
		p->prior =r;
		r=p;		
	
	}
	r->next=NULL;
	return SUCCESS;
}
//前边插入
Status InsertBeforeList_DuL(DuLinkedList L, int num){
	DuLinkedList p,f,q;
	p=L;
	
	while(p->data !=num){
		p=p->next ;//找到插入的结点 
		if (!p){
			printf("没有这个数据\n");
			return ERROR;
		} 
	}
	f=p->prior ;// 插入的结点的前一个 
	q=(DuLinkedList)malloc(sizeof(DuLNode));//q为新节点指针 
	printf("请输入要插入的数：\n");
	scanf("%d",&(q->data) );
	q->next =p;
	q->prior=f;
	f->next =q; 
	p->prior  =q;
	
	return SUCCESS;
}
//删除
Status DeleteList_DuL(DuLinkedList L, int num){

	DuLinkedList p,q;
	p=L;
	
	while(p->data!=num){
		p=p->next ;	//找到删除的结点
		if (!p){
			printf("没有这个数据\n");
			return ERROR;
		} 	
	} 
	if(!(p->next)){
		p->prior->next=NULL;//要删最后一个节点特殊处理 
	}else{
		printf("成功删除了数据：%d\n",p->data );
		p->next->prior =p->prior ;
		p->prior->next=p->next;
	}
	
	free(p);
	
	return SUCCESS;
} 
//打印整表
void TraverseList_DuL(DuLinkedList L){
	DuLinkedList p,q;
	p=L;
	
	if (L=NULL){
	
		printf("空链表，没有数据\n");
		return;
		}
	while(p){
		p=p->next;
		if(p==NULL)
			break;
		printf("%d->",p->data );
		
		
	}
	printf("NULL\n");
} 
//查找
Status SearchList_DuL(DuLinkedList L,int num){
	
	if(L==NULL){
		printf("错误！（空链表，没有数据）\n");
		return ERROR;
	}
	
	
	while(L){
		L=L->next ;
		if(L->data==num) {
			printf("元素%d存在！\n",L->data) ;
			return SUCCESS; 
		}
	}

	printf("该元素不存在！\n");	/*这里有问题，如果数据不存在就会直接退出程序，没有继续循环菜单，不知道为什么*/ 

	return ERROR;	
} 
//整表删除
void DestroyList_DuL(DuLinkedList *L){
	DuLinkedList p; 
	
	if(L==NULL){
		printf("错误！（空链表，没有数据）\n");
		return;
	}
	
	while ((*L)){
		p=*L;
		*L=(*L)->next ;
		free(p);
	}
} 
//反向倒序 思路：头L与NULL换，中间节点前后指针换 /*不知道为什么不行*/ 
Status ReverseList_DuL(DuLinkedList L){
  
   DuLinkedList p,_a;
   
	p=L;
	L->next->prior =NULL;//新的尾部处理
	
	while(!(p->next)){
		p=p->next ;//旧的尾结点 ,头L与NULL换
	}
	 p->next =L;
	 L->next =p;
	
	
	while(!p){//节点前后指针换 
		_a=p->prior;
		p->prior =p->next ;
		p->next =_a; 
		p=p->next ; 
	}
	
	return SUCCESS; 
} 
//中值 思路：两个指针一前一后往中间走当一个的后=一个的前时，就是中值 
Status MidList_DuL(DuLinkedList L){
	DuLinkedList r,f;
	r=L;
	f=L->next ;
	
	while(!(r->next)){
		r=r->next ;//尾结点 
	}
	while(f!=r&&(f->next )){
		f=f->next ;
		r=r->prior; 
	}
	if(!(f->next)){
		printf("有偶数个数据，没有中点\n");
	}else{
		printf("中值为%d",f->data );
	}
	return SUCCESS; 
}
//循环
Status CirList_DuL(DuLinkedList L){
	DuLinkedList r;
	r=L;
		while(!(r->next)){
		r=r->next ;//尾结点 
	}
	printf("成环了\n");
	r->next =L;
	L->prior=r; 
	 	
	return SUCCESS; 
}
//判断循环
Status JudCirList_DuL(DuLinkedList L){
	DuLinkedList p;
	p=L->next;
	while(p){
		if(L==p ) {
			printf("成环了\n"); 
			return SUCCESS; 
		}
		p=p->next ;
		
	}
	printf("未成环\n");


	return SUCCESS; 	
} 
//奇数偶数翻转
Status ReverseEvList_DuL(DuLinkedList L){
    DuLinkedList p,q;
    ElemType num;
    
	p=L->next;//前 
	q=p->next ;//后
	while(q->next ){
		num=p->data;
		p->data =q->data ;
		q->data =num; 
		p=p->next ;
		q=q->next ;	
	} 
	return SUCCESS;	
} 
