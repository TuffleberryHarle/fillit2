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

char			**set_dots(int total);
int				get_start_total(int count);
t_list			*get_item(t_list *figures, int current_item);
void			clear(int total, char **map, char c);
char			**solve_tetris(t_list *figure, int count);
void			print_map(char **map);
void			clear_map(char **map);
int				conect_check(int *r, int *c, int *num, char **file);
void			create_list(t_list **figures, t_figure *figur);
void			correct_coord(t_figure *fig, t_list **figures, int *first);
int				tetr_check1(char **line, int *row, char **figure, int *i);
int             is_valid(int ac, char **av, int *fig_num, t_list **figures);
void			clear_list(t_list **figures);

#endif
