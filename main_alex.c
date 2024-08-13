/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:12:20 by dacrespo          #+#    #+#             */
/*   Updated: 2024/08/12 14:06:43 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

char	*get_next_line(int fd)
{
	int		tamaño_del_fichero; // Contador de todos los caracteres del texto en bytes
	int		i_de_assign; // Indice de asignación
	char	*texto_dentro_del_fichero; //Texto que leemos cada vez ejecutamos read (depende del buffer)
	char	*temporal; //guarda solo los bytes leidos de una vez
	char	*re; //Guarda todos los temporales leidos hasta el final de la linea
	int		idx_buffer; //Indice donde nos quedamos en texto dentro de fichero
	int		BUFFER_SIZE; // Lo podemos definir aqui o arriba con  #define

	texto_dentro_del_fichero = malloc(BUFFER_SIZE + 1);
	temporal = malloc(BUFFER_SIZE);
	if (!texto_dentro_del_fichero || !temporal || !re)
		return (0);
	texto_dentro_del_fichero[BUFFER_SIZE] = '\0';
	tamaño_del_fichero = read(fd, texto_dentro_del_fichero, BUFFER_SIZE); // Nos da de resultado el total de bytes leidos
	re = malloc(tamaño_del_fichero + 1);


	if (!re)
		return (0);

	i_de_assign = 0;
	idx_buffer = 0;
	BUFFER_SIZE = 0;
	if (ft_strchr(texto_dentro_del_fichero, '\n'))
	{
		while (texto_dentro_del_fichero[i_de_assign] != '\0')
		{
			if (texto_dentro_del_fichero[idx_buffer] == '\n')
			{
				temporal[i_de_assign] = texto_dentro_del_fichero[idx_buffer];
				temporal[++i_de_assign] = '\0';
				re = ft_strdup(texto_dentro_del_fichero);

				return (re);
			}
			temporal[i_de_assign++] = texto_dentro_del_fichero[idx_buffer++];
		}
		temporal[i_de_assign] = '\0';
		if (re == NULL)
			re = ft_strdup(temporal);
		else
			re = ft_strjoin(re, temporal);
		return (re);
	}
	re = ft_strdup(texto_dentro_del_fichero);
	printf("tamaño del fichero: %d\n", tamaño_del_fichero);
	return (re);
}



int	main(void)
{
	int		fd; //file descriptor

	fd = open("/home/dacrespo/42_cursus/get_next_line/miFichero.txt", O_RDONLY);
	if (fd == -1)
	{
		printf ("NO FUNCIONA");
		return (0);
	}
	printf("\nesto es la cadena guardada --->> %s\n", get_next_line(fd));
	close (fd);
	return (0);
}
