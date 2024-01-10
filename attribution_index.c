/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribution_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: transfo <transfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 01:44:42 by transfo           #+#    #+#             */
/*   Updated: 2024/01/10 13:48:17 by tburtin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	while (head != NULL)
	{
		if ((head->index == -1) && (has_min == 0 || head->donne < min->donne))
		{
			min = head;
			has_min = 1;
		}
		head = head->suivant;
	}
	return (min);
}

void	attribution_index(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index;
		head = get_next_min(stack);
		index++;
	}
}
