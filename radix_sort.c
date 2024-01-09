/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: transfo <transfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:11:50 by transfo           #+#    #+#             */
/*   Updated: 2024/01/09 13:55:40 by transfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head != NULL)
	{
		if (head->index > max)
			max = head->index;
		head = head->suivant;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				r(stack_a, 'a');
			else
				p(stack_a, stack_b, 'b');
            j++;
		}
		while (ft_lstsize(*stack_b) != 0)
			p(stack_b, stack_a, 'a');
		i++;
	}
}