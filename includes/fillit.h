/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:55:38 by tharle            #+#    #+#             */
/*   Updated: 2019/09/07 18:58:08 by tharle           ###   ########.fr       */
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
	unsigned			*x;
	unsigned			*y;
}				t_figure;

char			**set_dots(unsigned total);
unsigned		get_start_total(unsigned count);
t_list			*get_item(t_list *figures, unsigned current_item);
void			clear(t_list *figures, unsigned total, char **map, char c);
char			**solve_tetris(t_list *figure, unsigned count);
void			print_map(char **map);
void			clear_map(char **map);
unsigned		conections_sum(unsigned *r, unsigned *c, unsigned *num, char **file);
void			create_list(t_list **figures, t_figure *figur);
void			correct_coords(t_figure *figur, t_list **figures, unsigned *first);
unsigned		simple_check(char **line, unsigned *text, char **figure, unsigned *i);
void			clear_list(t_list **figures);

#endif
