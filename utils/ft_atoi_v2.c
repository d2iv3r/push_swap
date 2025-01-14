/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_v2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:19:26 by efarhat           #+#    #+#             */
/*   Updated: 2023/04/10 01:14:42 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_sign(const char *str, int *i, int *s)
{
	if (str[*i] == '-')
		*s = -1;
	*i += 1;
	if (!str[*i])
		ft_error();
}

int	ft_atoi_v2(const char *str)
{
	int					i;
	int					s;
	unsigned long long	nb;

	i = 0;
	s = 1;
	nb = 0;
	while (str[i] != '\0' && str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		check_sign(str, &i, &s);
	while (str[i] != '\0')
	{
		nb = nb * 10 + (str[i] - 48);
		if ((nb >= 2147483648 && s == 1) || !ft_isdigit(str[i]))
			ft_error();
		if (nb > 2147483648 && s == -1)
			ft_error();
		i++;
	}
	return (nb * s);
}
