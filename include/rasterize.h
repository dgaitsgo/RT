/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rasterize.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:21:33 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/08 11:36:09 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RASTERIZE_H
# define __RASTERIZE_H

typedef struct
{
	int			x1;
	int			x2;
	int			y1;
	int			y2;
}				t_line;

typedef struct
{
	int			d;
	int			x;
	int			y;
	int			ax;
	int			ay;
	int			sx;
	int			sy;
	int			dx;
	int			dy;
}				t_bresenham;

t_line			init_line(int x1, int y1, int x2, int y2);
t_vector		perspective_divide(t_vector v);

#endif
