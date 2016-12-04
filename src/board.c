#include "board.h"


Board *create_board()
{
	Board *result = NULL;
	int i, j;
	result = (Board*)malloc(sizeof(Board));
	clear_board(result);
	for (i = 0; i < CELL_NUM; i++) {
		for (j = 0; j < NEIGHBORS_NUM; j++)
			result->neighbors[i][j] = NO_NEIGHBOR;
	}
	// define neighbors for cell 0
	result->neighbors[0][0] = 1;
	result->neighbors[0][1] = 3;
	result->neighbors[0][2] = 4;
	// define neighbors for cell 1
	result->neighbors[1][0] = 0;
	result->neighbors[1][1] = 2;
	result->neighbors[1][2] = 4;
	result->neighbors[1][3] = 5;
	// define neighbors for cell 2
	result->neighbors[2][0] = 1;
	result->neighbors[2][1] = 5;
	result->neighbors[2][2] = 6;
	// define neighbors for cell 3
	result->neighbors[3][0] = 0;
	result->neighbors[3][1] = 4;
	result->neighbors[3][2] = 7;
	// define neighbors for cell 4
	result->neighbors[4][0] = 0;
	result->neighbors[4][1] = 1;
	result->neighbors[4][2] = 3;
	result->neighbors[4][3] = 5;
	result->neighbors[4][4] = 7;
	result->neighbors[4][5] = 8;
	// define neighbors for cell 5
	result->neighbors[5][0] = 1;
	result->neighbors[5][1] = 2;
	result->neighbors[5][2] = 4;
	result->neighbors[5][3] = 6;
	result->neighbors[5][4] = 8;
	result->neighbors[5][5] = 9;
	// define neighbors for cell 6
	result->neighbors[6][0] = 2;
	result->neighbors[6][1] = 5;
	result->neighbors[6][2] = 9;
	// define neighbors for cell 7
	result->neighbors[7][0] = 3;
	result->neighbors[7][1] = 4;
	result->neighbors[7][2] = 8;
	result->neighbors[7][3] = 10;
	// define neighbors for cell 8
	result->neighbors[8][0] = 4;
	result->neighbors[8][1] = 5;
	result->neighbors[8][2] = 7;
	result->neighbors[8][3] = 9;
	result->neighbors[8][4] = 10;
	result->neighbors[8][5] = 11;
	// define neighbors for cell 9
	result->neighbors[9][0] = 5;
	result->neighbors[9][1] = 6;
	result->neighbors[9][2] = 8;
	result->neighbors[9][3] = 11;
	// define neighbors for cell 10
	result->neighbors[10][0] = 7;
	result->neighbors[10][1] = 8;
	result->neighbors[10][2] = 11;
	result->neighbors[10][3] = 12;
	// define neighbors for cell 11
	result->neighbors[11][0] = 8;
	result->neighbors[11][1] = 9;
	result->neighbors[11][2] = 10;
	result->neighbors[11][3] = 12;
	// define neighbors for cell 12
	result->neighbors[12][0] = 10;
	result->neighbors[12][1] = 11;
	return result;
}

void clear_board(Board *b)
{
	int i;
	for (i = 0; i < CELL_NUM; i++)
		b->board[i] = VOID_CELL;
	b->blueScore = 0;
	b->redScore = 0;
}

int void_cell_index(Board *b)
{
	int i;
	for (i = 0; i < CELL_NUM; i++)
	{
		if (b->board[i] == VOID_CELL)
			return i;
	}
	return -1;
}

void compute_score(Board *b)
{
	int i, idVoid;
	b->blueScore = 0;
	b->redScore = 0;
	idVoid = void_cell_index(b);
	for (i = 0; i < NEIGHBORS_NUM; i++)
	{
		if (b->neighbors[idVoid][i] != NO_NEIGHBOR)
		{
			if (b->board[b->neighbors[idVoid][i]] <= 6)
				b->blueScore += b->board[b->neighbors[idVoid][i]];
			else
				b->redScore += (b->board[b->neighbors[idVoid][i]] - 6);
		}
	}
}

void set_pawn(Board *b, int index, short value)
{
	b->board[index] = value;
}

void delete_board(Board *b)
{
	free(b);
}