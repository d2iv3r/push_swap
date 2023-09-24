/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:05:44 by efarhat           #+#    #+#             */
/*   Updated: 2023/04/09 17:35:35 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

int	read_argv(char *argv[])
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] && argv[i][j] == 32)
			j++;
		if (!argv[i][j])
			return (0);
		i++;
	}
	return (1);
}

char	**split_argv(char *argv[])
{
	char	*s;
	char	*tmp;
	char	**arg;
	int		i;

	s = malloc(1 * sizeof(char));
	if (!s)
		return (NULL);
	s[0] = '\0';
	i = 1;
	while (argv[i])
	{
		tmp = s;
		s = ft_strjoin(s, argv[i]);
		free(tmp);
		i++;
	}
	arg = ft_split(s, ' ');
	free (s);
	if (!arg)
		return (NULL);
	return (arg);
}

int	check_dup(char **arg)
{
	int	i;
	int	j;

	if (!arg)
		return (0);
	i = 0;
	while (arg[i])
	{
		j = i + 1;
		while (arg[j])
		{
			if (ft_atoi_v2(arg[i]) == ft_atoi_v2(arg[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_argv(char *argv[])
{
	char	**arg;

	if (!read_argv(argv))
		return (0);
	arg = split_argv(argv);
	if (!arg || !*arg)
		return (0);
	if (!check_dup(arg))
		return (ft_clear(arg), 0);
	return (ft_clear(arg), 1);
}
