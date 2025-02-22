/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:30:26 by dacrespo          #+#    #+#             */
/*   Updated: 2025/02/22 18:07:22 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;
	//int		stop;
	fd = open("./miFichero.txt", O_RDONLY);
	if (fd == -1)
	{
		printf ("NO FUNCIONA\n");
		return (1);
	}
	line = get_next_line(fd);
	////while (stop--)
	while (line)
	{
		printf("\nEsto es la cadena guardada --->> %s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (0);
}
