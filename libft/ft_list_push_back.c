/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 16:42:34 by galiza            #+#    #+#             */
/*   Updated: 2019/05/10 18:40:03 by galiza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*temp_list;

	temp_list = *begin_list;
	if (temp_list)
	{
		while (temp_list->next)
			temp_list = temp_list->next;
		temp_list->next = ft_create_elem(data);
	}
	else
		*begin_list = ft_create_elem(data);
}
