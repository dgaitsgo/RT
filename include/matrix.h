/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 21:23:45 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 00:23:39 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATRIX_H
# define __MATRIX_H

# define M_TRANSLATION	3
# define X				0
# define Y				1
# define Z				2

typedef double				t_matrix[4][4];

void		init_screen_space(t_matrix m, double width, double height);
void		new_perspective_matrix(t_matrix m, double fov, double aspect_ratio);
void		print_matrix(t_matrix m);
void		copy_matrix(t_matrix dst, t_matrix src);
void		matrix_multiply(t_matrix res, t_matrix m1, t_matrix m2);
#endif
