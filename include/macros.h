/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 21:27:26 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/08 11:18:46 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MACROS_H
# define __MACROS_H

# define MAX_OBJECTS 						8
# define PI									3.14159265359
# define FOV								45.0
# define FOV_RADIANS						PI * (FOV / 180.0)
# define DEFAULT_WINDOW_HEIGHT				400
# define DEFAULT_WINDOW_WIDTH				600
# define ASPECT_RATIO						WIDTH / HEIGHT
# define INVERSE_AR							HEIGHT / WIDTH
# define BCKGD								new_vector(0, 0, 0)
# define UP_VECTOR							new_vector(0, -1, 0)
# define MISS								0
# define HIT								1
# define FROM_INSIDE						-1
# define MAX_DEPTH							10
# define MAX_BOUND							FLT_MAX
# define MIN_PRECISION						0.00000001
# define CYLINDER_TOLERANCE 				0.000230
# define AIR_DENSITY						1.0
# define LIGHT_SIZE							40
# define AA_THRES							0.05
# define SH_GRAIN							10
# define NTHREAD							1
# define NTHREAD_AA							10
# define DELTA								0.2
# define REALLY_SMALL						-309812039840912
# define REALLY_BIG							309812039840912
# define Z_NEAR								1.0f
# define Z_FAR								100.0f
# define Z_RANGE							Z_FAR - Z_NEAR
# define RED								new_vector(0, 0, 255)
# define GREEN								new_vector(0, 255, 0)
# define BLUE								new_vector(255, 0, 0)
# define AA_SAMPLES							4
# define SI_LEFT							si->left[left]
# define SI_RIGHT							si->right[right]

# define MIN(a,b) (((a)<(b))?(a):(b))
# define MAX(a,b) (((a)>(b))?(a):(b))

#endif
