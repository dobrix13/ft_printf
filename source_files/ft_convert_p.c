/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:29:28 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/23 01:02:18 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_set_null(t_holder *holder)
{
	char	*number;

	if (holder->precision > -1)
	{
		number = (char *)malloc((holder->precision + 1) * sizeof(char));
		if (!number)
			return (NULL);
		ft_memset(number, '0', (size_t)holder->precision);
		number[holder->precision] = '\0';
	}
	else
		number = ft_strdup("0");
	return (number);
}

void	ft_convert_p(t_format *fmt, t_holder *holder)
{
	void	*ptr;
	char	*number;

	number = NULL;
	ptr = va_arg(fmt->ap, void *);
	if (!ptr)
		number = ft_set_null(holder);
	else
		number = ft_u_itoa_base((unsigned long)ptr, HEXADECIMAL_L_BASE);
	holder->argument = ft_strjoin(PTR_HEX_L_PREFIX, number);
	free(number);
	if (!holder->left_justify)
		ft_fill_left_pad(&holder->argument, ' ', holder->width);
	else
		ft_fill_right_pad(&holder->argument, ' ', holder->width);
	holder->len = ft_strlen(holder->argument);
}
