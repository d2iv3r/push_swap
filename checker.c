/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:22:08 by efarhat           #+#    #+#             */
/*   Updated: 2023/04/10 01:22:05 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	inst(char *ins, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(ins, "pa\n", 3))
		push(stack_b, stack_a, 0);
	else if (!ft_strncmp(ins, "pb\n", 3))
		push(stack_a, stack_b, 0);
	else if (!ft_strncmp(ins, "sa\n", 3))
		swap(stack_a, stack_b, 0, 1);
	else if (!ft_strncmp(ins, "sb\n", 3))
		swap(stack_b, stack_b, 0, 1);
	else if (!ft_strncmp(ins, "ss\n", 3))
		swap(stack_a, stack_b, 0, 2);
	else if (!ft_strncmp(ins, "ra\n", 3))
		rotate(stack_a, 0);
	else if (!ft_strncmp(ins, "rb\n", 3))
		rotate(stack_b, 0);
	else if (!ft_strncmp(ins, "rra\n", 4))
		rev_rotate(stack_a, 0);
	else if (!ft_strncmp(ins, "rrb\n", 4))
		rev_rotate(stack_b, 0);
	else if (!ft_strncmp(ins, "rr\n", 3))
		rr_rrr(stack_a, stack_b, "rr\n", 0);
	else if (!ft_strncmp(ins, "rrr\n", 4))
		rr_rrr(stack_a, stack_b, "rrr\n", 0);
	else
		ft_error();
}

void	execute(char *ins, t_list **stack_a, t_list **stack_b)
{
	if (!ins)
		return ;
	inst(ins, stack_a, stack_b);
}

void	read_ins(t_list **stack_a, t_list **stack_b)
{
	int				rd;
	static char		*buff;
	static char		*str;

	buff = malloc(sizeof(char) * 2);
	if (!buff)
		return ;
	rd = 1;
	while (rd > 0)
	{
		rd = read(0, buff, 1);
		if (rd <= 0)
			break ;
		buff[rd] = '\0';
		str = ft_strjoin_v2(str, buff);
		if (buff[0] == '\n')
		{
			execute(str, stack_a, stack_b);
			free(str);
			str = 0;
		}
	}
	execute(str, stack_a, stack_a);
	free(buff);
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
		size = ft_lstsize(stack_a);
		read_ins(&stack_a, &stack_b);
		if (is_sorted(stack_a) && size == ft_lstsize(stack_a))
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}	
}
