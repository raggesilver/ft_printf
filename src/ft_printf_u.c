/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rquerino <rquerino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 20:26:37 by rquerino          #+#    #+#             */
/*   Updated: 2019/09/07 14:55:00 by rquerino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char	*ft_precision_u(t_flags flags, char *var, int len)
{
	int		i;
	int		j;
	char	*final;

	if (flags.justdot == 1)
		return (ft_strnew(0));
	i = 0;
	j = 0;
	final = ft_strnew(flags.afterdot);
	while (i < (flags.afterdot - len))
	{
		final[i] = '0';
		i++;
	}
	while (var[j])
	{
		final[i] = var[j];
		i++;
		j++;
	}
	return (final);
}

/*
** Function to deal with 'u'.
*/

int		ft_printf_u(va_list args, t_flags flags)
{
	int		len;
    char    *var;

    if (flags.h == 1)
        var = ft_utoa_base((unsigned short)va_arg(args, unsigned int), 10);
    else if (flags.hh == 1)
        var = ft_utoa_base((unsigned char)va_arg(args, unsigned int), 10);
    else if (flags.l == 1)
        var = ft_ulltoa_base(va_arg(args, unsigned long), 10);
    else if (flags.ll == 1)
        var = ft_ulltoa_base(va_arg(args, unsigned long long), 10);
	else
		var = ft_utoa_base(va_arg(args, unsigned int), 10);
	len = ft_strlen(var);
	if (flags.afterdot > len || flags.justdot == 1)
	{
		var = ft_precision_u(flags, var, len);
		len = ft_strlen(var);
	}
	if (flags.width > len)
		ft_width_ox(flags, var, len);
	else
		ft_putstr(var);
	ft_strdel(&var);
	return (len > flags.width ? len : flags.width);
}