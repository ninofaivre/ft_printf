/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaivre <nfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:43:21 by nino              #+#    #+#             */
/*   Updated: 2022/02/01 17:17:43 by nfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_intlen(long long int n, char *base)
{
	int	size;

	size = 0;
	if (n == 0)
		size++;
	while (n >= ft_strlen(base))
	{
		n = n / ft_strlen(base);
		size++;
	}
	if (n % ft_strlen(base))
		size++;
	return (size);
}

int	ft_putchar(char c)
{
	write(1, &c, sizeof(c));
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return(ft_putstr("(null)"));
	while (str[i])
		ft_putchar(str[i++]);
	return (i);
}

int	ft_putbase(long long int n, char *base)
{
	unsigned int	moins;

	moins = 0;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		moins++;
	}
	if (n >= ft_strlen(base))
	{
		ft_putbase(n / ft_strlen (base), base);
		ft_putchar(base[n % ft_strlen (base)]);
	}
	else
		ft_putchar(base[n]);
	return (moins + ft_intlen(n, base));
}
