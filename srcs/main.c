/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:55:38 by tharle            #+#    #+#             */
/*   Updated: 2019/09/07 18:58:08 by tharle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
 * So here we go and we have the main in here!
 */

int		main(int ac, char **av)
{
	char		**map;
	t_list		**figures;
	t_list		*figure;
	unsigned			fig_num;
	unsigned			curr;
	
	if (!(figures = (t_list**)malloc(sizeof(t_list*))))
		return (0);
	fig_num = 0;
	*figures = NULL;
	if (!(is_valid(ac, av, &fig_num, figures)))
	{
		if (ac != 2)
			ft_putstr("usage: fillit input_file\n");
		else
			ft_putstr("error\n");
		return (0);
	}
	figure = *figures;
	curr = fig_num;
	map = tetr_solve(figure, curr);
	map_print(map);
	map_clear(map);
	list_clear(figures);
}
