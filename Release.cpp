#include "dulinkedlist.h" 

# include <stdio.h>

int main(){
	int cho;
	int flag;
	int flag_2=1;
	DuLinkedList L=NULL;
	
	while(flag_2){

		printf("*****************系统功能菜单******************\n");
		printf("-----------------------------------------------\n");//
		printf("***********************************************\n");
		printf("*  1.创建新链表       * *    2.插入新节点     *\n");
		printf("***********************************************\n");
		printf("*  3.输出链表         * *    4.将链表反向     *\n");
		printf("***********************************************\n");//
		printf("*  5.找到单链表中点   * *    6.判断是否成环   *\n");
		printf("***********************************************\n");//
		printf("*  7.删除节点取值     * *    8.奇偶反转       *\n");
		printf("***********************************************\n");//
		printf("*              9.查询数据是否在表中           *\n");
		printf("***********************************************\n");
		printf("*                 10.构造循环链表             *\n");
		printf("***********************************************\n");
		printf("*              0.删除链表并退出系统           *\n");
		printf("***********************************************\n");
		printf("请选择:" );
		scanf("%d",&cho);
		switch(cho){
	
			case 0:
				DestroyList_DuL(&L);
				flag_2=0;
				break;
			case 1:
				InitList_DuL(&L);
				printf("请问您创建的列表有几个数据？\n");
				scanf("%d",&flag);
			BuildList_DuL(&L,flag);				
				break;
			case 2:
				printf("请问你想在哪个数据前插入呢？\n");
				scanf("%d",&flag);
				InsertBeforeList_DuL(L, flag);
				break;
			case 3:
				TraverseList_DuL(L);
				break;
			case 4:
				/*ReverseList_DuL(L) ;
				TraverseList_DuL(L); */
				printf("写了代码不知道为什么不行 \n") ;
				break;
			case 5:
				/*MidList_DuL(L);*/
				printf("写了代码不知道为什么不行 \n") ;
				break;
			case 6:
				JudCirList_DuL(L);
				break;
			case 7:
				printf ("您希望删除哪个数据呢？\n");
				scanf("%d",&flag);
				DeleteList_DuL(L, flag);
				break;	 
			case 8:
				printf ("改前\n");
				TraverseList_DuL(L);
				ReverseEvList_DuL(L);
				printf ("改后\n");
				TraverseList_DuL(L);
				break;	 
			case 9:
				printf ("您希望查找什么元素呢？\n");
				scanf("%d",&flag) ;/*这里有问题，如果数据不存在就会直接退出程序，没有继续循环菜单，不知道为什么*/ 
				flag=SearchList_DuL( L,flag);
				printf("%d",flag);
				break;
			case 10:				
    			CirList_DuL(L);
				break;
			default :printf("请输入0-10的数字\n");
		}
	}
	return 0;
} 
