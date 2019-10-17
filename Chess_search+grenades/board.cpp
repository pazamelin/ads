#define _CRT_SECURE_NO_WARNINGS   
#include <queue> 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "board.h"
using namespace std;


CELL*** CopyBoard(CELL*** board)
{
	CELL*** newBoard = CreateBoard();
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
		{
			newBoard[i][j]->step = board[i][j]->step;
			newBoard[i][j]->wall = board[i][j]->wall;
			newBoard[i][j]->visited = board[i][j]->visited;
			newBoard[i][j]->parent = board[i][j]->parent;
		}

	
	return newBoard;

}

CELL*** CreateBoard()
{
	int i = 0, j = 0;
	CELL*** newBoard = (CELL***)malloc(dim * sizeof(CELL**));
	for (i = 0; i < dim; i++)
	{
		newBoard[i] = (CELL**)malloc(dim * sizeof(CELL*));
		for (j = 0; j < dim; j++)
			newBoard[i][j] = CreateCell(i, j);
	}	
	return newBoard;
}

CELL* CreateCell(short int x,short int y)
{
	CELL* newCell = (CELL*)malloc(sizeof(CELL));
	newCell->step = 0;
	newCell->parent = 0;
	newCell->wall = false;
	newCell->visited = false;
	return newCell;
}

void PrintBoard(CELL*** board)
{
	printf("\n");
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
			if (board[i][j]->wall == true)
				printf("/ ");
			else
				printf("%i ", board[i][j]->step);
		printf("\n");
	}
}

NODE* CreateNode(short int x, short int y)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->x = x;
	newNode->y = y;
	return newNode;
}

void PrintResult(CELL*** boardResult, int result, int grenades,int exp)
{
	int k = 0;
	int buf = result;
	int dX[4] = { +1,-1,+0,-0 };
	int dY[4] = { +0,-0,+1,-1 };
	CELL*** finalBoard = CreateBoard();
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
             finalBoard[i][j]->wall = boardResult[i][j]->wall;
	short int x = geraltX;
	short int y = geraltY;
	while (result > 0)
	{
		finalBoard[x][y]->step = result;
		k = boardResult[x][y]->parent;
		x = x - dX[k];
		y = y - dY[k];
		result--;
	}
	PrintBoard(finalBoard);
	printf("\n%i steps",buf );
	printf("\n%i grenades has been exploded", exp );

	printf("\n");
}
