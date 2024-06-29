/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:30:31 by dacrespo          #+#    #+#             */
/*   Updated: 2024/02/23 02:43:25 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Locates the first occurrence of 'c' in the string 's'
//Returns a pointer to the located character, or NULL if the character does
//not appear in the string.

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' || (char)c == '\0')
	{
		if (*s == (char) c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);