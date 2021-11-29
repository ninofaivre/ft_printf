/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaivre <nfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:57:26 by nino              #+#    #+#             */
/*   Updated: 2021/11/29 13:24:19 by nfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int				ft_putchar(char c);
int				ft_putstr(char *str);

int				ft_putbase(long long int n, char *base);

int				ft_printf(const char *str, ...);

#endif
