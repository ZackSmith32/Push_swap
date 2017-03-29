/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 22:08:22 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/13 22:51:08 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen_base(unsigned long long n, int base)
{
	int		i;

	i = 0;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	if (i == 0)
		i = 1;
	return (i);
}