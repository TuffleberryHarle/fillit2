/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 16:52:56 by galiza            #+#    #+#             */
/*   Updated: 2019/05/15 14:59:51 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_figure
{
	int			*x;
	int			*y;
}				t_figure;

char			**dots_set(unsigned total);
unsigned				get_start_total(unsigned count);
t_list			*get_item(t_list *figures, unsigned int current_item);
void			clear_to_expand(unsigned int total, char **map, char c);
char			**tetr_solve(t_list *figures, unsigned count);
void			map_print(char **map);
void			map_clear(char **map);
int				connect_check(unsigned *r, unsigned *c, unsigned *num, char **file);
void			list_create(t_list **figures, t_figure *figur);
void			coord_correct(t_figure *fig, t_list **figures, const int *first);
int				tetr_check1(char **line, unsigned *row, char **figure, unsigned *i);
int             is_valid(int ac, char **av, unsigned *fig_num, t_list **figures);
void			list_clear(t_list **figures);

#endif
