/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 21:30:18 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/08 11:35:17 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RANDOM_H
# define __RANDOM_H

# include "vector.h"
# include "shader.h"

double				random_double(double max);
int					random_int(double max);
t_vector			random_color(void);
t_material			random_material(void);

#endif
