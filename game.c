#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void GameConfig()
{
	int choice = 0;
	while(1)
	{
		
		printf(lightgreen"1.Easy (9x9  10)\n");
		printf(lightyellow"2.Normal (16x16  40)\n");
		printf(red"3.Hard (16x30  99)\n");
		printf(purred"4.User-Define (?x?  ??)\n"recolor);
		printf("��ѡ��:> ");
	again:
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			DisROW = 9; DisCOL = 9; MineNum = 10;
			ROW = DisROW + 2; COL = DisCOL + 2; break;
		case 2:
			DisROW = 16; DisCOL = 16; MineNum = 40; 
			ROW = DisROW + 2; COL = DisCOL + 2; break;
		case 3:
			DisROW = 16; DisCOL = 30; MineNum = 99; 
			ROW = DisROW + 2; COL = DisCOL + 2; break;
		case 4: 
			printf("����������С�������������50��(��15 15)\n");
			scanf("%d %d", &DisROW, &DisCOL);
			ROW = DisROW + 2;
			COL = DisCOL + 2;
			while (getchar() != '\n');
			printf("�������׵�������\n");
			scanf("%d", &MineNum);
			while (getchar() != '\n');
			break;
		default:while (getchar() != '\n'); printf("�Ƿ����룡������ѡ��:> "); goto again;
		}
		break;
	}
}

void InitBoard(char arr[MROW][MCOL], int row, int col, char set)
{
	for (int i = 0; i < row;i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = set;
		}
	}
}
void DisInterface(char arr[MROW][MCOL], int row, int col)
{
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	for (int i = 0; i <=col; i++)
	{
		printf(green"%2d ", i);
	}
	printf(recolor"\n");
	for (int i = 1; i <=row; i++)
	{
		printf(green"%2d ", i);
		for (int j = 1; j<= col; j++)
		{
			if (arr[i][j] == Face)
				printf(purred" %c ", arr[i][j]);//��ӡδ�������
			else if (arr[i][j] == '0')
				printf(lightblack" %c ", arr[i][j]);//��ӡ��0������
			else if (arr[i][j] == '1')
				printf(red" %c ", arr[i][j]);//��ӡ��Χ����.......
			else if (arr[i][j] == '2')
				printf(cyan" %c ", arr[i][j]);
			else if (arr[i][j] == '3')
				printf(yellow" %c ", arr[i][j]);
			else if (arr[i][j] == '4')
				printf(blue" %c ", arr[i][j]);
			else if (arr[i][j] == '5')
				printf(lightred" %c ", arr[i][j]);
			else if (arr[i][j] == '6')
				printf(lightgreen " %c ", arr[i][j]);
			else if (arr[i][j] == '7')
				printf(cyan" %c ", arr[i][j]);
			else
				printf(red" %c ", arr[i][j]);
		}
		printf(recolor"\n");
	}
	printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}
void SetMine(char arr[MROW][MCOL], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = MineNum;
	while (count)
	{
		i = RandMaxMin(DisROW, 1);
		j = RandMaxMin(DisCOL, 1);
		if (arr[i][j] == '0')
		{
			arr[i][j] = '1';
			count--;
		}
	}
}
void GetMine(char show[MROW][MCOL], char mine[MROW][MCOL], int row, int col)
{
	printf(red"tip:���������������У��Կո����\n"recolor);
	while (1)
	{
		int ret = IsWin(show, DisROW, DisCOL);
		if (ret <= MineNum)
		{
			printf("������ʤ�������˲��𣡱�����ʵ��̫����ɨ������Ϸ...\n\n");
			break;
		}
		printf("��������������:> ");
		int i = 0, j = 0;
		scanf("%d %d", &i, &j);
		if (show[i][j] != Face)
		{
			printf("���������ظ�����Ч���꣡\n");
			continue;
		}
		if (i < 1 || i > 9 || j < 1 || j > 9)
		{
			printf("����Ƿ����������룡\n");
			while (getchar() != '\n');
			continue;
		}
		if (mine[i][j] == '1')
		{
			DisInterface(mine, DisROW, DisCOL);
			printf("���ź�...��ը����...\n");
			break;
		}
		else
		{
			int count = MineCount(mine, i, j);
			//printf("DEBUG:)
			if (count > 0)
			{
				show[i][j] = count + '0';
			}
			else if (count == 0)
			{
				//printf("DEBUG: It's ZERO")
				BlankDiffusion(show,mine, i, j);
			}
			DisInterface(show, DisROW, DisCOL);
		}
	}
}