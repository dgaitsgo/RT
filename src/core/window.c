/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/07 16:00:56 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector		get_pixel_color(t_window *window, char *img, int x, int y)
{
	t_vector	color;
	int			i;

	i = (x * SDL_DEPTH >> 3) + y * SDL_BPL;
	color.x = img[i];
	color.y = img[i + 1];
	color.z = img[i + 2];
	color.w = img[i + 3];
	rgb_to_normal(&color);
	return (color);
}

void			initialize_window(t_window *window)
{
	SDL_WIDTH = SDL_WIDTH ? SDL_WIDTH : DEFAULT_WINDOW_WIDTH;
	SDL_HEIGHT = SDL_HEIGHT ? SDL_HEIGHT : DEFAULT_WINDOW_HEIGHT;
	SDL_DEPTH = 32;
	SDL_BPL = SDL_WIDTH * (SDL_DEPTH / 8);
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WINDOW = SDL_CreateWindow("ray tracing", 100, 200,
	SDL_WIDTH, SDL_HEIGHT, 0);
	SDL_SCREEN = SDL_GetWindowSurface(SDL_WINDOW);
	SDL_FRAME_BUFFER = malloc(SDL_WIDTH * SDL_HEIGHT * 4);
	SDL_IMAGE = SDL_CreateRGBSurfaceFrom(SDL_FRAME_BUFFER,
	SDL_WIDTH, SDL_HEIGHT, SDL_DEPTH, SDL_BPL, 0, 0, 0, 0);
	window->z_buffer = malloc(sizeof(double) * SDL_WIDTH * SDL_HEIGHT);
	window->aspect_ratio = (double)SDL_WIDTH / (double)SDL_HEIGHT;
	window->inverse_aspect_ratio = (double)SDL_HEIGHT / (double)SDL_WIDTH;
}

void			kill_sdl(t_scene *scene, char *str, int fd)
{
	t_window	*window;

	window = &scene->window;
	SDL_FreeSurface(window->image);
	SDL_FreeSurface(window->screen);
	SDL_DestroyWindow(SDL_WINDOW);
	SDL_Quit();
	ft_putstr_fd(str, fd);
	exit(0);
}

void			put_pixel(t_window *window,
				t_vector pos, t_vector color, int depth_test)
{
	int i;
	int	zindex;

	zindex = (int)pos.y + window->width + (int)pos.x;
	i = ((int)pos.x * SDL_DEPTH >> 3) + (int)pos.y * SDL_BPL;
	if (pos.x < 0 || pos.x >= window->width ||
		pos.y < 0 || pos.y >= window->height)
		return ;
	if (color.x < 0 || color.x > 255)
		return ;
	if (color.y < 0 || color.y > 255)
		return ;
	if (color.z < 0 || color.z > 255)
		return ;
	SDL_FRAME_BUFFER[i] = color.z;
	SDL_FRAME_BUFFER[i + 1] = color.y;
	SDL_FRAME_BUFFER[i + 2] = color.x;
	SDL_FRAME_BUFFER[i + 3] = 1;
	window->z_buffer[(int)pos.y + window->width + (int)pos.x] = pos.z;
}

void			put_image(t_scene *scene)
{
	t_window	*window;

	window = &scene->window;
	SDL_BlitSurface(SDL_IMAGE, NULL, SDL_SCREEN, NULL);
	SDL_UpdateWindowSurface(SDL_WINDOW);
	poll_events(scene);
}
