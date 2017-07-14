/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 09:41:46 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/08 10:50:30 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DEBUG_H
# define __DEBUG_H

# define CRED   "\x1B[31m"
# define CGRN   "\x1B[32m"
# define CYEL   "\x1B[33m"
# define CBLU   "\x1B[34m"
# define CMAG   "\x1B[35m"
# define CCYN   "\x1B[36m"
# define CWHT   "\x1B[37m"
# define CRESET "\x1B[0m"

# include "ray_trace.h"

void		debug_camera(char *title, t_camera *c);
void		debug_triangle(char *title, t_triangle *t);
void		debug_vector(char *title, t_vector *a);
void		debug_matrix(char *title, t_matrix m);
void		debug_bbox(char *title, t_bbox *bbox);

#endif
