/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:51:49 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/23 16:49:05 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WINDOW_H
# define __WINDOW_H

# include "ray_trace.h"
# include "/Library/Frameworks/SDL2.framework/Versions/A/Headers/SDL.h"

# define SDL_WINDOW			window->window
# define SDL_SCREEN			window->screen
# define SDL_IMAGE			window->image
# define SDL_FRAME_BUFFER	window->frame_buffer
# define SDL_WIDTH			window->width
# define SDL_HEIGHT			window->height
# define SDL_DEPTH			window->depth
# define SDL_BPL			window->bytes_per_line
# define SDL_EVENT			window->event
# define KEY				SDL_EVENT.key.keysym.sym

typedef	struct		s_sdlwindow
{
	SDL_Window		*window;
	SDL_Surface		*screen;
	SDL_Surface		*image;
	SDL_Event		event;
	t_matrix		screen_space;
	double			aspect_ratio;
	double			inverse_aspect_ratio;
	double			*z_buffer;
	char			*frame_buffer;
	int				width;
	int				height;
	int				depth;
	int				bytes_per_line;
	int				flags;
}					t_window;

void				put_pixel(t_window *window, t_vector pos,
						t_vector color, int depth);
void				initialize_window(t_window *window);
t_vector			get_pixel_color(t_window *window, char *img, int x, int y);
#endif
