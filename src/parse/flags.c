/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/11 09:07:50 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "flags.h"

int	check_repeat(int *flag_location, int test_flag)
{
	if (!BIT_CHECK(*flag_location, test_flag))
		BIT_SET(*flag_location, test_flag);
	else
		parse_error(REPEAT_SYMBOL, NULL, 0);
	return (1);
}
