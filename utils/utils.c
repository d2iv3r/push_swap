/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:30:31 by efarhat           #+#    #+#             */
/*   Updated: 2023/04/10 01:02:14 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst)
{
	t_list	*i;
	t_list	*j;

	if (!lst)
		return (0);
	i = lst;
	j = lst->next;
	while (i && j)
	{
		if (i->data > j->data)
			return (0);
		i = i->next;
		j = j->next;
	}
	return (1);
}

int	max_pos(t_list *stack)
{
	t_list	*p;
	int		max;

	if (!stack->next)
		return (stack->pos);
	p = stack->next;
	max = stack->pos;
	while (p)
	{
		if (p->pos > max)
			max = p->pos;
		p = p->next;
	}
	return (max);
}

t_list	*pos_in_stack(t_list **stack_a, int pos)
{
	t_list	*p;

	p = *stack_a;
	if (max_pos(*stack_a) < pos)
		pos = 0;
	while (p)
	{
		if (p->pos == pos + 1)
			return (p);
		p = p->next;
		if (!p)
		{
			p = *stack_a;
			pos++;
		}
	}
	return (0);
}

void	get_coord(t_list *stack)
{
	t_list	*p;
	int		i;

	if (!stack)
		return ;
	p = stack;
	i = 0;
	while (p)
	{
		p->up = i;
		p = p->next;
		i++;
	}
	p = stack;
	i--;
	while (p)
	{
		p->down = i;
		p = p->next;
		i--;
	}
}

t_list	*fill_stack(char *argv[])
{
	char	**arg;
	int		i;
	t_list	*lst;

	arg = split_argv(argv);
	if (!arg)
		return (NULL);
	i = 0;
	while (arg[i])
		i++;
	i--;
	lst = ft_lstnew(ft_atoi_v2(arg[i]));
	if (!lst)
		return (ft_clear(arg), NULL);
	i--;
	while (i >= 0)
	{
		ft_lstadd_front(&lst, ft_lstnew(ft_atoi_v2(arg[i])));
		i--;
	}
	ft_clear(arg);
	return (lst);
}
