#ifndef _BOARD_H_INCLUDED_
#define _BOARD_H_INCLUDED_
#include <stdlib.h>
#include <stdio.h>

#define VOID_CELL -1
#define NO_NEIGHBOR -1
#define CELL_NUM 13
#define NEIGHBORS_NUM 6

typedef struct board
{
	short board[CELL_NUM];
	short neighbors[CELL_NUM][NEIGHBORS_NUM];
	int redScore;
	int blueScore;
}Board;

Board *create_board();
void clear_board(Board *b);
int void_cell_index(Board *b);
void compute_score(Board *b);
void set_pawn(Board *b, int index, short value);
void delete_board(Board *b);
#endif