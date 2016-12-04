#ifndef _TREE_H_INCLUDED_
#define _TREE_H_INCLUDED_
#include "board.h"

#define NO_RESULT -1
#define DRAW_PARTY 0
#define BLUE_WINS 1
#define RED_WINS 2
#define MAX_CHILDREN 13

typedef struct node
{
	short nbChildren;
	short idCell;
	short turn;
	short result;
	struct node **children;
}Node;

typedef struct tree
{
	Node *root;
	Board *board;
	int nbConfigurations;
}Tree;

Node *create_node(int idCell, int turn);
Node *addChild(Node *n, int idCell);
void delete_node(Node *n);

Tree *create_tree(Board *b);
void set_first_blue_choice(Tree *t, int idCell);
void set_first_red_choice(Tree *t, int idCell);
void build_tree(Tree *t);
void compute_possibilities(Tree *t, Node *n);
int compute_blue_victories(Tree *t, Node *n);
int compute_red_victories(Tree *t, Node *n);
int compute_draws(Tree *t, Node *n);
void delete_tree(Tree *t);
#endif