/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:44:41 by tharle            #+#    #+#             */
/*   Updated: 2019/11/17 16:29:35 by tharle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		gnl_2(char **arr, char **line, int fd, int ret)
{
	char	*tmp;
	int		pos;

	pos = 0;
	while (arr[fd][pos] != '\n' && arr[fd][pos] != '\0')
		pos++;
	if (arr[fd][pos] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(arr[fd]);
		ft_strdel(&arr[fd]);
	}
	else if (arr[fd][pos] == '\n')
	{
		tmp = ft_strdup(arr[fd] + pos + 1);
		*line = ft_strsub(arr[fd], 0, pos);
		free(arr[fd]);
		arr[fd] = tmp;
		if (arr[fd][0] == '\0')
			ft_strdel(&arr[fd]);
	}
	return (1);
}

int		gnl_1(char **arr, char **line, int fd, char *buf)
{
	int		ret;
	char	*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!arr[fd])
			arr[fd] = ft_strnew(1);
		tmp = ft_strjoin(arr[fd], buf);
		free(arr[fd]);
		arr[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (!arr[fd] || arr[fd][0] == '\0'))
		return (0);
	return (gnl_2(arr, line, fd, ret));
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*arr[255];

	if (fd < 0 || !line)
		return (-1);
	return (gnl_1(arr, line, fd, buf));
}
