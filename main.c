#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|\n");
	printf("�|�|�|�|�|�|�|�|�| 1.play �|�|�|�|�|�|�|�|�|\n");
	printf("�|�|�|�|�|�|�|�|�| 0.exit �|�|�|�|�|�|�|�|�|\n");
	printf("�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|�|\n");
	printf("��ѡ��:> ");
}
void game()
{
	char ret = 0;
	char table[ROW][COL] = { 0 };
	init_table(table,ROW,COL);
	display_table(table, ROW, COL);
	while (1)
	{
		PlayerMove(table, ROW, COL);
		display_table(table, ROW, COL);
		ret =IsWin(table,ROW,COL);
		if (ret != 'C')
		{
			if (ret != 'E')
			{
				printf("��һ�ʤ��\n");
				break;
			}
			else
			{
				printf("ƽ�֣�\n");
				break;
			}
		}
		ComputerMove(table,ROW,COL);
		display_table(table, ROW, COL);
		ret = IsWin(table, ROW, COL);
		if (ret != 'C')
		{
			if (ret != 'E')
			{
				printf("���Ի�ʤ����������AI��ô���???)\n");
				break;
			}
			else
			{
				printf("ƽ�֣�\n");
				break;
			}
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������������\n");
			printf("���Ͻ�Ϊ����ԭ�㣺1 1 (�� �У�\n");
			goto game;
		case 0:
			printf("�˳���Ϸ...\n");
			goto quit;
		default:
			printf("��������ȷ����\n");
			break;
		}
	} while (input);
game:
	game();
	printf("��Ϸ������\n");
	printf("�Ƿ�����һ�֣�(�� 1/�� 0) :> ");
	int again = 0;
	scanf("%d", &again);
	while (1)
	{
		switch (again)
		{
		case 1:
			goto game;
			break;
		case 0:
			goto quit;
			break;
		default:
			printf("����ȷ���룡");
			break;
		}
	}
quit:
	return 0;
}