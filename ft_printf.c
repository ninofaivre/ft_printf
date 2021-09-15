/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:46:33 by nino              #+#    #+#             */
/*   Updated: 2021/09/08 14:57:16 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_parse(char c, va_list arg)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = ft_putchar (va_arg (arg, int));
	else if (c == 's')
		i = ft_putstr (va_arg (arg, char *));
	else if (c == 'p')
	{
		i = ft_putstr ("0x");
		i += ft_putbase_address (va_arg (arg, unsigned long int),
				"0123456789abcdef");
	}
	else if (c == 'd' || c == 'i')
		i = ft_putbase (va_arg (arg, int), "0123456789");
	else if (c == 'u')
		i = ft_putbase (va_arg (arg, unsigned int), "0123456789");
	else if (c == 'x')
		i = ft_putbase (va_arg (arg, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		i = ft_putbase (va_arg (arg, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		i = ft_putchar (c);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		to_return;
	va_list	arg;

	i = 0;
	to_return = 0;
	va_start (arg, str);
	while (str[i])
	{
		if (str[i] == '%')
			to_return += ft_parse (str[++i], arg);
		else
		{
			ft_putchar (str[i]);
			to_return++;
		}
		i++;
	}
	va_end (arg);
	return (to_return);
}
