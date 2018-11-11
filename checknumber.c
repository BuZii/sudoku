/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   checknumber.c                                                            */
/*                                                                            */
/*   By: Gaia, Timofey, Bulat                                                  */
/*                                                                            */
/*   Created: 2018/09/30 16:57:07                                             */
/*   Updated: 2018/09/30 21:48:47                                             */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		checknum(int num, t_cell *grid, int pos)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (pos != (pos / 9) * 9 + i)
		{
			if ((grid + (pos / 9) * 9 + i)->value == num)
				return (0);
		}
		if (pos != (pos % 9) + 9 * i)
		{
			if ((grid + (pos % 9) + 9 * i)->value == num)
				return (0);
		}
		i++;
	}
	return (checksquare(num, grid, pos));
}

int		checksquare(int num, t_cell *grid, int pos)
{
	int i;
	int row;
	int col;
	int j;

	row = (((pos / 9) / 3) * 3);
	col = (((pos % 9) / 3) * 3);
	i = 0;
	j = 0;
	while (j < 9)
	{
		if (pos != row * 9 + col + i)
		{
			if ((grid + row * 9 + col + i)->value == num)
				return (0);
		}
		if ((col + i) % 3 == 2)
			i = i + 7;
		else
			i++;
		j++;
	}
	return (1);
}

int		numbers_are_ok(t_cell *grid)
{
	int i;

	i = 0;
	while (i < 81)
	{
		if ((grid + i)->changeable == 0)
		{
			if (checknum((grid + i)->value, grid, i) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}
