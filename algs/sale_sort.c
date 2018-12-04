/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sale_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 01:35:05 by tduval            #+#    #+#             */
/*   Updated: 2018/12/04 03:20:17 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int  stacks_sorted(int *stacks)
{
    int i;
    int f;

    i = 1;
    f = -1;
    while (i < stacks[0])
    {
        if (stacks[i] > stacks[i + 1])
        {
            if (f == -1)
                f = 1;
            else if (f == 2)
                return (0);
        }
        else
        {
            if (f == -1)
                f = 2;
            else if (f == 1)
                return (0);
        }       
        i++;
    }
    return (f);
}

void	sale_sort(int **stacks)
{
	int			tmp;
	int			i;
	int			j;

	if (stacks[0][1] > stacks[0][2] && stacks[0][0] > 1)
		sa(stacks, 1);
	while (stacks[0][0] && stacks_sorted(stacks[0]) != 2)
	{
		i = 1;
		tmp = 1;
		if (stacks[0][1] > stacks[0][2] && stacks[0][0] > 1)
			sa(stacks, 1);
		while (i < stacks[0][0] + 1)
		{
			if (stacks[0][i] < stacks[0][tmp])
				tmp = i;
			i++;
		}
		if (tmp > stacks[0][0] / 2)
		{
			tmp = stacks[0][0] - tmp;
			while (tmp > -1)
			{
				rra(stacks, 1);
				tmp--;
			}
		}
		else
		{
			while (tmp > 1)
			{
				ra(stacks, 1);
				tmp--;
			}
		}
		pb(stacks, 1);
	}
	i = 0;
	tmp = stacks[1][0];
	while (i < tmp)
	{
		pa(stacks, 1);
		i++;
	}
}
