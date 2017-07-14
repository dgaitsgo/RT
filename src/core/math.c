/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/04/23 00:33:01 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

double		square(double n)
{
	return (n * n);
}

double		largest(double a, double b)
{
	return (a > b ? a : b);
}

int			sgn(int x)
{
	return ((x > 0) - (x < 0));
}

double		smallest(double a, double b)
{
	return (a > b ? b : a);
}

int			solve_quadratic(t_quadratic *q)
{
	double	discriminant;
	double	e;
	double	denom;

	discriminant = (q->b * q->b) - (4.0 * q->a * q->c);
	if (discriminant < MIN_PRECISION)
		return (0);
	e = sqrt(discriminant);
	if (q->a >= -MIN_PRECISION && q->a <= MIN_PRECISION)
	{
		q->t1 = -q->c / q->b;
		q->t2 = q->t1;
	}
	else
	{
		denom = 2.0 * q->a;
		q->t1 = (-q->b - e) / denom;
		q->t2 = (-q->b + e) / denom;
	}
	if (q->t1 > q->t2)
		swap(&q->t1, &q->t2);
	if (q->t1 < MIN_PRECISION && q->t2 < MIN_PRECISION)
		return (0);
	return (1);
}
