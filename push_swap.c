/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:02:55 by efarhat           #+#    #+#             */
/*   Updated: 2023/04/10 01:13:31 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_range1(t_list **stack_a, t_list **stack_b, int size)
{
	if (is_sorted(*stack_a))
		return ;
	if (size == 3)
	{
		if ((*stack_a)->data > (*stack_a)->next->data
			&& (*stack_a)->data > (*stack_a)->next->next->data)
			rotate(stack_a, "ra\n");
		else if ((*stack_a)->next->next->data < (*stack_a)->data
			&& (*stack_a)->next->next->data < (*stack_a)->next->data)
			rev_rotate(stack_a, "rra\n");
		else if ((*stack_a)->data > (*stack_a)->next->data
			|| (*stack_a)->next->data > (*stack_a)->next->next->data)
			swap(stack_a, stack_b, "sa\n", 1);
		else if ((*stack_a)->data > (*stack_a)->next->next->data)
			rev_rotate(stack_a, "rra\n");
		sort_range1(stack_a, stack_b, size);
	}
	if (size > 3)
		sort_range2(stack_a, stack_a, size);
}

void	sort_range2(t_list **stack_a, t_list **stack_b, int size)
{
	int	s;

	s = size;
	while (size > 3)
	{
		push_min(stack_a, stack_b);
		size--;
	}
	sort_range1(stack_a, stack_b, size);
	while (size <= s)
	{
		push(stack_b, stack_a, "pa\n");
		size++;
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	else
	{
		if (!check_argv(argv))
			return (write(2, "Error\n", 6), 1);
		stack_a = fill_stack(argv);
		if (!stack_a)
			return (0);
		if (is_sorted(stack_a))
		{
			ft_free_lst(&stack_a);
			exit(0);
		}
		size = ft_lstsize(stack_a);
		sorting(&stack_a, &stack_b, size);
	}
	return (0);
}
