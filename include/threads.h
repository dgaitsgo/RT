/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiarra <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:40:10 by mdiarra           #+#    #+#             */
/*   Updated: 2017/03/08 11:44:01 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __THREADS_H
# define __THREADS_H

# include "ray_trace.h"
# include <pthread.h>

typedef struct
{
	int						x;
	int						y;
	int						max_x;
	int						max_y;
	int						thread_id;
	t_scene					*scene;
	t_window				*window;
	t_camera				*camera;
	t_vector				color;
}							t_thread_env;

typedef struct
{
	int			thread_id;
	t_scene		*scene;
	t_window	*window;
	char		*img;
}				t_thread_aa;

void			*launch_anti_aliasing(void *arg);
pthread_t		*create_thread_tab_aa(int size);
t_thread_aa		*create_env_tab_aa(t_window *window, t_scene *scene);

int				init_threading(t_window *window,
							t_camera *camera,
							t_scene *scene);
int				multi_threading_aa(t_window *window, t_scene *scene);

#endif
