/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:37:27 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/29 13:02:01 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	The strdup() function returns a pointer to a new string which
**	is a duplicate of the string s. Memory for the new string is
**	obtained with malloc(3), and can be freed with free(3).
*/
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str1)
{
	char	*str2;
	size_t	str_size;

	if (!str1)
	{
		return (0);
	}
	str_size = ft_strlen(str1) + 1;
	str2 = (char *)ft_calloc(*str1, str_size);
	ft_strlcpy(str2, str1, str_size);
	return (str2);
}
