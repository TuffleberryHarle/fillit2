/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:55:38 by tharle            #+#    #+#             */
/*   Updated: 2019/09/07 18:58:08 by tharle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	map_print(char **map)
{
	unsigned		i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i++]);
		ft_putchar('\n');
	}
}

void	map_clear(char **map)
{
	unsigned		i;

	i = 0;
	while (map[i])
	{
		ft_strdel(&map[i]);
		i++;
	}
	free(map);
}

void	list_clear(t_list **figures)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = *figures;
	if (tmp)
	{
		while (tmp)
		{
			tmp1 = tmp->next;
			free(tmp);
			tmp = tmp1;
		}
	}
}
