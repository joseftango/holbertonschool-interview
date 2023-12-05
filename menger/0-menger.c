#include "menger.h"


/**
 * menger - draws a 2D Menger Sponge of given level
 * @level: level of the Menger Sponge to draw
 * Return: void
*/

void menger(int level)
{
	int size = pow(3, level), row = 0, column = 0, pound = 1;
	int divisor = pow(3, 0), r_remain = 0, c_remain = 0;

	if (level < 0)
		return;
	if (level == 0)
		printf("#\n");
	if (level > 0)
	{
		for (row = 0; row < size; row++)
		{
			for (column = 0; column < size; column++)
			{
				pound = 1;
				for (divisor = 1; divisor < size; divisor *= 3)
				{
					r_remain = ((row / divisor) % 3) == 1;
					c_remain = ((column / divisor) % 3) == 1;
					if (r_remain && c_remain && pound)
						pound = 0;
				}
				if (pound)
					printf("#");
				else
					printf(" ");
			}
			printf("\n");
		}
	}
}
