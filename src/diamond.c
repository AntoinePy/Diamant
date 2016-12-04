#include <stdio.h>
#include <stdlib.h>
#include "diamond.h"

int nbConfigurations;

/**********************************
   functions to mangage the board
***********************************/
board_t* createBoard() {
  board_t* b = NULL;
  /* A COMPLETER :
     - allouer l'espace mémoire pour une board_t et mettre l'adresse dans b */
    pointeur = malloc(sizeof(board_t));
    b=&pointeur;
    /*
     - "effacer" le plateau
     */
     clear_board(b);
/*
     - mettre NO_NEIGHBOR dans toutes les cases du tableau b->neighbors
     */
    b->neighbors;
     for(int i=0;i<13;i++) {
            for(int j=0;j<6;j++) {
                neighbors[i][j] = NO_NEIGHBOR;
            }
        }
    /*
     - initialiser neighbors (cf. canevas Java)
     */
     neighbors[0][0] = 1;
        neighbors[0][1] = 3;
        neighbors[0][2] = 4;
        // define neighbors for cell 1
        neighbors[1][0] = 0;
        neighbors[1][1] = 2;
        neighbors[1][2] = 4;
        neighbors[1][3] = 5;
        // define neighbors for cell 2
        neighbors[2][0] = 1;
        neighbors[2][1] = 5;
        neighbors[2][2] = 6;
        // define neighbors for cell 3
        neighbors[3][0] = 0;
        neighbors[3][1] = 4;
        neighbors[3][2] = 7;
        // define neighbors for cell 4
        neighbors[4][0] = 0;
        neighbors[4][1] = 1;
        neighbors[4][2] = 3;
        neighbors[4][3] = 5;
        neighbors[4][4] = 7;
        neighbors[4][5] = 8;
        // define neighbors for cell 5
        neighbors[5][0] = 1;
        neighbors[5][1] = 2;
        neighbors[5][2] = 4;
        neighbors[5][3] = 6;
        neighbors[5][4] = 8;
        neighbors[5][5] = 9;
        // define neighbors for cell 6
        neighbors[6][0] = 2;
        neighbors[6][1] = 5;
        neighbors[6][2] = 9;
        // define neighbors for cell 7
        neighbors[7][0] = 3;
        neighbors[7][1] = 4;
        neighbors[7][2] = 8;
        neighbors[7][3] = 10;
        // define neighbors for cell 8
        neighbors[8][0] = 4;
        neighbors[8][1] = 5;
        neighbors[8][2] = 7;
        neighbors[8][3] = 9;
        neighbors[8][4] = 10;
        neighbors[8][5] = 11;
        // define neighbors for cell 9
        neighbors[9][0] = 5;
        neighbors[9][1] = 6;
        neighbors[9][2] = 8;
        neighbors[9][3] = 11;
        // define neighbors for cell 10
        neighbors[10][0] = 7;
        neighbors[10][1] = 8;
        neighbors[10][2] = 11;
        neighbors[10][3] = 12;
        // define neighbors for cell 11
        neighbors[11][0] = 8;
        neighbors[11][1] = 9;
        neighbors[11][2] = 10;
        neighbors[11][3] = 12;
        // define neighbors for cell 12
        neighbors[12][0] = 10;
        neighbors[12][1] = 11;


  return b;
}

void clearBoard(board_t* b) {
  /* A COMPLETER : cf. canevas Java
   */
}

int voidCellIndex(board_t* b) {
  int id = -1;
  /* A COMPLETER : cf. canevas Java

  */
  return id;
}

void computeScore(board_t* b) {

  /* A COMPLETER : cf. canevas Java
  */

}

void setPawn(board_t* b, int idCell, char value) {
  b->board[idCell] = value;
}


/**********************************
   functions to mangage the nodes
***********************************/

node_t* createNode(int idCell, int turn) {
  node_t* n = NULL;
  /* A COMPLETER :
     - allouer l'espace mémoire pour un node_t et mettre son adresse dans n
     - initialiser les champs idCell, turn, result, nbChildren (cf. canevas Java)
     - allouer l'espace mémoire pour children en fonction de turn (cf. canevas Java et énoncé)
  */
  return n;
}

node_t* addChild(node_t* n, int idCell) {
  node_t* child = NULL;
  /* A COMPLETER : 
     - créer un nouveau noeud child avec comme paramètre idCell et n->turn+1
     - ajouter child aux fils de n et incrémenter son nombre de fils     
  */
  return child;
}

/**********************************
   functions to mangage the tree
***********************************/

tree_t* createTree() {

  tree_t* t = NULL;
  /* A COMPLETER :
     - allouer l'espace mémoire pour un tree_t et mettre son adresse dans t
     - initialiser le champ root
  */

  return t;
}


void setFirstBlueChoice(tree_t* t, board_t* b, int idCell) {
  /* A COMPLETER : cf. canevas Java
  */
}

void setFirstRedChoice(tree_t* t, board_t* b, int idCell) {
  /* A COMPLETER : cf. canevas Java
   */  
}

void buildTree(tree_t* t, board_t* b) {
  /* A COMPLETER : cf. canevas Java
  */
}

void computePossibilities(node_t* n, board_t* b) {

  /* A COMPLETER : cf. canevas Java
  */

}

int computeBlueVictories(node_t* n) {
  int nb = 0;
  /* A COMPLETER :
  */
  return nb;
}

int computeRedVictories(node_t* n) {
  int nb = 0;
  /* A COMPLETER :
  */
  return nb;

}

int computeDraws(node_t* n) {
  int nb = 0;
  /* A COMPLETER :
  */
  return nb;

}


