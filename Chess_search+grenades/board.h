#pragma once
#ifndef BOARD_H
#define BOARD_H

#define dim 8
#define plotvaX 0
#define plotvaY 0
#define geraltX dim-1
#define geraltY dim-1
#define grenadD 4

typedef struct Node
{
	short int x;
	short int y;
}NODE;

typedef struct Cell
{
	short int step;
	short int parent;
	bool wall;
	bool visited;
	
}CELL;

CELL*** CopyBoard(CELL*** board);
CELL*** CreateBoard();
void PrintBoard(CELL*** board);
CELL* CreateCell(short int x, short int y);
NODE* CreateNode(short int x, short int y);
void PrintResult(CELL*** boardResult,int result, int grenades,int exp);





#endif // !BOARD_H