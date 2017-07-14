/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <trecomps@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:27:35 by trecomps          #+#    #+#             */
/*   Updated: 2017/03/08 11:23:24 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOISE_H
# define NOISE_H

# include "vector.h"

typedef	struct		s_noise
{
	int				i_part_x;
	int				i_part_y;
	int				i_part_z;
	t_vector		f_part;
	t_vector		grad_3d[16];
	unsigned char	*hash;
	double			grad_000;
	double			grad_001;
	double			grad_010;
	double			grad_011;
	double			grad_100;
	double			grad_101;
	double			grad_110;
	double			grad_111;
	t_vector		poly;
	double			inter_1;
	double			inter_2;
	double			inter_3;
}					t_noise;

void				init_grad(t_noise *env);
double				lin_double_inter(double a, double b, double t);
t_vector			quintic_poly(t_vector f_part);

#endif
