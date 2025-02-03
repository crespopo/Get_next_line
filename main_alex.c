/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:12:20 by dacrespo          #+#    #+#             */
/*   Updated: 2025/02/03 15:01:42 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# define BUFFER_SIZE 20
//# define BUFFER_SIZE 1024

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

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*c_str;
	size_t			i;

	c_str = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		c_str[i] = (unsigned char)c;
		i++;
	}
	return (str = c_str);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc((ft_strlen(s) + 1));
	if (!res)
		return (0);
	ft_memset(res, '\0', ft_strlen(s));
	while (i < ft_strlen(s))
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

char	*ft_strjoin(char *s1, char s2)
{
	size_t	len_s1;
	size_t	len_total;
	char	*join;

	if (!s2)
		return (s1);
	if (!s1)
	{
		join = (char *)malloc(2 * sizeof(char));
		join[0] = s2;
		join[1] = '\0';
		return (join);
	}
	printf("aqui en strjoin1\n");
	len_s1 = ft_strlen(s1);
	len_total = len_s1 + 1;
	join = (char *)malloc((len_total +1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	printf("aqui en strjoin s1 --> %s\n", s1);
	while (*s1)
		*join++ = *s1++;
	printf("aqui en strjoin2\njoin1 -->> %s\n", join);
	if (s2)
		*join++ = s2;
	*join = '\0';
	printf("aqui en strjoin3\njoin2 -->> %s\n", join);
	return (join);
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



char	*get_next_line(int fd)
{
	int		tamaño_del_fichero; // Contador de todos los caracteres del texto en bytes
	int		i_de_assign; // Indice de asignación
	char	*texto_leido; //Texto que leemos cada vez ejecutamos read (depende del buffer)
	char	*temporal; //guarda solo los bytes leidos de una vez
	int		idx_buffer; //Indice donde nos quedamos en texto dentro de fichero

	printf("aqui\n");
	texto_leido = (char *)malloc(BUFFER_SIZE + 1);
	if (!texto_leido)
		return (0);
	texto_leido[BUFFER_SIZE] = '\0';
	tamaño_del_fichero = read(fd, texto_leido, BUFFER_SIZE); // Nos da de resultado el total de bytes leidos
	texto_leido[tamaño_del_fichero] = '\0';
	printf("aqui1\n");
	i_de_assign = -1;
	idx_buffer = 0;
	temporal = NULL;
	printf("aqui2\n");
	while (texto_leido[++i_de_assign] != '\0' && texto_leido[i_de_assign] != '\n')
	{
		temporal = ft_strjoin(temporal, texto_leido[i_de_assign]);
		printf("temporal-->> %s\ntexto_leido-->> %s\nchar-->> %c\nidx-->> %d\n", temporal, texto_leido, texto_leido[i_de_assign], i_de_assign);
	}

	printf("aqui3\n");
	temporal = ft_strjoin(temporal, '\0');
	printf("aqui4\n");
	return (temporal);
}

int	main(void)
{
	int		fd; //file descriptor

	fd = open("./miFichero.txt", O_RDONLY);
	if (fd == -1)
	{
		printf ("NO FUNCIONA");
		return (0);
	}
	printf("\nesto es la cadena guardada --->> %s\n", get_next_line(fd));
	close (fd);
	return (0);
}
