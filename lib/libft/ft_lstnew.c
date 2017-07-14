/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 19:58:39 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/03/17 15:48:11 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *maillon;

	maillon = NULL;
	if ((content == NULL) || (*(void**)content == NULL) || (content_size == 0))
	{
		if (!(maillon = (t_list *)malloc(sizeof(t_list))))
			return (0);
		maillon->content_size = 0;
		maillon->content = NULL;
		return (maillon);
	}
	if (!(maillon = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(maillon->content = ft_memalloc(content_size)))
		return (NULL);
	maillon->content = ft_memcpy(maillon->content, content, content_size);
	maillon->content_size = content_size;
	maillon->next = NULL;
	return (maillon);
}
