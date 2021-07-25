#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include "game.h"

void menu()
{
	printf("**********************\n");
	printf("*****1.play 2.exit****\n");
	printf("**********************\n");
}

void game()
{
	char ret;
	char board[ROW][COL];
	InitBoard(board, ROW, COL);
	DisplayBoard(board,ROW,COL);
	while (1)
	{
		Playermove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		 ret=Iswin(board, ROW, COL);
		 if (ret != 'C')
		 {
			 break;
		 }
		Computermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret=Iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
		printf("���Ӯ \n");
	else if (ret == '#')
		printf("����Ӯ\n");
	else if(ret == 'Q')
		printf("ƽ��\n");
}
void test()
{
	int a;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ���Ƿ������Ϸ\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("����������\n");
			game();
			break;
		case 2:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (a != 2);
}

	int main()
	{
		test();
		return 0;
	}