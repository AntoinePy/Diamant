#include "tree.h"

int main()
{
	int idCellBlue = 0;
	int idCellRed = 1;
	Board *board = create_board();
	Tree *tree = create_tree(board);
	set_first_blue_choice(tree, idCellBlue);
	set_first_red_choice(tree, idCellBlue);
	build_tree(tree);
	printf("nb configurations: %d, nb blue victories: %d, nb red victories: %d, nb draws: %d\n", 
		tree->nbConfigurations, compute_blue_victories(tree, tree->root), 
		compute_red_victories(tree, tree->root), compute_draws(tree, tree->root));

	//
	delete_tree(tree);
	delete_board(board);
	return 0;
}