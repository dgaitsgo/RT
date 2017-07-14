/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/19 15:05:05 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void		draw_line_down(t_bresenham b,
							t_line line, t_vector color, t_window *window)
{
	b.d = b.ay - (b.ax >> 1);
	while (1)
	{
		put_pixel(window, new_vector(b.x, b.y, 0), color, 0);
		if (b.x == line.x2)
			return ;
		if (b.d >= 0)
		{
			b.y += b.sy;
			b.d -= b.ax;
		}
		b.x += b.sx;
		b.d += b.ay;
	}
}

void		draw_line_up(t_bresenham b,
			t_line line, t_vector color, t_window *window)
{
	b.d = b.ax - (b.ay >> 1);
	while (1)
	{
		put_pixel(window, new_vector(b.x, b.y, 0), color, 0);
		if (b.y == line.y2)
			return ;
		if (b.d >= 0)
		{
			b.x += b.sx;
			b.d -= b.ay;
		}
		b.y += b.sy;
		b.d += b.ax;
	}
}

void		draw_line(t_line line, t_vector color, t_window *window)
{
	t_bresenham b;

	b.dx = line.x2 - line.x1;
	b.ax = abs(b.dx) << 1;
	b.sx = sgn(b.dx);
	b.dy = line.y2 - line.y1;
	b.ay = abs(b.dy) << 1;
	b.sy = sgn(b.dy);
	b.x = line.x1;
	b.y = line.y1;
	if (b.ax > b.ay)
		draw_line_down(b, line, color, window);
	else
		draw_line_up(b, line, color, window);
}
