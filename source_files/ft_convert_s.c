/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 21:36:27 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/28 00:38:19 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_convert_s(t_format *fmt, t_holder *holder)
{
	char	*string;
	size_t	len;
	char	*temp;

	string = ft_strdup(va_arg(fmt->ap, char *));
	if (!string)
		string = ft_strdup("(null)");
	len = (size_t)ft_strlen(string);
	holder->argument = (char *)malloc((len + 1) * sizeof(char));
	if (!holder->argument)
		return ;
	ft_strlcpy(holder->argument, string, len + 1);
	if (holder->precision > -1)
	{
		temp = holder->argument;
		holder->argument = ft_strndup(temp, (size_t)holder->precision);
		free(temp);
	}
	if (!holder->left_justify)
		ft_fill_left_pad(&holder->argument, ' ', holder->width);
	else
		ft_fill_right_pad(&holder->argument, ' ', holder->width);
	holder->len = ft_strlen(holder->argument);
	free(string);
}
