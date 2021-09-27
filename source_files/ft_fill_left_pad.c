/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_left_pad.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:46:24 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/23 00:05:53 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_fill_left_pad(char **src, char padding, int width)
{
	char	*temp;
	size_t	str_len;
	size_t	pad_len;

	str_len = ft_strlen(*src);
	if (!width || width < (int)str_len)
		width = str_len;
	temp = (char *)malloc(width * sizeof(char));
	if (!temp)
		return ;
	pad_len = width - str_len;
	ft_memset(temp, padding, pad_len);
	temp[pad_len] = '\0';
	ft_strlcat(temp, *src, width + 1);
	free(*src);
	*src = temp;
}
