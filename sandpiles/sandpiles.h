#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

void topple(int grid[SIZE][SIZE], int row, int col);
int isStable(int grid[SIZE][SIZE]);
void sandpiles_sum(int grid1[SIZE][SIZE], int grid2[SIZE][SIZE]);
void printSandpile(int grid[SIZE][SIZE]);
#endif /* SANDPILES_H */
