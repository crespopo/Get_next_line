/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 12:59:33 by dacrespo          #+#    #+#             */
/*   Updated: 2024/08/01 13:04:24 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Hemos protegido contra errores ft_strlen y se ha rehecho ft_strchr
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	if (s == NULL)
	return(0);

	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

char *ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}

	if (c == '\0')
	{
		return ((char *)s);
	}

	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_total;
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	len_total = (len_s1 + len_s2);
	join = (char *)malloc((len_total +1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	return (join);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char *) malloc(len + 1);
	if (str == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_joinandfree(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	free(s1);
	return (temp);
}


