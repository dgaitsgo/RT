/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quantize_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 12:30:01 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/03 15:54:54 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_palette		**get_color_map_memory(void)
{
	t_palette	**color_map;
	int			i;

	i = 0;
	color_map = malloc(sizeof(t_palette *) * 256);
	while (i < 256)
	{
		color_map[i] = malloc(sizeof(t_palette));
		i++;
	}
	return (color_map);
}

t_palette		**gen_lowres_color_table(void)
{
	t_palette		**eight_bit_table;
	t_color_vector	c;
	int				i;

	eight_bit_table = get_color_map_memory();
	initialize_to_zero_2(&i, &c.r);
	while (c.r <= 255)
	{
		c.g = 0;
		while (c.g <= 255)
		{
			c.b = 0;
			while (c.b <= 255)
			{
				eight_bit_table[i]->r = c.r;
				eight_bit_table[i]->g = c.g;
				eight_bit_table[i]->b = c.b;
				i++;
				c.b += 51;
			}
			c.g += 51;
		}
		c.r += 51;
	}
	return (eight_bit_table);
}

t_vector		nearest_color_neighbor(t_palette **palette, t_vector color)
{
	int			i;
	t_vector	curr_neighbor;
	t_vector	closest_neighbor;
	double		smallest;
	double		current;

	i = 0;
	smallest = REALLY_BIG;
	while (i < 256)
	{
		curr_neighbor = new_vector(palette[i]->r, palette[i]->g, palette[i]->b);
		current = euclidean_distance3d(color, curr_neighbor);
		if (smallest > current)
		{
			smallest = current;
			closest_neighbor = curr_neighbor;
		}
		i++;
	}
	return (closest_neighbor);
}
