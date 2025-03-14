/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 03:16:29 by dacrespo          #+#    #+#             */
/*   Updated: 2025/03/14 03:31:06 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int main ()
{
	int		fd_1;
	int		fd_2;
	int		fd_3;
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 1;
	fd_1 = open("files/text.txt", O_RDONLY);
	fd_2 = open("files/text2.txt", O_RDONLY);
	fd_3 = open("files/text3.txt", O_RDONLY);
	while (i < 3)
	{
		line = get_next_line(fd_1);
		printf("fd_1 - Linea [%d]:\n%s\n", j, line);
		free(line);
		line = get_next_line(fd_2);
		printf("fd_2 - Linea [%d]:\n%s\n", j, line);
		free(line);
		line = get_next_line(fd_3);
		printf("fd_3 - Linea [%d]:\n%s\n", j, line);
		free(line);
		i++;
		j++;
	}
	close(fd_1);
	close(fd_2);
	close(fd_3);
	return (0);
}
