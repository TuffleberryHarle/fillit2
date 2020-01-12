/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:55:38 by tharle            #+#    #+#             */
/*   Updated: 2019/09/07 18:58:08 by tharle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**g_map;
char	*g_text;
int		g_current_item;
int		g_x1;
int		g_y1;
int		g_total;
t_list	*g_tmp;
int		g_i;

void	next_dot(t_list *figures)
{
	if (g_x1 > g_total)
	{
		g_y1++;
		g_x1 = 0;
	}
	if (g_y1 >= g_total)
	{
		g_x1 = 0;
		g_y1 = 0;
		g_current_item--;
		while (g_map[g_y1][g_x1] != g_text[g_current_item])
		{
			if (g_x1++ == g_total)
			{
				g_x1 = 0;
				g_y1++;
			}
		}
		clear(g_total, g_map, g_text[g_current_item]);
		g_tmp = get_item(figures, g_current_item);
		g_x1 += 1 - ((int*)((t_figure*)g_tmp->content)->x)[0];
	}
}

void	increase_square(void)
{
	int		i;

	i = 0;
	if (g_x1 >= (g_total - 1) && g_y1 >= (g_total - 1) && g_current_item == 0)
	{
		while (i < g_total)
		{
			ft_strdel(&g_map[i]);
			i++;
		}
		ft_strdel(g_map);
		g_total++;
		clear_map(g_map);
		g_map = set_dots(g_total);
		g_x1 = 0;
		g_y1 = 0;
	}
}

void	check(t_list *figures)
{
	if (g_i != 4)
	{
		clear(g_total, g_map, g_text[g_current_item]);
		g_x1++;
	}
	else
	{
		g_current_item++;
		g_tmp = get_item(figures, g_current_item);
		g_x1 = 0;
		g_y1 = 0;
	}
}

void	set_figure(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		while ((x - y) < 4 && g_i < 4)
		{
			if ((((int*)((t_figure*)g_tmp->content)->x)[g_i] == x) &&
					(((int*)((t_figure*)g_tmp->content)->y)[g_i] == y))
			{
				if (!(y + g_y1 >= g_total || x + g_x1 >= g_total)
					&& (g_map[y + g_y1][x + g_x1] == '.'))
					g_map[y + g_y1][x + g_x1] = g_text[g_current_item];
				else
					break ;
				g_i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

char	**solve_tetris(t_list *figures, int count)
{
	g_i = 0;
	g_text = ft_strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	g_current_item = 0;
	g_tmp = figures;
	g_map = NULL;
	g_total = get_start_total(count);
	g_map = set_dots(g_total);
	while (g_current_item < count)
	{
		next_dot(figures);
		increase_square();
		set_figure();
		check(figures);
		g_i = 0;
	}
	free(g_text);
	return (g_map);
}
