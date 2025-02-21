/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leerFileDescriptor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:10:02 by dacrespo          #+#    #+#             */
/*   Updated: 2025/02/21 11:33:21 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int	main(void)
{
	int	fd;

	fd = open("/home/dacrespo/42_cursus/Get_next_line/miFichero", O_RDONLY);
}
