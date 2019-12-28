/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:40:25 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/18 13:25:23 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if ((size + 1) < size)
		return (NULL);
	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	ft_bzero((void *)str, size + 1);
	return (str);
}
