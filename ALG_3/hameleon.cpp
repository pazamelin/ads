#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>   
#include <queue> 
using namespace std;
#define dim 3
//#include "queue.h"
typedef struct Node
{
	int x;
	int y;
}NODE;

queue<NODE> myQueue;


string strData = "HMELEOAN ";
string strParagon = "HAMELEON";
char board[3][3] = { '0' };
char boardParagon[3][3] = { '0' };
int dX[4] = { -1, +0, +0, +1 };
int dY[4] = { +0, -1, +1, +0 };

void PrintBoard(char(*board)[dim])
{
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			std::cout << "" << board[i][j];
		std::cout<<"\n";
	}

}
bool isEqual(char(*board)[dim], char(*boardParagon)[dim])
{
	int i = 0, j = 0;
	bool isTrue = true;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (board[i][j] != boardParagon[i][j])
				isTrue = false;
	return isTrue;
}
void HBFS(char board[dim][dim], NODE* curEmptyCell, int entr)
{
	int x = curEmptyCell->x;
	int y = curEmptyCell->y;
	int k = 0;
	int next_x = 0;
	int next_y = 0;
	if (isEqual(board,boardParagon))
	{
		printf("!");
	}
	else
	{
		for (k = 0; k < 4; k++)
		{
			next_x = x + dX[k];
			next_y = y + dY[k];
			if ((next_x < 0) || (next_x > dim - 1) || (next_y < 0) || (next_y > dim - 1))
			{
			}
			else
			{
				board[x][y] = board[next_x][next_y];
				board[next_x][next_y] = ' ';
				NODE* node = (NODE*)malloc(sizeof(NODE));
				node->x = next_x;
				node->y = next_y;
				myQueue.push(*node);	
				HBFS(board, &myQueue.front(), entr + 1);
				board[next_x][next_y] = board[x][y];
				board[x][y] = ' ';
				PrintBoard(board);
				printf("----\n");
			}
		}
		myQueue.pop();
		PrintBoard(board);
		printf("\n");
	}
}
int main()
{
	int i = 0, j = 0, k = 0;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			board[i][j] = strData[k];
			k++;
		}
	PrintBoard(board);
	printf("\n");
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->x = 2;
	node->y = 2;
	myQueue.push(*node);
	HBFS(board, &myQueue.front(),0);
	
	return 0;
}