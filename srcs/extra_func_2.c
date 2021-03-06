/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:55:38 by tharle            #+#    #+#             */
/*   Updated: 2019/09/07 18:58:08 by tharle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clear_to_expand(unsigned int total, char **map, char c)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < total)
	{
		while (x < total)
		{
			if (map[y][x] == c)
				map[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
}

t_list	*get_item(t_list *figures, unsigned int current_item)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = figures;
	while (i < current_item)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

unsigned		get_start_total(unsigned count)
{
	unsigned		total;
	unsigned		i;

	i = 2;
	total = 0;
	while (i < 11)
	{
		if (i * i >= count * 4)
		{
			total = i;
			break ;
		}
		i++;
	}
	return (total);
}

char	**dots_set(unsigned total)
{
	char	**map;
	unsigned		i;

	i = 0;
	map = (char**)malloc(sizeof(char*) * (total + 1));
	while (i < total)
	{
		map[i] = ft_strnew(total);
		ft_memset(map[i], '.', total);
		i++;
	}
	map[i] = 0;
	return (map);
}
