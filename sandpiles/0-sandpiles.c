#include "sandpiles.h"

/**
 * printSandpile - prints sandpile
 * @grid: dd array
 * Return: void
**/
void printSandpile(int grid[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/**
 * topple - function that topple
 * @grid: dd array
 * @row: row
 * @col: column
 * Return: void
**/

void topple(int grid[SIZE][SIZE], int row, int col)
{
	grid[row][col] -= 4;

	if (col - 1 >= 0)
		grid[row][col - 1]++;
	if (col + 1 < SIZE)
		grid[row][col + 1]++;
	if (row - 1 >= 0)
		grid[row - 1][col]++;
	if (row + 1 < SIZE)
		grid[row + 1][col]++;
}

/**
 * isStable - function that checks satability
 * @grid: dd array
 * Return: 1 or 0
**/
int isStable(int grid[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * sandpiles_sum - counting sum of sandpiles
 * @grid1: dd array
 * @grid2: dd array
 * Return: void
*/

void sandpiles_sum(int grid1[SIZE][SIZE], int grid2[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	while (!isStable(grid1))
	{
		printf("Unstable Sandpile:\n");
		printSandpile(grid1);

		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (grid1[i][j] > 3)
					topple(grid1, i, j);
			}
		}
	}

	printf("Final Stable Sandpile:\n");
	printSandpile(grid1);
}
