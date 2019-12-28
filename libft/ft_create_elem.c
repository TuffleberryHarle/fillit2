/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:49:03 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/22 17:49:19 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_create_elem(void *data)
{
	t_list *new_item;

	if (!(new_item = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (new_item)
	{
		new_item->content = data;
		new_item->next = NULL;
	}
	return (new_item);
}
