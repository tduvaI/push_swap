/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 03:18:55 by tduval            #+#    #+#             */
/*   Updated: 2019/01/05 15:28:25 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int			main(int ac, char **av)
{
	int			c;
	t_list		*stack_a;
	t_list		*stack_b;

	stack_b = 0;
	c = 0;
	if (ac < 2 || !(stack_a = cat_params(ac, av, &c)))
	{
		if (ac > 1)
			ft_putstr("Error\n");
		lst_free(&stack_a, &stack_b);
		return (0);
	}
	else
	{
		if (stacks_sorted(stack_a) == 2 || lst_len(stack_a) < 2)
		{
			lst_free(&stack_a, &stack_b);
			return (0);
		}
		if (lst_len(stack_a) < 6 && lst_len(stack_a) > 1)
		{
			short_sort(&stack_a, &stack_b);
			lst_free(&stack_a, &stack_b);
			return (0);
		}
		opti_sort(&stack_a, &stack_b);
		//print_stacks(stack_a, stack_b);
		lst_free(&stack_a, &stack_b);
	}
	return (0);
}
