/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:03:52 by efarhat           #+#    #+#             */
/*   Updated: 2023/04/09 17:28:13 by efarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_moves
{
	int	a;
	int	b;
}		t_moves;

typedef struct s_list
{
	int				data;
	int				pos;
	int				up;
	int				down;
	int				nmv;
	t_moves			mvpos;
	struct s_list	*next;
}		t_list;

//LIBFT
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int		ft_atoi_v2(const char *str);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//CHECKING ARGS
int		read_argv(char *argv[]);
char	**split_argv(char *argv[]);
int		check_dup(char **arg);
int		check_argv(char *argv[]);
t_list	*fill_stack(char *argv[]);
void	ft_error(void);
void	ft_clear(char **str);

//OPERATIONS
void	swap(t_list **stack1, t_list **stack2, char *ins, int flag);
void	push(t_list **src, t_list **dst, char *ins);
void	rotate(t_list **lst, char *ins);
void	rev_rotate(t_list **lst, char *ins);
void	rr_rrr(t_list **stack_a, t_list **stack_b, char *ins, int flag);
void	push_min(t_list **stack_a, t_list **stack_b);

// LIST UTILS
t_list	*ft_lstnew(int data);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

// UTILS
void	get_pos(t_list **stack, int size);
int		max_pos(t_list *stack);
void	sort_arr(int *arr, int size);
void	get_coord(t_list *stack);
void	get_pos(t_list **stack, int size);
t_list	*pos_in_stack(t_list **stack_a, int pos);

//MOVES
void	get_nmv(t_list **stack_a, t_list **stack_b);
int		less_move(t_list **stack);
void	get_nmv(t_list **stack_a, t_list **stack_b);
void	first_move(t_list **stack_a, t_list **stack_b, t_list *pa, t_list *pb);
void	second_move(t_list **stack_a, t_list **stack_b, t_list *pa, t_list *pb);

//SORTING
int		is_sorted(t_list *lst);
void	keep_three(t_list **stack_a, t_list **stack_b, int size);
void	sort_range1(t_list **stack_a, t_list **stack_b, int size);
void	sort_range2(t_list **stack_a, t_list **stack_b, int size);
void	sorting(t_list **stack_a, t_list **stack_b, int size);
void	ft_free_lst(t_list **lst);

#endif