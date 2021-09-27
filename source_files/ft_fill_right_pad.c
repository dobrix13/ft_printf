/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_right_pad.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 18:55:53 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/23 00:05:53 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_fill_right_pad(char **src, char padding, int width)
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
	ft_strlcpy(temp, *src, str_len + 1);
	pad_len = width - str_len;
	ft_memset(&temp[str_len], padding, pad_len);
	temp[width] = '\0';
	free(*src);
	*src = temp;
}
