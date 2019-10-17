#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctime>
#include <cstdio>
#include "board.h"
using namespace std;

queue<NODE*> cellQueue;
queue<CELL***> boardQueue;
queue<int> grenadesQueue;
queue<int> inQueue; 
queue<int> explosionsQueue;

int dX[4] = { +1,-1,+0,-0};
int dY[4] = { +0,-0,+1,-1};
//int dX[8] = { +1,-1,-2,+2,-2,+2,-1,+1 };
//int dY[8] = { -2,-2,-1,-1,+1,+1,+2,+2 };
int k = 0;
int result = 0;
double start = clock();



void FindWay(CELL*** curBoard, NODE* curCell)
{
	short int next_x = 0;
	short int next_y = 0;
	short int x = curCell->x;
	short int y = curCell->y;
	short int grenades = grenadesQueue.front();
	short int exp = explosionsQueue.front();
	int such_boards_inQueue = inQueue.front() - 1;
	//PrintBoard(curBoard);
	if ((x == geraltX) && (y == geraltY))
	{
		//PrintBoard(curBoard);
		//printf("\nGrenades:%i", grenades);
		result = curBoard[x][y]->step;
		PrintResult(curBoard, result, grenades,exp);
		printf("\n%.4lf\n", (clock() - start) / CLOCKS_PER_SEC);
		exit(1);
	}
	else 
	{
		for (short int k = 0; k < 8; k++)
		{
			next_x = x + dX[k];
			next_y = y + dY[k];
			if ((next_x < 0) || (next_x > dim - 1) || (next_y < 0) || (next_y > dim - 1) || (curBoard[next_x][next_y]->visited))
			{
			}
			else
			{
				
				if (curBoard[next_x][next_y]->wall)
				{
					if (grenadesQueue.front() > 0)
					{
						exp++;
						CELL*** newBoard = CopyBoard(curBoard);
						newBoard[next_x][next_y]->wall = false;
						grenades--;
						newBoard[next_x][next_y]->step = curBoard[x][y]->step+1;
						newBoard[next_x][next_y]->visited = true;

						newBoard[next_x][next_y]->parent =k;

                        boardQueue.push(newBoard);
						cellQueue.push(CreateNode(next_x, next_y));
						grenadesQueue.push(grenades);
						inQueue.push(1);
						explosionsQueue.push(exp);
					}
				}
				else
				{
					//curBoard[next_x][next_y]->visited = true;
					curBoard[next_x][next_y]->parent = k;
					curBoard[next_x][next_y]->step = curBoard[x][y]->step + 1;
					such_boards_inQueue++;

					boardQueue.push(curBoard);
					cellQueue.push(CreateNode(next_x,next_y));
				    grenadesQueue.push(grenades);

					inQueue.push(such_boards_inQueue);
					explosionsQueue.push(exp);
				}
			}
		}
		if(inQueue.front()==0)
			free(boardQueue.front());
		free(cellQueue.front());

		boardQueue.pop();
		cellQueue.pop();
		grenadesQueue.pop();
		inQueue.pop();
		explosionsQueue.pop();
	}
   

}





int main()
{
	CELL*** board = CreateBoard();
	NODE* cell = CreateNode(plotvaX, plotvaY);
	int k = 0;
	char str[] = "00W0W00W 0W0W00W0 W0W00W00 0W00WW00 W00WWW00 00WWW00W 0WWW00W0 WWW00W00";
	//char str[] = "WWWWWWWW WWWWWWWW WWWWWWWW WWWWWWWW WWWWWWWW WWWWWWWW WWWWWWWW WWWWWWWW";

	for(int i=0;i<dim;i++)
		for (int j = 0; j < dim; j++)
		{
			if (str[k] == ' ')
				k++;
			if (str[k] == 'W')
				board[i][j]->wall = true;
			k++;
		}
   
	PrintBoard(board);
	

	board[plotvaX][plotvaY]->visited = true;
	boardQueue.push(board);
	cellQueue.push(cell);
	grenadesQueue.push(grenadD);
	inQueue.push(1);
	explosionsQueue.push(0);

	while(!boardQueue.empty())
		FindWay(boardQueue.front(), cellQueue.front());




	printf("%.4lf\n", (clock() - start) / CLOCKS_PER_SEC);
	
	return 0;
}