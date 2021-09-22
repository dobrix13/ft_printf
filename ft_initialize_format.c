/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 12:30:48 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/22 13:23:30 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_format	*ft_initialize_format(const char *format, va_list ap)
{
	t_format	*tmp;

	tmp = malloc(sizeof(t_format));
	if (!tmp)
		return (NULL);
	tmp->format = format;
	va_copy(tmp->ap, ap);
	tmp->i = 0;
	tmp->len = 0;
	return (tmp);
}

t_holder	*ft_initialize_holder(void)
{
	t_holder	*temp;

	temp = malloc(sizeof(t_holder));
	if (!temp)
		return (NULL);
	temp->len = 0;
	temp->prefix = ft_strdup("");
	temp->argument = NULL;
	temp->padding = ' ';
	temp->conversion = '\0';
	temp->left_justify = 0;
	temp->width = 0;
	temp->precision = -1;
	return (temp);
}
