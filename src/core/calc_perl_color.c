/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_perl_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/08 17:44:19 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

double				turbulence(t_vector point, int turb_size,
								unsigned char hash[512])
{
	double			ret;
	double			size;
	double			n;

	ret = 0;
	size = turb_size;
	while (size >= 1)
	{
		n = p_noise_3d(point.x / size, point.y / size, point.z / size, hash);
		ret += ((n + 1) / 2) * size;
		size /= 2.0;
	}
	ret = ret / (2 * turb_size);
	return (ret);
}

double				calc_n_pure(t_vector point, t_texture texture,
									unsigned char hash[512])
{
	double			n;

	point.x = point.x / texture.repetition.x;
	point.y = point.y / texture.repetition.y;
	point.z = point.z / texture.repetition.z;
	n = turbulence(point, texture.turb_size, hash);
	n = (n + 1) / 2;
	return (n);
}

double				calc_n_marble(t_vector point, t_texture texture,
									unsigned char hash[512])
{
	double			n;

	n = 0;
	n = cos((point.x / texture.repetition.x) +
			(point.y / texture.repetition.y) +
			(point.z / texture.repetition.z) +
			(texture.turb_power * turbulence(point, texture.turb_size, hash)));
	n = (n + 1) / 2;
	return (n);
}

t_vector			calc_perl(t_vector point, t_texture texture,
						unsigned char hash[512])
{
	double			n;

	n = 0;
	if (texture.type == PURE_NOISE)
		n = calc_n_pure(point, texture, hash);
	else if (texture.type == MARBLE)
		n = calc_n_marble(point, texture, hash);
	else if (texture.type == WOOD)
	{
		n = (20 *
				p_noise_3d(point.x / 100, point.y / 100, point.z / 100, hash));
		n = fabs(n - (int)(n));
	}
	return (linear_inter(texture.color_1, texture.color_2, n));
}
