/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:55:38 by tharle            #+#    #+#             */
/*   Updated: 2019/09/07 18:58:08 by tharle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "fillit.h"

int				g_j;
int				g_count;
int				g_k;

int		verify(char **file)
{
	int			r;
	int			c;
	int			num;

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

void	coord_array(char **figure, t_figure *figur, int *first, int *g_k)
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
					first[0] = (int)g_j;
					first[1] = (int)*g_k;
					figur->x[0] = (int)g_j;
					figur->y[0] = (int)*g_k;
				}
				else
				{
					(g_j < first[0]) ? first[0] = g_j : first[0];
					figur->y[g_count] = (int)*g_k;
					figur->x[g_count] = (int)g_j;
				}
			}
		}
		g_j = -1;
		*g_k += 1;
	}
}

int		second_check(char **figure, int *i, int *fig_num, t_list **figures)
{
	int			*first;
	t_figure	*figur;

	g_k = 0;
	figur = (t_figure*)malloc(sizeof(t_figure));
	figur->x = (int*)malloc(sizeof(int) * 4);
	figur->y = (int*)malloc(sizeof(int) * 4);
	first = (int*)malloc(sizeof(int) * 2);
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

int		is_valid(int ac, char **av, int *fig_num, t_list **figures)
{
	int			fd;
	char		*line;
	char		**figure;
	int			text;
	int			i;

	i = 0;
	text = 1;
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0 && text < 6)
	{
		if (text == 1)
			if (!(figure = (char**)malloc(sizeof(*figure) * 5)))
				return (0);
		if (!(simple_check(&line, &text, figure, &i)))
			return (0);
		if (!(second_check(figure, &i, fig_num, figures)))
			return (0);
	}
	if (text < 5)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	t_list		**figures;
	t_list		*figure;
	int			fig_num;
	int			cp;
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
