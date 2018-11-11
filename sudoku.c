/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   sudoku.c                                                                 */
/*                                                                            */
/*   By: Gya, Timofey, Bulat                                                  */
/*                                                                            */
/*   Created: 2018/09/30 16:57:07                                             */
/*   Updated: 2018/09/30 21:48:47                                             */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		main(int argc, char **argv)
{
	t_cell *grid;

	grid = NULL;
	if (check_input_valid(argc, argv) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	grid = fill_grid(grid, argv + 1);
	if (!grid)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (numbers_are_ok(grid) == 0 || solve(grid, 0) == 0)
	{
		write(1, "Error\n", 6);
	}
	return (0);
}

int		check_input_valid(int ac, char **av)
{
	int i;
	int j;
	int count;

	if (ac != 10)
		return (0);
	i = 0;
	count = 0;
	while (++i < ac)
	{
		j = 0;
		while (j < 9)
		{
			if (av[i][j] == '\0')
				return (0);
			if (av[i][j] > '0' && av[i][j] <= '9')
				count++;
			else if (av[i][j] != '.')
				return (0);
			j++;
		}
	}
	if (count < 17)
		return (0);
	return (1);
}

t_cell	*fill_grid(t_cell *grid, char **av)
{
	int i;
	int j;

	grid = (t_cell*)malloc(sizeof(t_cell) * 81);
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (av[i][j] >= '1' && av[i][j] <= '9')
			{
				(grid + i * 9 + j)->changeable = 0;
				(grid + i * 9 + j)->value = av[i][j] - '0';
			}
			else if (av[i][j] == '.')
			{
				(grid + i * 9 + j)->changeable = 1;
				(grid + i * 9 + j)->value = 0;
			}
			j++;
		}
		i++;
	}
	return (grid);
}

void	print_grid(t_cell *grid)
{
	int		i;
	char	c;

	i = 0;
	while (i < 81)
	{
		c = (grid + i)->value + '0';
		write(1, &c, 1);
		i++;
		if (i % 9 == 0)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
	}
}

int		solve(t_cell *grid, int index)
{
	if (index == 81)
	{
		print_grid(grid);
		return (1);
	}
	if ((grid + index)->changeable == 0)
		return (solve(grid, index + 1));
	while ((grid + index)->value < 9)
	{
		(grid + index)->value += 1;
		if (checknum((grid + index)->value, grid, index) == 1)
			if (solve(grid, index + 1) == 1)
				return (1);
	}
	(grid + index)->value = 0;
	return (0);
}
