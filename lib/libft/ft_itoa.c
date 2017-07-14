/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 17:02:02 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/02/17 22:36:08 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		push(char digit, int *index, char *s)
{
	(*index)++;
	s[*index] = digit;
}

static void		ft_putnbr_string(int nbr, int *index, char *s)
{
	if (nbr < 0)
	{
		push('-', index, s);
		if (nbr == -2147483648)
		{
			push('2', index, s);
			nbr = -147483648;
		}
		nbr = nbr * -1;
	}
	if (nbr / 10 > 0)
	{
		ft_putnbr_string(nbr / 10, index, s);
		ft_putnbr_string(nbr % 10, index, s);
	}
	else
		push(nbr + 48, index, s);
}

static int		num_size(int n)
{
	int neg;
	int nums;

	nums = 0;
	neg = n > 0 ? 0 : 1;
	if (n == -2147483647)
		return (11);
	n = n > 0 ? n : -n;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		nums++;
	}
	return (nums + neg);
}

char			*ft_itoa(int n)
{
	char	*number;
	int		adress;
	int		*index;

	adress = -1;
	index = &adress;
	if (!(number = (char *)malloc(sizeof(char) * (num_size(n) + 1))))
		return (NULL);
	ft_putnbr_string(n, index, number);
	number[*index + 1] = '\0';
	return (number);
}
