#include "tree.h"


Node *create_node(int idCell, int turn)
{
	Node *result = NULL;
	result = (Node*)malloc(sizeof(Node));
	result->idCell = idCell;
	result->turn = turn;
	if (turn == 1)
		result->children = (Node**)malloc(sizeof(Node*));
	else if (turn < 12)
		result->children = (Node**)malloc(sizeof(Node*)* (MAX_CHILDREN - turn));
	else
		result->children = NULL;
	result->nbChildren = 0;
	result->result = NO_RESULT;
	return result;
}

Node *addChild(Node *n, int idCell)
{
	n->children[n->nbChildren] = create_node(idCell, n->turn + 1);
	n->nbChildren++;
	return n->children[n->nbChildren - 1];
}

void delete_node(Node *n)
{
	int i;
	if (n == NULL)
		return;
	for (i = 0; i < n->nbChildren; i++)
	{
		delete_node(n->children[i]);
	}
	free(n->children[i]);
}

Tree *create_tree(Board *b)
{
	Tree *temp = NULL;
	temp = (Tree *)malloc(sizeof(Tree));
	temp->root = NULL;
	temp->board = b;
	temp->nbConfigurations = 0;
	return temp;
}

void set_first_blue_choice(Tree *t, int idCell)
{
	t->root = create_node(idCell, 1);
	set_pawn(t->board, idCell, 1);
}

void set_first_red_choice(Tree *t, int idCell)
{
	addChild(t->root, idCell);
	set_pawn(t->board, idCell, 7);
}

void build_tree(Tree *t)
{
	Node *n;
	t->nbConfigurations = 0;
	n = t->root->children[0];
	compute_possibilities(t, n);
	printf(" done.");
}

void compute_possibilities(Tree *t, Node *n)
{
	int i, r, b, nextPawnValue;
	Node *child;
	if (n->turn == 12) 
	{
		compute_score(t->board);
		r = t->board->redScore;
		b = t->board->blueScore;
		if (b == r)
			n->result = DRAW_PARTY;
		// if blue obtains less than red -> blue wins
		else if (b < r)
			n->result = BLUE_WINS;
		// if red obtains less than blue -> red wins
		else 
			n->result = RED_WINS;
		t->nbConfigurations += 1;
		if ((t->nbConfigurations % 1000000) == 0)
			printf(".");
		return;
	}
	nextPawnValue = (n->turn + 2) / 2;
	if ((n->turn + 1) % 2 == 0) 
		nextPawnValue += 6;
	for (i = 0; i < CELL_NUM; i++)
	{
		if (t->board->board[i] == VOID_CELL) {
			// place the pawn here
			set_pawn(t->board, i, nextPawnValue);
			// create the corresponding node in the tree
			child = addChild(n, i);
			// recursive call
			compute_possibilities(t, child);
			// remove pawn so that the cell appears to be free
			set_pawn(t->board, i, VOID_CELL);
		}
	}
}

void delete_tree(Tree *t)
{
	if (t == NULL)
		return;
	delete_node(t->root);
	free(t);
}

int compute_blue_victories(Tree *t, Node *n)
{
    int nb = 0;
    if(n.result == Node.BLUE_WINS && n.nbChildren == 0) nb++;
    if(n.children !=null) {
        for (int i = 0; i < n.children.length; i++) {
            if (n.children[i] != null) {
                nb += computeBlueVictories(n.children[i]);
            }
        }
    }
    return nb;
}
}

int compute_red_victories(Tree *t, Node *n)
{
	int nb = 0;
    if(n.result == Node.RED_WINS&& n.nbChildren == 0) nb++;
    if(n.children != null) {
        for (int i = 0; i < n.children.length; i++) {
            if (n.children[i] != null) {
                nb += computeRedVictories(n.children[i]);
            }
        }
    }
    return nb;
}

int compute_draws(Tree *t, Node *n)
{
    int nb = 0;
    if(n.result == Node.DRAW_PARTY && n.nbChildren == 0) nb++;
    if(n.children != null) {
        for (int i = 0; i < n.children.length; i++) {
            if (n.children[i] != null) {
                nb += computeDraws(n.children[i]);
            }
        }
    }
    return nb;
}
}