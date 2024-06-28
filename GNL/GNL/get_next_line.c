/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:51:55 by dacrespo          #+#    #+#             */
/*   Updated: 2024/06/28 14:22:49 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

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
	ft_strlcpy(join, s1, len_s1 + 1);
	ft_strlcpy(join + len_s1, s2, len_s2 + 1);
	return (join);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substring = malloc(len + 1);
	if (substring == NULL)
		return (NULL);
	ft_strlcpy(substring, s + start, len + 1);
	return (substring);
}


