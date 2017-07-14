/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tone_mapping.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 13:38:59 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/08 11:48:04 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TONE_MAP_H
# define __TONE_MAP_H

# include "vector.h"

# define TONE_MAP_A			0.15
# define TONE_MAP_B			0.50
# define TONE_MAP_C			0.10
# define TONE_MAP_D			0.20
# define TONE_MAP_E			0.02
# define TONE_MAP_F			0.30
# define TONE_MAP_W			11.2
# define TONE_MAP_EXPOSURE	0.012
# define GAMMA				2.2

typedef struct
{
	double		a;
	double		b;
	double		c;
	double		d;
	double		e;
	double		f;
	double		w;
	double		exposure;
	double		white;
	double		gamma;
}				t_tone_map;

void			initialize_tone_map(t_tone_map *t);
void			tone_map(t_vector *color, t_tone_map *t);

#endif
