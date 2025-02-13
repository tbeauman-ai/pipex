/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <tbeauman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:58:07 by tbeauman          #+#    #+#             */
/*   Updated: 2025/02/13 13:50:06 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_conversion(char conv, va_list *ap)
{
	char	*conversions;
	int		(*print_functions[9])(va_list *ap);
	int		i;

	conversions = "cspdiuxX%";
	print_functions[0] = &print_c;
	print_functions[1] = &print_s;
	print_functions[2] = &print_p;
	print_functions[3] = &print_d;
	print_functions[4] = &print_d;
	print_functions[5] = &print_u;
	print_functions[6] = &print_x;
	print_functions[7] = &print_bx;
	print_functions[8] = &print_prc;
	i = 0;
	while (conversions[i])
	{
		if (conversions[i] == conv)
			return (print_functions[i](ap));
		i++;
	}
	return (-1);
}

int	ft_printf(const char *frm, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, frm);
	ret = 0;
	if (!frm)
		return (-1);
	while (*frm)
	{
		if (*frm == '%' && *(frm + 1))
		{
			frm++;
			ret += print_conversion(*frm, &ap);
		}
		else if (*frm == '%')
			return (ret);
		else
		{
			ret += 1;
			ft_putchar(*frm, 1);
		}
		frm++;
	}
	va_end(ap);
	return (ret);
}
