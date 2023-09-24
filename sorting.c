/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 10:08:18 by efarhat           #+#    #+#             */
/*   Updated: 2023/04/09 22:27:08 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_lst(t_list **lst)
{
	t_list	*p;

	if (!*lst)
		return ;
	while (*lst)
	{
		p = *lst;
		*lst = (*lst)->next;
		free(p);
	}
}

void	sort_rem(t_list **stack)
{
	t_list	*p;
	int		i;

	if (!*stack)
		return ;
	get_coord(*stack);
	p = *stack;
	while (p->pos != 1)
		p = p->next;
	i = -1;
	if (p->up <= p->down)
	{
		while (++i < p->up)
			rotate(stack, "ra\n");
	}
	else if (p->down < p->up)
	{
		while (++i < p->down + 1)
			rev_rotate(stack, "rra\n");
	}
}

void	sort_back(t_list **stack_a, t_list **stack_b)
{
	t_list	*pa;
	t_list	*pb;

	if (ft_lstsize(*stack_b) == 0)
		return ;
	get_nmv(stack_a, stack_b);
	pa = *stack_a;
	pb = *stack_b;
	pa = pos_in_stack(stack_a, less_move(stack_b));
	while (pb->pos != less_move(stack_b))
		pb = pb->next;
	if (pa->data != (*stack_a)->data && pb->data != (*stack_b)->data)
		first_move(stack_a, stack_b, pa, pb);
	else
		second_move(stack_a, stack_b, pa, pb);
	sort_back(stack_a, stack_b);
}

void	keep_three(t_list **stack_a, t_list **stack_b, int size)
{
	t_list	*p;

	p = *stack_a;
	if (ft_lstsize(*stack_a) == 3)
		return ;
	else if (p->pos > size - 3)
		rotate(stack_a, "ra\n");
	else if (p->pos > size / 2)
		push(stack_a, stack_b, "pb\n");
	else if (p->pos <= size / 2)
	{
		push(stack_a, stack_b, "pb\n");
		rotate(stack_b, "rb\n");
	}
	keep_three(stack_a, stack_b, size);
}

void	sorting(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		swap(stack_a, stack_b, "sa\n", 1);
	else if (size <= 3)
		sort_range1(stack_a, stack_b, size);
	else if (size <= 5)
		sort_range2(stack_a, stack_b, size);
	else
	{
		get_pos(stack_a, size);
		keep_three(stack_a, stack_b, size);
		sort_range1(stack_a, stack_b, 3);
		sort_back(stack_a, stack_b);
		sort_rem(stack_a);
	}
	ft_free_lst(stack_a);
}
