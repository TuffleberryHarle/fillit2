/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:58:45 by galiza            #+#    #+#             */
/*   Updated: 2019/05/15 15:00:35 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i++]);
		ft_putchar('\n');
	}
}

void	clear_map(char **map)
{
	int		i;

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
