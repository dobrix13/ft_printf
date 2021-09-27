/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:31:32 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/23 00:05:53 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_vprintf(const char *format, va_list ap)
{
	t_format	*tmp;
	int			len;

	tmp = ft_initialize_format(format, ap);
	if (!tmp)
		return (0);
	while (tmp->format[tmp->i])
	{
		if (tmp->format[tmp->i] == '%')
			ft_placeholder(tmp);
		else
			tmp->len += write(1, &tmp->format[tmp->i++], 1);
	}	
	len = tmp->len;
	free(tmp);
	return (len);
}
