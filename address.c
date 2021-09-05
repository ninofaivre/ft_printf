/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 11:42:28 by nino              #+#    #+#             */
/*   Updated: 2021/09/05 12:03:45 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_intlen_address(unsigned long int n, char *base)
{
	int	size;

	size = 0;
	if (n == 0)
		size++;
	while (n >= ft_strlen (base))
	{
		n = n / ft_strlen (base);
		size++;
	}
	if (n % ft_strlen (base))
		size++;
	return (size);
}

int	ft_putbase_address(unsigned long int n, char *base)
{
	if (n >= ft_strlen (base))
	{
		ft_putbase (n / ft_strlen (base), base);
		ft_putchar (base[n % ft_strlen (base)]);
	}
	else
		ft_putchar (base[n]);
	return (ft_intlen_address (n, base));
}
