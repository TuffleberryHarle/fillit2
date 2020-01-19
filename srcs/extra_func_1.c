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

int		connect_check(unsigned *row, unsigned *col, unsigned *num, char **file)
{
	*col = 0;
	*num = 0;
	while (*row < 4)
	{
		while (file[*row][*col] != '\0')
		{
			if (file[*row][*col] == '#')
			{
				if (*col > 0 && file[*row][*col - 1] == '#')
					(*num)++;
				if (*row > 0 && file[*row - 1][*col] == '#')
					(*num)++;
				if (*col < 3 && file[*row][*col + 1] == '#')
					(*num)++;
				if (*row < 3 && file[*row + 1][*col] == '#')
					(*num)++;
			}
			(*col)++;
		}
		(*row)++;
		*col = 0;
	}
	if (*num == 6 || *num == 8)
		return (1);
	return (0);
}

void	list_create(t_list **figures, t_figure *figur)
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

void	coord_correct(t_figure *fig, t_list **figures, const int *first)
{
	int			r;

	r = 0;
	while (r < 4)
	{
		fig->x[r] = (int)fig->x[r] - (int)first[0];
		fig->y[r] = (int)fig->y[r] - (int)first[1];
		r++;
	}
	list_create(figures, fig);
}


