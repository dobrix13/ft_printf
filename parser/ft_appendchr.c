/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:18:19 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/22 14:51:58 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_append_chr(char const *s, char const c)
{
	char	*temp;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	temp = (char *)malloc((len + 2) * sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		temp[i] = s[i];
		i++;
	}
	temp[i++] = c;
	temp[i] = '\0';
	return (temp);
}
