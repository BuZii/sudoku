/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   sudoku.h                                                           */
/*                                                                            */
/*   By: Gya, Timofey, Bulat                                                  */
/*                                                                            */
/*   Created: 2018/09/29 22:09:07                                             */
/*   Updated: 2018/09/30 21:48:47                                             */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_cell
{
	int value;
	int changeable;
}				t_cell;

int				numbers_are_ok(t_cell *grid);

int				check_input_valid(int ac, char **av);

int				checksquare(int num, t_cell *grid, int pos);

void			print_grid(t_cell *grid);

int				checknum(int num, t_cell *grid, int pos);

t_cell			*fill_grid(t_cell *grid, char **av);

int				solve(t_cell *grid, int index);

#endif
