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
		printf("玩家赢 \n");
	else if (ret == '#')
		printf("电脑赢\n");
	else if(ret == 'Q')
		printf("平局\n");
}
void test()
{
	int a;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择是否进入游戏\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("进入三子棋\n");
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (a != 2);
}

	int main()
	{
		test();
		return 0;
	}