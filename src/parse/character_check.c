/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2017/02/11 09:06:37 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				is_space(char c)
{
	if (c == '\n' || c == ' ' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int				lower_case_letter(char c)
{
	if ((c >= 'a' && c <= 'z') || c == '_')
		return (1);
	return (0);
}

int				capital_letter(char c)
{
	if ((c >= 'A' && c <= 'Z') || c == '_')
		return (1);
	return (0);
}

int				balancing_symbol(char c)
{
	if (c == '<' || c == '>' || c == '{' || c == '}' || c == '\"')
		return (1);
	return (0);
}

int				is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c == '-')
		return (1);
	if (c == '.')
		return (1);
	return (0);
}
