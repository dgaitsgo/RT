/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csg2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:27:10 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/22 14:28:06 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_node		*new_csg(void)
{
	t_node	*ret;

	if ((ret = (t_node *)ft_memalloc(sizeof(t_node))) == NULL)
		return (NULL);
	ret->left = NULL;
	ret->right = NULL;
	return (ret);
}
