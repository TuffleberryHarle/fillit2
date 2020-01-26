/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:55:38 by tharle            #+#    #+#             */
/*   Updated: 2019/09/07 18:58:08 by tharle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ext_tmp;
char	**ext_map;
char	*ext_letter;
unsigned		ext_i;
unsigned		ext_x;
unsigned		ext_y;
unsigned		ext_curr;
unsigned		ext_total;

void	square_expand(void)
{
	unsigned		i;

	i = 0;
	if (ext_x >= (ext_total - 1) && ext_y >= (ext_total - 1) && ext_curr == 0)
	{
		while (i < ext_total)
		{
			ft_strdel(&ext_map[i]);
			i++;
		}
		ft_strdel(ext_map);
		ext_total++;
		map_clear(ext_map);
		ext_map = dots_set(ext_total);
		ext_x = 0;
		ext_y = 0;
	}
}

void	figure_check(t_list *figures)
{
	if (ext_i != 4)
	{
		clear_to_expand(ext_total, ext_map, ext_letter[ext_curr]);
		ext_x++;
	}
	else
	{
		ext_curr++;
		ext_tmp = get_item(figures, ext_curr);
		ext_x = 0;
		ext_y = 0;
	}
}

void	figure_set(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 4)
	{
		while ((x - y) < 4 && ext_i < 4)
		{
			if ((((int*)((t_figure*)ext_tmp->content)->x)[ext_i] == x) &&
				(((int*)((t_figure*)ext_tmp->content)->y)[ext_i] == y))
			{
				if (!(y + ext_y >= ext_total || x + ext_x >= ext_total)
					&& (ext_map[y + ext_y][x + ext_x] == '.'))
					ext_map[y + ext_y][x + ext_x] = ext_letter[ext_curr];
				else
					break ;
				ext_i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	next_dot(t_list *figures)
{
	if (ext_x > ext_total)
	{
		ext_y++;
		ext_x = 0;
	}
	if (ext_y >= ext_total)
	{
		ext_x = 0;
		ext_y = 0;
		ext_curr--;
		while (ext_map[ext_y][ext_x] != ext_letter[ext_curr])
		{
			if (ext_x++ == ext_total)
			{
				ext_x = 0;
				ext_y++;
			}
		}
		clear_to_expand(ext_total, ext_map, ext_letter[ext_curr]);
		ext_tmp = get_item(figures, ext_curr);
		ext_x += 1 - ((int*)((t_figure*)ext_tmp->content)->x)[0];
	}
}

char	**tetr_solve(t_list *figures, unsigned count)
{
	ext_i = 0;
	ext_letter = ft_strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	ext_curr = 0;
	ext_tmp = figures;
	ext_map = NULL;
	ext_total = get_start_total(count);
	ext_map = dots_set(ext_total);
	while (ext_curr < count)
	{
		next_dot(figures);
		square_expand();
		figure_set();
		figure_check(figures);
		ext_i = 0;
	}
	free(ext_letter);
	return (ext_map);
}
