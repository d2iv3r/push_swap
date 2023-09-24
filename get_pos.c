/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:08:10 by efarhat           #+#    #+#             */
/*   Updated: 2023/04/10 00:58:31 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*lst_arr(t_list *stack, int size)
{
	int		i;
	t_list	*p;
	int		*arr;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (0);
	p = stack;
	i = 0;
	while (p)
	{
		arr[i] = p->data;
		p = p->next;
		i++;
	}
	return (arr);
}

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	get_pos(t_list **stack, int size)
{
	t_list	*p;
	int		i;
	int		*arr;

	if (!*stack)
		return ;
	arr = lst_arr(*stack, size);
	if (!arr)
		return ;
	sort_arr(arr, size);
	p = *stack;
	i = 0;
	while (p)
	{
		if (p->data == arr[i])
		{
			p->pos = i + 1;
			p = p->next;
			i = -1;
		}
		i++;
	}
	free(arr);
}
