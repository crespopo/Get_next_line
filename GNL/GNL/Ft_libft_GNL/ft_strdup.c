/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:56:09 by dacrespo          #+#    #+#             */
/*   Updated: 2024/02/15 15:54:01 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// It creates a duplicate of an string by allocating memory for a new string
// and coping the content of the original string into it.

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(s1);
	new_str = (char *) malloc(len +1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy (new_str, s1, len + 1);
	return (new_str);
}
