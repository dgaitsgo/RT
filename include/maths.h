/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 21:24:44 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/08 11:19:03 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATHS_H
# define __MATHS_H

typedef struct
{
	double			min;
	double			max;
}					t_range;

typedef struct
{
	double			a;
	double			b;
	double			c;
	double			t1;
	double			t2;
}					t_quadratic;

t_range				range(double min, double max);
int					sgn(int x);
int					solve_quadratic(t_quadratic *q);
double				smallest(double a, double b);
double				largest(double a, double b);
double				square(double n);
void				swap(double *a, double *b);

#endif
