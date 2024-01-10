/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburtin <tburtin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:11:45 by transfo           #+#    #+#             */
/*   Updated: 2024/01/10 14:19:35 by tburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	get_min(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->suivant)
	{
		head = head->suivant;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

void	sort_3(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min(stack_a, -1);
	next_min = get_min(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	if (head->index == min && head->suivant->index != next_min)
	{
		r(stack_a, 'a');
		s(stack_a, 'a');
		rr(stack_a, 'a');
	}
	else if (head->index == next_min)
	{
		if (head->suivant->index == min)
			s(stack_a, 'a');
		else
			rr(stack_a, 'a');
	}
	else
		part2_sort_3(stack_a, head, min);
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		r(stack_a, 'a');
	else if (distance == 2)
	{
		r(stack_a, 'a');
		r(stack_a, 'a');
	}
	else if (distance == 3)
		rr(stack_a, 'a');
	if (is_sorted(stack_a))
		return ;
	p(stack_a, stack_b, 'b');
	sort_3(stack_a);
	p(stack_b, stack_a, 'a');
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		r(stack_a, 'a');
	else if (distance == 2)
	{
		r(stack_a, 'a');
		r(stack_a, 'a');
	}
	else if (distance == 3)
	{
		rr(stack_a, 'a');
		rr(stack_a, 'a');
	}
	else if (distance == 4)
		rr(stack_a, 'a');
	if (is_sorted(stack_a))
		return ;
	p(stack_a, stack_b, 'b');
	sort_4(stack_a, stack_b);
	p(stack_b, stack_a, 'a');
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 0 || size == 1)
		return ;
	if (size == 2)
		s(stack_a, 'a');
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}
