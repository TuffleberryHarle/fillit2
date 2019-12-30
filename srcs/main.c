/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:55:38 by tharle            #+#    #+#             */
/*   Updated: 2019/09/07 18:58:08 by tharle	          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "fillit.h"

unsigned				g_j;
unsigned				g_count;
unsigned				g_k;

unsigned		verify(char **file)
{
	unsigned			r;
	unsigned			c;
	unsigned			num;

	r = 0;
	c = 0;
	num = 0;
	while (r < 4)
	{
		while (file[r][c] != '\0')
		{
			if (file[r][c] != '#' && file[r][c] != '.')
				return (0);
			if (file[r][c++] == '#')
				num++;
		}
		c = 0;
		r++;
	}
	r = 0;
	g_count = -1;
	if (num == 4 && conections_sum(&r, &c, &num, file))
		return (1);
	return (0);
}

void	coord_array(char **figure, t_figure *figur, unsigned *first, unsigned *g_k)
{
	g_j = -1;
	while (*g_k < 4)
	{
		while (figure[*g_k][++g_j] != '\0')
		{
			if (figure[*g_k][g_j] == '#')
			{
				if (++g_count == 0)
				{
					first[0] = (unsigned)g_j;
					first[1] = (unsigned)*g_k;
					figur->x[0] = (unsigned)g_j;
					figur->y[0] = (unsigned)*g_k;
				}
				else
				{
					(g_j < first[0]) ? first[0] = g_j : first[0];
					figur->y[g_count] = (unsigned)*g_k;
					figur->x[g_count] = (unsigned)g_j;
				}
			}
		}
		g_j = -1;
		*g_k += 1;
	}
}

unsigned		second_check(char **figure, unsigned *i, unsigned *fig_num, t_list **figures)
{
	unsigned	*first;
	t_figure	*figur;

	g_k = 0;
	figur = (t_figure*)malloc(sizeof(t_figure));
	figur->x = (unsigned*)malloc(sizeof(unsigned) * 4);
	figur->y = (unsigned*)malloc(sizeof(unsigned) * 4);
	first = (unsigned*)malloc(sizeof(unsigned) * 2);
	if (*i == 4)
	{
		figure[5] = NULL;
		if (!(verify(figure)))
			return (0);
		*i = 0;
		coord_array(figure, figur, first, &g_k);
		correct_coords(figur, figures, first);
		*fig_num += 1;
		while (*i < 4)
		{
			free(figure[*i]);
			*i += 1;
		}
		free(figure);
	}
	return (1);
}

unsigned		is_valid(int ac, char **av, unsigned *fig_num, t_list **figures)
{
	int			fd;
	char		*line;
	char		**figure;
	unsigned	rows;
	unsigned	i;

	i = 0;
	rows = 1;
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0 && rows < 6)
	{
		if (rows == 1)
			if (!(figure = (char**)malloc(sizeof(*figure) * 5)))
				return (0);
		if (!(simple_check(&line, &rows, figure, &i)))
			return (0);
		if (!(second_check(figure, &i, fig_num, figures)))
			return (0);
	}
	if (rows < 5)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	t_list		**figures;
	t_list		*figure;
	unsigned	fig_num;
	unsigned	cp;
	char		**map;

	fig_num = 0;
	if (!(figures = (t_list**)malloc(sizeof(t_list*))))
		return (0);
	*figures = NULL;
	if (!(is_valid(ac, av, &fig_num, figures)))
	{
		if (ac != 2)
			ft_putstr("usage: fillit input_file\n");
		else
			ft_putstr("error\n");
		return (0);
	}
	figure = *figures;
	cp = fig_num;
	map = solve_tetris(figure, cp);
	print_map(map);
	clear_map(map);
	clear_list(figures);
}
