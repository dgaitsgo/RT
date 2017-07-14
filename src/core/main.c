/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/21 17:10:43 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "libft.h"
#include "threads.h"
#include "parse.h"

void		usage(void)
{
	ft_putstr("usage : ./rt [example.rtsd]\n");
	exit(0);
}

void		init_view_matrices(t_scene *scene)
{
	double width;
	double height;
	double fov;

	fov = scene->camera.half_height;
	width = scene->window.width;
	height = scene->window.height;
	init_screen_space(scene->screen_space, width, height);
	new_perspective_matrix(scene->projection, fov, width / height);
}

void		post_processing(t_scene *scene)
{
	if (scene->camera.anti_aliasing)
		multi_threading_aa(&scene->window, scene);
	if (scene->camera.visualize_bboxes)
		rasterize(scene);
}

int			main(int argc, char **argv)
{
	t_scene		scene;

	if (argc != 2 || !argv)
		usage();
	initialize_scene(&scene);
	if (parse(argv[1], &scene))
	{
		initialize_window(&scene.window);
		initialize_camera(&scene.camera, &scene.window);
		build_light_matrices(&scene);
		init_view_matrices(&scene);
		bound_entire_scene(&scene);
		init_threading(&scene.window, &scene.camera, &scene);
		post_processing(&scene);
		put_image(&scene);
	}
	return (0);
}
