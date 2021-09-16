/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_strat2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <e.djavid@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 23:43:33 by edjavid           #+#    #+#             */
/*   Updated: 2021/09/07 23:43:33 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_keep_nb_str2(int index, s_stack *a, s_bool affect)
{
	s_element	*temp;
	int			i;
	int			count;
	int			comp;

	i = compute_stack_size(a);
	count = 0;
	temp = a->first;
	while (temp->index != index)
		temp = temp->next_one;
	if (affect == TRUE)
		temp->keep = TRUE;
	comp = temp->number;
	while (i)
	{
		if (temp->next_one == NULL)
			temp = a->first;
		else
			temp = temp->next_one;
		if (comp < temp->number)
		{
			if (affect == TRUE)
				temp->keep = TRUE;
			comp = temp->number;
			count++;
		}
		i--;
	}
	return (count);
}

int	strat2(s_control *list)
{
	int			nb_keep;
	s_element	*temp;

	temp = list->a->first;
	nb_keep = 0;
	while (temp != NULL)
	{
		if (list->a->first->index == (list->a->first->next_one->index + 1))
		{
			swap_x(list->a);
			temp = list->a->first;
		}
		if (find_keep_nb_str2(temp->index, list->a, FALSE) > nb_keep)
		{
			nb_keep = find_keep_nb_str2(temp->index, list->a, FALSE);
			list->s2_markup_head = temp->index;
		}
		temp = temp->next_one;
	}
	return (nb_keep);
}
