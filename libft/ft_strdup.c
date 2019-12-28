/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:38:45 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/29 16:59:49 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*cp_src;
	size_t	len;

	len = ft_strlen(src);
	if (!(cp_src = ft_strnew(len)))
		return (NULL);
	ft_strcpy(cp_src, src);
	return (cp_src);
}
