/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:40:44 by mcanhand          #+#    #+#             */
/*   Updated: 2019/05/20 17:53:12 by mcanhand         ###   ########.fr       */
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

int		simple_check(char **line, int *text, char **figure, int *i)
{
	static int tetr;

	if (*text < 5 && tetr == 0)
		tetr = 0;
	if (!**line)
	{
		if (*text == 5)
		{
			*text = 1;
			tetr++;
			*i = 0;
			return (1);
		}
		return (0);
	}
	if ((ft_strlen(*line)) == 4)
	{
		figure[*i] = ft_strdup(*line);
		*text += 1;
		free(*line);
		*i += 1;
	}
	if (tetr >= 25 || *text > 5)
		return (0);
	return (1);
}
