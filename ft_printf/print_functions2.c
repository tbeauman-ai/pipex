/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:07:01 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/13 13:49:32 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(va_list *ap)
{
	int	u;

	u = va_arg(*ap, unsigned int);
	return (custom_putnbr_base((unsigned int)u, 10));
}

int	print_x(va_list *ap)
{
	int	x;

	x = va_arg(*ap, unsigned int);
	return (custom_putnbr_base((unsigned int)x, 16));
}

int	puthexa_big(unsigned int bx)
{
	char	*base;
	int		ret;

	ret = 1;
	base = "0123456789ABCDEF";
	if (bx / 16 != 0)
		ret = 1 + puthexa_big(bx / 16);
	ft_putchar(base[bx % 16], 1);
	return (ret);
}

int	print_bx(va_list *ap)
{
	int	bx;

	bx = va_arg(*ap, unsigned int);
	return (puthexa_big(bx));
}

int	print_prc(va_list *ap)
{
	(void)ap;
	ft_putchar('%', 1);
	return (1);
}
