/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:55:38 by tharle            #+#    #+#             */
/*   Updated: 2019/09/07 18:58:08 by tharle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map)
{
	unsigned		i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i++]);
		ft_putchar('\n');
	}
}

void	clear_map(char **map)
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

void	clear_list(t_list **figures)
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
