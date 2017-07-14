/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/08 15:50:28 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "threads.h"

int				above_threshold(t_thread_aa e, t_vector color, int x, int y)
{
	t_vector	win_color;
	t_window	*window;

	window = e.window;
	if (x < SDL_WIDTH - 1)
	{
		win_color = get_pixel_color(window, e.img, x + 1, y);
		win_color = vector_subtract(color, win_color);
		if (fabs(win_color.x) > AA_THRES || fabs(win_color.y) > AA_THRES
			|| fabs(win_color.z) > AA_THRES)
			return (1);
	}
	if (y < SDL_HEIGHT - 1)
	{
		win_color = get_pixel_color(window, e.img, x, y + 1);
		win_color = vector_subtract(color, win_color);
		if (fabs(win_color.x) > AA_THRES || fabs(win_color.y) > AA_THRES
			|| fabs(win_color.z) > AA_THRES)
			return (1);
	}
	return (0);
}

double			randomize(double start, int subdiv, double range)
{
	double		res;

	start += (subdiv * range);
	res = range * (((double)rand()) / (double)RAND_MAX);
	res += start;
	return (res);
}

int				launch_ray(int x, int y, t_thread_aa env, t_vector *color)
{
	int			i;
	int			j;
	t_ray		sub_ray;
	t_vector	tmp_color;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			tmp_color = new_vector(0, 0, 0);
			if ((i + j) != 0 && !(above_threshold(env,
							moy_color(color, i + 1 + (j * 4)), x, y)))
				return (i + 1 + (j * 4));
			sub_ray = generate_primary_ray(&env.scene->camera,
				randomize(x, i, 0.25), randomize(y, j, 0.25));
			*color = vector_add(trace_container(sub_ray, env.scene,
						&tmp_color, 0),
					*color);
			i++;
		}
		j++;
	}
	return (16);
}

int				anti_aliasing(int x, int y, t_thread_aa env)
{
	t_vector	color;
	int			sub;

	color = get_pixel_color(env.window, env.img, x, y);
	if (!above_threshold(env, color, x, y))
		return (0);
	set_vector(&color, 0, 0, 0);
	sub = launch_ray(x, y, env, &color);
	color = moy_color(&color, sub);
	process_color(&color, &env.scene->camera.film);
	put_pixel(env.window, new_vector(x, y, 0), color, 0);
	return (0);
}

void			*launch_anti_aliasing(void *arg)
{
	int			x;
	int			y;
	int			max_x;
	int			max_y;
	t_thread_aa	e;

	e = *(t_thread_aa*)arg;
	x = e.window->width / NTHREAD_AA * (e.thread_id % NTHREAD_AA);
	y = e.window->height / NTHREAD_AA * (e.thread_id / NTHREAD_AA);
	max_x = x + (e.window->width / NTHREAD_AA);
	max_y = y + (e.window->height / NTHREAD_AA);
	while (y < max_y)
	{
		x = e.window->width / NTHREAD_AA * (e.thread_id % NTHREAD_AA);
		while (x < max_x)
		{
			anti_aliasing(x, y, e);
			x++;
		}
		y++;
	}
	pthread_exit(0);
}
