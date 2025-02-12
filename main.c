/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:30:26 by dacrespo          #+#    #+#             */
/*   Updated: 2025/02/06 16:36:48 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 5


int	main(void)
{
	int		fd;

	fd = open("./miFichero.txt", O_RDONLY);
	if (fd == -1)
	{
		printf ("NO FUNCIONA");
		return (0);
	}
	printf("\nEsto es la cadena guardada --->> %s\n", get_next_line(fd));
	close (fd);
	return (0);
}
