/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:22:25 by efarhat           #+#    #+#             */
/*   Updated: 2023/04/09 23:56:49 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strlen_v2(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_v2(char *s, char *buff)
{
	int		i;
	int		j;
	char	*str;

	if (!s)
	{
		s = (char *)malloc(1 * sizeof(char));
		if (!s)
			return (0);
		s[0] = '\0';
	}
	if (!buff)
		return (0);
	str = malloc(sizeof(char) * ((ft_strlen_v2(s) + ft_strlen_v2(buff)) + 1));
	if (!str)
		return (0);
	i = -1;
	j = 0;
	while (s[++i] != '\0')
		str[i] = s[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen_v2(s) + ft_strlen_v2(buff)] = '\0';
	free(s);
	return (str);
}
