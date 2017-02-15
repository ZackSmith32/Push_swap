/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:43:31 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/09 21:08:18 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*make_stack_obj(int *a, int alen)
{
	// ft_printf("make_stack_obj: in\n");
	t_stack		*stacks;

	stacks = (t_stack *)ft_memalloc(sizeof(t_stack));
	stacks->a = a;
	stacks->alen = alen;
	stacks->b = (int *)ft_memalloc(sizeof(int));
	stacks->blen = 0;
	stacks->operations = (char **)ft_memalloc(sizeof(char*));
	stacks->operations[0] = 0;
	return (stacks);
}

int		data_validate(int argc, char **argv, int **a)
{
	int		i;
	int		j;

	i = 0;
	while (i < argc)
	{
		ft_printf("arg = %s\n", argv[i]);
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]))
				j++;
			else 
				return (0);
		}
		i = ft_append_arr(a, ft_atoi(argv[i]), i);
	}
	ft_printf("stack parsed:\n");
	ft_put_arr(*a, i);
	return (1);
}