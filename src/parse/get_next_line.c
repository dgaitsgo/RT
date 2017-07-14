/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/11 09:07:53 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*fill_line(char *line, char *ex_buff)
{
	char	*temp;
	int		i;

	i = 0;
	while (ex_buff[i] != '\n' && ex_buff[i] != '\0')
		i++;
	if (!(temp = ft_memalloc(i + ft_strlen(line))))
		return (NULL);
	ft_strcat(temp, line);
	ft_strncat(temp, ex_buff, i);
	free(line);
	return (temp);
}

static void	multi_fd(t_gnl **gnl, int fd)
{
	t_gnl *temp;

	temp = *gnl;
	(*gnl)->right = (t_gnl *)ft_memalloc(sizeof(t_gnl));
	*gnl = (*gnl)->right;
	(*gnl)->buff = ft_memalloc(BUFF_SIZE + 1);
	(*gnl)->fd = fd;
	(*gnl)->bsn = NULL;
	(*gnl)->right = NULL;
	(*gnl)->left = temp;
}

static void	gnl_mem(char **line, t_gnl **gnl, int fd)
{
	*line = ft_memalloc(1);
	if (!*gnl)
	{
		if (!(*gnl = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
			return ;
		if (!((*gnl)->buff = ft_memalloc(BUFF_SIZE + 1)))
			return ;
		(*gnl)->fd = fd;
		(*gnl)->bsn = NULL;
		(*gnl)->left = NULL;
		(*gnl)->right = NULL;
	}
	while ((*gnl)->left && (*gnl)->fd != fd)
		*gnl = (*gnl)->left;
	while ((*gnl)->right && (*gnl)->fd != fd)
		*gnl = (*gnl)->right;
	if (fd != (*gnl)->fd)
		multi_fd(gnl, fd);
}

int			get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl;
	int				ret;

	if ((fd < 0) || (!line))
		return (-1);
	gnl_mem(line, &gnl, fd);
	while (gnl->bsn || (ret = read(fd, gnl->buff, BUFF_SIZE)))
	{
		if (gnl->bsn)
		{
			*line = fill_line(*line, gnl->bsn + 1);
			if ((gnl->bsn = ft_strchr(gnl->bsn + 1, '\n')) != NULL)
				return (1);
			ret = read(fd, gnl->buff, BUFF_SIZE);
		}
		if (ret < 0)
			return (-1);
		gnl->buff[ret] = '\0';
		*line = fill_line(*line, gnl->buff);
		if ((gnl->bsn = ft_strchr(gnl->buff, '\n')) != NULL)
			return (1);
	}
	return (ret || **line ? 1 : 0);
}
