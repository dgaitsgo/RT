/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   film.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:04:02 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/08 10:51:44 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILM_H
# define __FILM_H

# include "tone_map.h"

struct s_palette;

typedef struct
{
	int					quantize;
	int					ldr;
	t_tone_map			tone_map;
	struct s_palette	**color_map;
}						t_film;

#endif
