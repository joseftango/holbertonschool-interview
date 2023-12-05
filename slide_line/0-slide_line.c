#include "slide_line.h"

/**
 * slide_line - slides and merges an array of ints to the left or right,
 * based on the mechanics of the 2048 game on a single horizontal line
 * @line: pointer to the array
 * @size: the size of the array
 * @direction: int defined by macro to determine if sliding left or right
 * Return: 1 or 0
 */

int slide_line(int *line, size_t size, int direction)
{
	int index = 0, placeholder = 0;

	if (size < 1 || (direction != SLIDE_RIGHT && direction != SLIDE_LEFT))
		return (0);
	if (direction == SLIDE_RIGHT)
	{
		placeholder = (size - 1);
		for (index = (size - 2); index >= 0; index--)
		{
			if (line[index] == line[placeholder] && line[index])
				slide(line, index, placeholder--);
			else if (line[index] != line[placeholder] && line[index])
			{
				if (line[placeholder] != 0)
					placeholder--;
				if (line[placeholder] == 0)
					slide(line, index, placeholder);
			}
		}
	}
	else if (direction == SLIDE_LEFT)
	{
		for (index = 1; index < (int)size; index++)
		{
			if (line[index] == line[placeholder] && line[index])
				slide(line, index, placeholder++);
			else if (line[index] != line[placeholder] && line[index])
			{
				if (line[placeholder] != 0)
					placeholder++;
				if (line[placeholder] == 0)
					slide(line, index, placeholder);
			}
		}
	}
	return (1);
}

/**
 * slide - adds the value of index to the placeholder
 * @line: pointer to the array
 * @index: index to get value that needs to be shifted
 * @placeholder: index to merge index's value
 * Return: void
*/

void slide(int *line, int index, int placeholder)
{
	line[placeholder] += line[index];
	line[index] = 0;
}
