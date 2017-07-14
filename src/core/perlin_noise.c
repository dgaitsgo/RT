/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin_noise.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/28 14:42:22 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void			take_part(double x, double y, double z, t_noise *env)
{
	if (x >= 0)
		env->i_part_x = (int)(x);
	else
		env->i_part_x = (int)(x) - 1;
	if (y >= 0)
		env->i_part_y = (int)(y);
	else
		env->i_part_y = (int)(y) - 1;
	if (z >= 0)
		env->i_part_z = (int)(z);
	else
		env->i_part_z = (int)(z) - 1;
	env->f_part.x = x - env->i_part_x;
	env->f_part.y = y - env->i_part_y;
	env->f_part.z = z - env->i_part_z;
	env->i_part_x &= 255;
	env->i_part_y &= 255;
	env->i_part_z &= 255;
}

t_vector		gt_grad(t_noise *env, int x, int y, int z)
{
	int			tmp;

	tmp = env->hash[env->i_part_x + x];
	tmp = env->hash[env->i_part_y + y + tmp];
	tmp = env->hash[env->i_part_z + z + tmp];
	return (env->grad_3d[tmp & 15]);
}

double			dot(t_noise *env, double x, double y, double z)
{
	t_vector	tmp;
	double		ret;

	tmp = gt_grad(env, x, y, z);
	ret = tmp.x * (env->f_part.x - x);
	ret += tmp.y * (env->f_part.y - y);
	ret += tmp.z * (env->f_part.z - z);
	return (ret);
}

void			calc_grad(t_noise *env)
{
	env->grad_000 = dot(env, 0, 0, 0);
	env->grad_001 = dot(env, 0, 0, 1);
	env->grad_010 = dot(env, 0, 1, 0);
	env->grad_011 = dot(env, 0, 1, 1);
	env->grad_100 = dot(env, 1, 0, 0);
	env->grad_101 = dot(env, 1, 0, 1);
	env->grad_110 = dot(env, 1, 1, 0);
	env->grad_111 = dot(env, 1, 1, 1);
}

double			p_noise_3d(double x, double y, double z,
		unsigned char hash[512])
{
	t_noise		env;
	double		ret;

	env.hash = hash;
	take_part(x, y, z, &env);
	init_grad(&env);
	calc_grad(&env);
	env.poly = quintic_poly(env.f_part);
	env.inter_1 = lin_double_inter(env.grad_000, env.grad_100, env.poly.x);
	env.inter_2 = lin_double_inter(env.grad_010, env.grad_110, env.poly.x);
	env.inter_3 = lin_double_inter(env.inter_1, env.inter_2, env.poly.y);
	env.inter_1 = lin_double_inter(env.grad_001, env.grad_101, env.poly.x);
	env.inter_2 = lin_double_inter(env.grad_011, env.grad_111, env.poly.x);
	ret = lin_double_inter(env.inter_1, env.inter_2, env.poly.y);
	ret = lin_double_inter(env.inter_3, ret, env.poly.z);
	return (ret);
}
