/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:55:38 by tharle            #+#    #+#             */
/*   Updated: 2019/09/07 18:58:08 by tharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		conections_sum(int *r, int *c, int *num, char **file)
{
	*c = 0;
	*num = 0;
	while (*r < 4)
	{
		while (file[*r][*c] != '\0')
		{
			if (file[*r][*c] == '#')
			{
				if (*c > 0 && file[*r][*c - 1] == '#')
					*num += 1;
				if (*r > 0 && file[*r - 1][*c] == '#')
					*num += 1;
				if (*c < 3 && file[*r][*c + 1] == '#')
					*num += 1;
				if (*r < 3 && file[*r + 1][*c] == '#')
					*num += 1;
			}
			*c += 1;
		}
		*r += 1;
		*c = 0;
	}
	if (*num == 6 || *num == 8)
		return (1);
	return (0);
}

void	create_list(t_list **figures, t_figure *figur)
{
	t_list		*tmp;

	if (!*figures)
		ft_lstadd(figures, ft_lstnew(figur, sizeof(t_figure)));
	else
	{
		tmp = *figures;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(figur, sizeof(t_figure));
	}
}

void	correct_coords(t_figure *figur, t_list **figures, int *first)
{
	int			r;

	r = 0;
	while (r < 4)
	{
		figur->x[r] = (int)figur->x[r] - (int)first[0];
		figur->y[r] = (int)figur->y[r] - (int)first[1];
		r++;
	}
	create_list(figures, figur);
}


