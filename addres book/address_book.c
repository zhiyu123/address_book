#include"contact.h"

void menu(void)
{
	printf("***************************************************\n");
	printf("**************     这是一个通讯录    **************\n");
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
		printf("请选择：");
		scanf("%d", &choose);
		switch (choose)
		{
		case EXIT:
			printf("退出成功！\n");
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
			printf("输入错误，请重新输入!\n");
			break;
		}
	} while (choose);
	return 0;
}