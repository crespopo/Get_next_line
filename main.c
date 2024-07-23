/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:12:20 by dacrespo          #+#    #+#             */
/*   Updated: 2024/07/06 15:12:33 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	main (int	argc, char	**argv)
{
	int		fd;
	char	*result;
	int		i;
	if (argc < 2)
	{
		printf ("\033[34mError, envia argumentos a la función\n\033[0m");
		return (1);
	}
	fd = open (argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf ("\033[34mError al abrir el archivo\033[0m");
		return (1);
	}
	i = 0;
	while ((result = get_next_line(fd)) != NULL)
	{
		printf ("\033[32mLinea %d :\033[0m %s\n", i, result);
		free (result);
		i++;
	}
	close (fd);
	return (0);
}
