/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:48:16 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/08 11:48:24 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILITY_H
# define __UTILITY_H

void			multi_free_4(void *addr1, void *addr2, void *addr3,
					void *addr4);
void			free_if(void *ptr);
void			initialize_to_zero_2(int *a, int *b);
#endif
