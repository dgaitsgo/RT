/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 20:31:02 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/05/06 16:21:33 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*fill_line(char *line, char *ex_buff)
{
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	while (ex_buff[i] != '\n' && ex_buff[i] != '\0')
		i++;
	if (!(temp = ft_memalloc(i + ft_strlen(line))))
		return (NULL);
	ft_strcat(temp, line);
	ft_strncat(temp, ex_buff, i);
	return (temp);
}

static void	multi_fd(t_gnl **gnl, int fd)
{
	t_gnl *temp;

	temp = *gnl;
	(*gnl)->right = ft_memalloc(sizeof(t_gnl));
	*gnl = (*gnl)->right;
	(*gnl)->buff = ft_memalloc(BUFF_SIZE + 1);
	(*gnl)->fd = fd;
	(*gnl)->bsn = NULL;
	(*gnl)->right = NULL;
	(*gnl)->left = temp;
}

static int	gnl_mem(char **line, t_gnl **gnl, int fd)
{
	if (!(*line = malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	ft_memset(*line, 0, BUFF_SIZE + 1);
	if (!*gnl)
	{
		if (!(*gnl = ft_memalloc(sizeof(t_gnl))))
			return (0);
		if (!((*gnl)->buff = ft_memalloc(BUFF_SIZE + 1)))
			return (0);
		(*gnl)->fd = fd;
		(*gnl)->bsn = NULL;
		(*gnl)->left = NULL;
		(*gnl)->right = NULL;
		return (1);
	}
	while ((*gnl)->left && (*gnl)->fd != fd)
		*gnl = (*gnl)->left;
	while ((*gnl)->right && (*gnl)->fd != fd)
		*gnl = (*gnl)->right;
	if (fd != (*gnl)->fd)
		multi_fd(gnl, fd);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl;
	int				ret;

	if ((fd < 0) || (!line))
		return (-1);
	if (gnl_mem(line, &gnl, fd) != 1)
		return (-1);
	while (gnl->bsn || (ret = read(fd, gnl->buff, BUFF_SIZE)))
	{
		if (gnl->bsn && (*line = fill_line(*line, gnl->bsn + 1)))
		{
			if ((gnl->bsn = ft_strchr(gnl->bsn + 1, '\n')) != NULL)
				return (1);
			ret = read(fd, gnl->buff, BUFF_SIZE);
		}
		if (ret < 0)
			return (-1);
		gnl->buff[ret] = '\0';
		*line = fill_line(*line, gnl->buff);
		if (*line == NULL)
			return (0);
		if ((gnl->bsn = ft_strchr(gnl->buff, '\n')) != NULL)
			return (1);
	}
	return (ret || **line ? 1 : 0);
}
