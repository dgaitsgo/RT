/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading_aa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/15 16:27:30 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "threads.h"

t_thread_aa			*create_env_tab_aa(t_window *window, t_scene *scene)
{
	t_thread_aa		env;
	t_thread_aa		*tab;
	int				i;

	env.window = window;
	env.scene = scene;
	env.thread_id = i;
	env.img = (char *)ft_memalloc(sizeof(char) * (SDL_HEIGHT * SDL_WIDTH * 4));
	ft_memcpy(env.img, window->frame_buffer, SDL_WIDTH * SDL_HEIGHT * 4);
	i = 0;
	tab = (t_thread_aa *)ft_memalloc(sizeof(t_thread_aa) * (NTHREAD_AA
				* NTHREAD_AA));
	while (i < NTHREAD_AA * NTHREAD_AA)
	{
		ft_memcpy((void *)&tab[i], &env, sizeof(t_thread_aa));
		tab[i].thread_id = i;
		i++;
	}
	return (tab);
}

pthread_t			*create_thread_tab_aa(int size)
{
	pthread_t		*tab;

	tab = (pthread_t *)ft_memalloc(sizeof(pthread_t) * size);
	return (tab);
}

int					multi_threading_aa(t_window *window, t_scene *scene)
{
	pthread_t		*tab;
	t_thread_aa		*e_tab;
	void			*ret;
	int				i;

	i = 0;
	tab = create_thread_tab_aa(NTHREAD_AA * NTHREAD_AA);
	e_tab = create_env_tab_aa(window, scene);
	while (i < NTHREAD_AA * NTHREAD_AA)
	{
		if (pthread_create(&tab[i], NULL, launch_anti_aliasing, &e_tab[i]) != 0)
			kill_sdl(scene, "Cannot allocate pthread\n", 2);
		i++;
	}
	i = 0;
	while (i < NTHREAD_AA * NTHREAD_AA)
	{
		(void)pthread_join(tab[i], &ret);
		i++;
	}
	free(e_tab[0].img);
	free(e_tab);
	free(tab);
	return (0);
}
