/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:47:04 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/08 10:50:10 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __COLOR_H
# define __COLOR_H

# include "vector.h"
# include "film.h"
# include "tone_map.h"

typedef struct		s_palette
{
	int				r;
	int				g;
	int				b;
}					t_palette;

t_vector			nearest_color_neighbor(t_palette **palette, t_vector color);
t_palette			**gen_lowres_color_table(void);
void				process_color(t_vector *color, t_film *film);
t_vector			init_color(double r, double g, double b);
void				clamp_color(t_vector *color);
void				normal_to_rgb(t_vector *color);
void				rgb_to_normal(t_vector *color);
int					out_of_gamut(t_vector *color);
void				floor_and_ceiling(t_vector *color);
void				floor_color(t_vector *color);
int					under_floor(t_vector *color);
t_vector			moy_color(t_vector *color, double sub);

#endif
