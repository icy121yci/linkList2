#include "dulinkedlist.h" 

# include <stdio.h>

int main(){
	int cho;
	int flag;
	int flag_2=1;
	DuLinkedList L=NULL;
	
	while(flag_2){

		printf("*****************ϵͳ���ܲ˵�******************\n");
		printf("-----------------------------------------------\n");//
		printf("***********************************************\n");
		printf("*  1.����������       * *    2.�����½ڵ�     *\n");
		printf("***********************************************\n");
		printf("*  3.�������         * *    4.��������     *\n");
		printf("***********************************************\n");//
		printf("*  5.�ҵ��������е�   * *    6.�ж��Ƿ�ɻ�   *\n");
		printf("***********************************************\n");//
		printf("*  7.ɾ���ڵ�ȡֵ     * *    8.��ż��ת       *\n");
		printf("***********************************************\n");//
		printf("*              9.��ѯ�����Ƿ��ڱ���           *\n");
		printf("***********************************************\n");
		printf("*                 10.����ѭ������             *\n");
		printf("***********************************************\n");
		printf("*              0.ɾ�������˳�ϵͳ           *\n");
		printf("***********************************************\n");
		printf("��ѡ��:" );
		scanf("%d",&cho);
		switch(cho){
	
			case 0:
				DestroyList_DuL(&L);
				flag_2=0;
				break;
			case 1:
				InitList_DuL(&L);
				printf("�������������б��м������ݣ�\n");
				scanf("%d",&flag);
			BuildList_DuL(&L,flag);				
				break;
			case 2:
				printf("�����������ĸ�����ǰ�����أ�\n");
				scanf("%d",&flag);
				InsertBeforeList_DuL(L, flag);
				break;
			case 3:
				TraverseList_DuL(L);
				break;
			case 4:
				/*ReverseList_DuL(L) ;
				TraverseList_DuL(L); */
				printf("д�˴��벻֪��Ϊʲô���� \n") ;
				break;
			case 5:
				/*MidList_DuL(L);*/
				printf("д�˴��벻֪��Ϊʲô���� \n") ;
				break;
			case 6:
				JudCirList_DuL(L);
				break;
			case 7:
				printf ("��ϣ��ɾ���ĸ������أ�\n");
				scanf("%d",&flag);
				DeleteList_DuL(L, flag);
				break;	 
			case 8:
				printf ("��ǰ\n");
				TraverseList_DuL(L);
				ReverseEvList_DuL(L);
				printf ("�ĺ�\n");
				TraverseList_DuL(L);
				break;	 
			case 9:
				printf ("��ϣ������ʲôԪ���أ�\n");
				scanf("%d",&flag) ;/*���������⣬������ݲ����ھͻ�ֱ���˳�����û�м���ѭ���˵�����֪��Ϊʲô*/ 
				flag=SearchList_DuL( L,flag);
				printf("%d",flag);
				break;
			case 10:				
    			CirList_DuL(L);
				break;
			default :printf("������0-10������\n");
		}
	}
	return 0;
} 
