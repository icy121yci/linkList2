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
//����˫������ β�巨 
Status BuildList_DuL(DuLinkedList *L,int num){
	int i; 
	DuLinkedList p,r;
	r=*L;//rΪβ��ָ�� 
	for (i=1;i<=num;i++){
		p=(DuLinkedList)malloc(sizeof(DuLNode));
		//pΪ�½��ָ�� 
		printf("�������%d������:\n",i) ;
		scanf("%d",&(p->data) );
		r->next =p;//ǰ�� 
		p->prior =r;
		r=p;		
	
	}
	r->next=NULL;
	return SUCCESS;
}
//ǰ�߲���
Status InsertBeforeList_DuL(DuLinkedList L, int num){
	DuLinkedList p,f,q;
	p=L;
	
	while(p->data !=num){
		p=p->next ;//�ҵ�����Ľ�� 
		if (!p){
			printf("û���������\n");
			return ERROR;
		} 
	}
	f=p->prior ;// ����Ľ���ǰһ�� 
	q=(DuLinkedList)malloc(sizeof(DuLNode));//qΪ�½ڵ�ָ�� 
	printf("������Ҫ���������\n");
	scanf("%d",&(q->data) );
	q->next =p;
	q->prior=f;
	f->next =q; 
	p->prior  =q;
	
	return SUCCESS;
}
//ɾ��
Status DeleteList_DuL(DuLinkedList L, int num){

	DuLinkedList p,q;
	p=L;
	
	while(p->data!=num){
		p=p->next ;	//�ҵ�ɾ���Ľ��
		if (!p){
			printf("û���������\n");
			return ERROR;
		} 	
	} 
	if(!(p->next)){
		p->prior->next=NULL;//Ҫɾ���һ���ڵ����⴦�� 
	}else{
		printf("�ɹ�ɾ�������ݣ�%d\n",p->data );
		p->next->prior =p->prior ;
		p->prior->next=p->next;
	}
	
	free(p);
	
	return SUCCESS;
} 
//��ӡ����
void TraverseList_DuL(DuLinkedList L){
	DuLinkedList p,q;
	p=L;
	
	if (L=NULL){
	
		printf("������û������\n");
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
//����
Status SearchList_DuL(DuLinkedList L,int num){
	
	if(L==NULL){
		printf("���󣡣�������û�����ݣ�\n");
		return ERROR;
	}
	
	
	while(L){
		L=L->next ;
		if(L->data==num) {
			printf("Ԫ��%d���ڣ�\n",L->data) ;
			return SUCCESS; 
		}
	}

	printf("��Ԫ�ز����ڣ�\n");	/*���������⣬������ݲ����ھͻ�ֱ���˳�����û�м���ѭ���˵�����֪��Ϊʲô*/ 

	return ERROR;	
} 
//����ɾ��
void DestroyList_DuL(DuLinkedList *L){
	DuLinkedList p; 
	
	if(L==NULL){
		printf("���󣡣�������û�����ݣ�\n");
		return;
	}
	
	while ((*L)){
		p=*L;
		*L=(*L)->next ;
		free(p);
	}
} 
//������ ˼·��ͷL��NULL�����м�ڵ�ǰ��ָ�뻻 /*��֪��Ϊʲô����*/ 
Status ReverseList_DuL(DuLinkedList L){
  
   DuLinkedList p,_a;
   
	p=L;
	L->next->prior =NULL;//�µ�β������
	
	while(!(p->next)){
		p=p->next ;//�ɵ�β��� ,ͷL��NULL��
	}
	 p->next =L;
	 L->next =p;
	
	
	while(!p){//�ڵ�ǰ��ָ�뻻 
		_a=p->prior;
		p->prior =p->next ;
		p->next =_a; 
		p=p->next ; 
	}
	
	return SUCCESS; 
} 
//��ֵ ˼·������ָ��һǰһ�����м��ߵ�һ���ĺ�=һ����ǰʱ��������ֵ 
Status MidList_DuL(DuLinkedList L){
	DuLinkedList r,f;
	r=L;
	f=L->next ;
	
	while(!(r->next)){
		r=r->next ;//β��� 
	}
	while(f!=r&&(f->next )){
		f=f->next ;
		r=r->prior; 
	}
	if(!(f->next)){
		printf("��ż�������ݣ�û���е�\n");
	}else{
		printf("��ֵΪ%d",f->data );
	}
	return SUCCESS; 
}
//ѭ��
Status CirList_DuL(DuLinkedList L){
	DuLinkedList r;
	r=L;
		while(!(r->next)){
		r=r->next ;//β��� 
	}
	printf("�ɻ���\n");
	r->next =L;
	L->prior=r; 
	 	
	return SUCCESS; 
}
//�ж�ѭ��
Status JudCirList_DuL(DuLinkedList L){
	DuLinkedList p;
	p=L->next;
	while(p){
		if(L==p ) {
			printf("�ɻ���\n"); 
			return SUCCESS; 
		}
		p=p->next ;
		
	}
	printf("δ�ɻ�\n");


	return SUCCESS; 	
} 
//����ż����ת
Status ReverseEvList_DuL(DuLinkedList L){
    DuLinkedList p,q;
    ElemType num;
    
	p=L->next;//ǰ 
	q=p->next ;//��
	while(q->next ){
		num=p->data;
		p->data =q->data ;
		q->data =num; 
		p=p->next ;
		q=q->next ;	
	} 
	return SUCCESS;	
} 
