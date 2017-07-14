/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/15 15:43:36 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "threads.h"
#include <errno.h>

t_thread_env	*create_env_tab(t_thread_env e)
{
	t_thread_env	*tab;
	int				i;

	i = 0;
	tab = (t_thread_env *)ft_memalloc(sizeof(t_thread_env) *
			(NTHREAD * NTHREAD));
	while (i < NTHREAD * NTHREAD)
	{
		ft_memcpy(&tab[i], &e, sizeof(t_thread_env));
		tab[i].thread_id = i;
		tab[i].x = (e.window->width / NTHREAD) * (i % NTHREAD);
		tab[i].y = (e.window->height / NTHREAD) * (i / NTHREAD);
		tab[i].max_x = tab[i].x + (e.window->width / NTHREAD);
		tab[i].max_y = tab[i].y + (e.window->height / NTHREAD);
		i++;
	}
	return (tab);
}

pthread_t		*create_thread_tab(int size)
{
	pthread_t	*tab;

	tab = (pthread_t *)ft_memalloc(sizeof(pthread_t) * size);
	return (tab);
}

t_thread_env	create_thread_environememt(t_window *window,
							t_camera *camera,
							t_scene *scene)
{
	t_thread_env	env;

	env.window = window;
	env.scene = scene;
	env.camera = camera;
	env.color = init_color(0, 0, 0);
	env.thread_id = 0;
	env.x = 0;
	env.y = 0;
	env.max_x = 0;
	env.max_y = 0;
	return (env);
}

int				init_threading(t_window *window,
							t_camera *camera,
							t_scene *scene)
{
	pthread_t		*tab;
	t_thread_env	env;
	t_thread_env	*e_tab;
	void			*ret;
	int				error;

	tab = create_thread_tab(NTHREAD * NTHREAD);
	env = create_thread_environememt(window, camera, scene);
	e_tab = create_env_tab(env);
	while (env.thread_id < NTHREAD * NTHREAD)
	{
		if ((error = pthread_create(&tab[env.thread_id], NULL, render,
					&e_tab[env.thread_id])) != 0)
			kill_sdl(scene, "Cannot allocate pthread\n", 2);
		env.thread_id++;
	}
	env.thread_id = 0;
	while (env.thread_id < NTHREAD * NTHREAD)
	{
		(void)pthread_join(tab[env.thread_id], &ret);
		env.thread_id++;
	}
	free(e_tab);
	free(tab);
	return (0);
}
