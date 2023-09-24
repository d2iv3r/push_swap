/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:39:21 by efarhat           #+#    #+#             */
/*   Updated: 2023/04/04 16:47:41 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	less_move(t_list **stack)
{
	t_list		*i;
	t_list		*j;
	int			pos;

	if (ft_lstsize(*stack) == 1)
		return ((*stack)->pos);
	i = *stack;
	j = (*stack)->next;
	pos = i->pos;
	while (j)
	{
		if (j->nmv < i->nmv)
		{
			pos = j->pos;
			i = j;
		}
		j = j->next;
	}
	return (pos);
}

void	get_nmv(t_list **stack_a, t_list **stack_b)
{
	t_list	*p;

	get_coord(*stack_a);
	p = *stack_a;
	while (p)
	{
		if (p->up <= p->down)
			p->nmv = p->up;
		if (p->down < p->up)
			p->nmv = p->down + 1;
		p = p->next;
	}
	get_coord(*stack_b);
	p = *stack_b;
	while (p)
	{
		if (p->up <= p->down)
			p->nmv = p->up;
		if (p->down < p->up)
			p->nmv = p->down + 1;
		p->nmv += pos_in_stack(stack_a, p->pos)->nmv;
		p = p->next;
	}
}

void	first_move(t_list **stack_a, t_list **stack_b, t_list *pa, t_list *pb)
{
	int		i;

	i = 0;
	if (pa->up <= pa->down && pb->up <= pb->down)
	{
		while (i < pa->up && i < pb->up)
		{
			rr_rrr(stack_a, stack_b, "rr\n", 1);
			i++;
		}
	}
	else if (pa->down < pa->up && pb->down < pb->down)
	{
		while (i < pa->down + 1 && i < pb->down + 1)
		{
			rr_rrr(stack_a, stack_b, "rrr\n", 1);
			i++;
		}
	}
	else
		second_move(stack_a, stack_b, pa, pb);
}

void	second_move(t_list **stack_a, t_list **stack_b, t_list *pa, t_list *pb)
{
	int	i;

	i = 0;
	if (pa->up <= pa->down)
	{
		while (i++ < pa->up)
			rotate(stack_a, "ra\n");
	}
	else if (pa->down < pa->up)
	{
		while (i++ < pa->down + 1)
			rev_rotate(stack_a, "rra\n");
	}
	i = 0;
	if (pb->up <= pb->down)
	{
		while (i++ < pb->up)
			rotate(stack_b, "rb\n");
	}
	else if (pb->down < pb->up)
	{
		while (i++ < pb->down + 1)
			rev_rotate(stack_b, "rrb\n");
	}
	push(stack_b, stack_a, "pa\n");
}

void	push_min(t_list **stack_a, t_list **stack_b)
{
	t_list		*p;
	t_list		*min;
	int			i;

	get_coord(*stack_a);
	min = *stack_a;
	p = min->next;
	while (p)
	{
		if (min->data > p->data)
			min = p;
		p = p->next;
	}
	i = 0;
	if (min->up <= min->down)
	{
		while (i++ < min->up)
			rotate(stack_a, "ra\n");
	}
	else if (min->down < min->up)
	{
		while (i++ < min->down + 1)
			rev_rotate(stack_a, "rra\n");
	}
	push(stack_a, stack_b, "pb\n");
}
