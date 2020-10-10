#include"contact.h"

void menu(void)
{
	printf("***************************************************\n");
	printf("**************     ����һ��ͨѶ¼    **************\n");
	printf("**************   1.add     2.delete  **************\n");
	printf("**************   3.search  4.modify  **************\n");
	printf("**************   5.show    6.empty   **************\n");
	printf("**************   7.sort    0.exit    **************\n");
	printf("***************************************************\n");
}
int main()
{
	int choose = 0;
	Contact con;
	init_contact(&con);
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &choose);
		switch (choose)
		{
		case EXIT:
			printf("�˳��ɹ���\n");
			break;
		case ADD:
			add(&con);
			break;
		case DELETE:
			delete(&con);
			break;
		case SEARCH:
			search(&con);
			break;
		case MODIFY:
			modify(&con);
			break;
		case SHOW:
			show(&con);
			break;
		case EMPTY:
			empty(&con);
			break;
		case SORT:   
			sort(&con);
			break;
		default:
			printf("�����������������!\n");
			break;
		}
	} while (choose);
	return 0;
}