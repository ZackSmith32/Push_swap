/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_funx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:44:56 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/19 21:28:37 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 *	> This is a realloc for a double pointer.  Pass in &tab, the function 
 *		will place the address to a new memory allocation in the place where the 
 *		old pointer was.
 *	> ptr is not freed.  I often pass this is as a static string which
 *		doesn't need to be freed, but if you don't do that remember to free
 */

int		ft_push_str(char ***tab, char *ptr)
{
	// ft_printf("in: push_str\n");
	int		i;
	int		j;
	char	**new;

	// if ((*tab)[0] == 0)
	// {
	// 	*tab = (char **)ft_memalloc(sizeof(char *) * 2);
	// 	(*tab)[0] = ft_strdup(ptr);
	// 	return (0);
	// }
	i = 0;
	while ((*tab)[i] != 0)
		i++;
	new = (char **)ft_memalloc(sizeof(char *) * (i + 2));
	j = 0;
	while (j < i)
	{
		new[j] = (*tab)[j];
		j++;
	}
	new[j] = ft_strdup(ptr);
	new[++j] = 0;
	free(*tab);
	*tab = new;
	return(j);
}

/*
 *	> pops index 0, and shifts everything down
 *	> note that I just free after the loop, this is because the null
 *		terminator was already shifted onto the tab in the loop
 */

char	*ft_pop_str(char **tab)
{
	// ft_printf("pop_str: in:\n");
	// ft_puttab(tab);
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (tab[i] != 0)
		i++;
	ret = ft_strdup(tab[0]);
	while (j < i)
	{
		free(tab[j]);
		tab[j] = ft_strdup(tab[j + 1]);
		j++;
	}
	free(tab[j]);
	// ft_puttab(tab);
	// ft_printf("pop_str: out:\n");
	return(ret);
}




























