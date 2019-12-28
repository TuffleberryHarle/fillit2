/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:57:02 by mcanhand          #+#    #+#             */
/*   Updated: 2019/04/09 17:08:37 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sbstr;

	i = 0;
	if (!s)
		return (NULL);
	if (!s[i])
		return (NULL);
	if (!(sbstr = (char *)malloc(len + 1)))
		return (NULL);
	while (i < len)
		sbstr[i++] = s[start++];
	sbstr[i] = '\0';
	return (sbstr);
}
