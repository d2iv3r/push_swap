/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:56:12 by efarhat           #+#    #+#             */
/*   Updated: 2023/04/09 22:29:59 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack1, t_list **stack2, char *ins, int flag)
{
	t_list	*tmp;

	if (!*stack1 || !(*stack1)->next)
		return ;
	if (flag == 1)
	{
		tmp = *stack1;
		*stack1 = tmp->next;
		tmp->next = (*stack1)->next;
		(*stack1)->next = tmp;
	}
	else if (flag == 2)
		swap(stack2, stack1, ins, 1);
	if (ins)
		ft_putstr_fd(ins, 1);
}

void	push(t_list **src, t_list **dst, char *ins)
{
	t_list	*tmp;

	if (!*src)
		return ;
	if (!*dst)
	{
		*dst = ft_lstnew((*src)->data);
		(*dst)->pos = (*src)->pos;
		tmp = *src;
		*src = (*src)->next;
		free(tmp);
		if (ins)
			ft_putstr_fd(ins, 1);
		return ;
	}
	tmp = *dst;
	*dst = *src;
	*src = (*src)->next;
	(*dst)->next = tmp;
	if (ins)
		ft_putstr_fd(ins, 1);
}

void	rotate(t_list **lst, char *ins)
{
	t_list	*first;
	t_list	*last;

	if (!*lst || !(*lst)->next)
		return ;
	first = *lst;
	*lst = (*lst)->next;
	last = ft_lstlast(*lst);
	last->next = first;
	first->next = NULL;
	if (ins)
		ft_putstr_fd(ins, 1);
}

void	rev_rotate(t_list **lst, char *ins)
{
	int		blast;
	int		i;
	t_list	*tmp;
	t_list	*first;

	if (!*lst || !(*lst)->next)
		return ;
	blast = ft_lstsize(*lst);
	tmp = *lst;
	first = *lst;
	i = 1;
	while (i < blast - 1)
	{
		tmp = tmp->next;
		i++;
	}
	*lst = ft_lstlast(*lst);
	(*lst)->next = first;
	tmp->next = NULL;
	if (ins)
		ft_putstr_fd(ins, 1);
}

void	rr_rrr(t_list **stack_a, t_list **stack_b, char *ins, int flag)
{
	if (!ft_strncmp(ins, "rr\n", 3))
	{
		rotate(stack_a, NULL);
		rotate(stack_b, NULL);
	}
	if (!ft_strncmp(ins, "rrr\n", 4))
	{
		rev_rotate(stack_a, NULL);
		rev_rotate(stack_b, NULL);
	}
	if (flag)
		ft_putstr_fd(ins, 1);
}
