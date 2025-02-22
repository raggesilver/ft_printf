/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ull_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pqueiroz <pqueiroz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 14:41:10 by pqueiroz          #+#    #+#             */
/*   Updated: 2019/09/07 14:41:18 by pqueiroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_ull_len_base(unsigned long long n, int base)
{
	size_t				res;

	res = 1;
	while ((n /= base))
		res++;
	return (res);
}

size_t		ft_ull_len(unsigned long long n)
{
	return (ft_ull_len_base(n, 10));
}
