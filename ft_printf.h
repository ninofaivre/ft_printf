/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:57:26 by nino              #+#    #+#             */
/*   Updated: 2021/09/05 13:12:48 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

unsigned int	ft_strlen(char *str);

int				ft_putchar(char c);
int				ft_putstr(char *str);

int				ft_putbase(long long int n, char *base);
int				ft_putbase_address(unsigned long int n, char *base);

int				ft_printf(const char *str, ...);

#endif
