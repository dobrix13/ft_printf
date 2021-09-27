/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avitolin <avitolin@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 11:37:27 by avitolin          #+#    #+#             */
/*   Updated: 2021/09/28 00:40:19 by avitolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	The strdup() function returns a pointer to a new string which
**	is a duplicate of the string s. Memory for the new string is
**	obtained with malloc(3), and can be freed with free(3).
*/
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	i = ft_strlen(s);
	dup = (char *)malloc(sizeof(*dup) * (i + 1));
	if (dup == NULL)
		return (NULL);
	dup[i] = '\0';
	while (i--)
		dup[i] = s[i];
	return (dup);
}
