/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ejemplo_Variable_Estatica.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:31:12 by dacrespo          #+#    #+#             */
/*   Updated: 2025/02/03 15:04:39 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	contar_llamadas(void)
{
	static int	contador = 0;

	contador++;
	printf("La función fue llamada %d veces\n", contador);
}

int	main(void)
{
	contar_llamadas();
	contar_llamadas();
	contar_llamadas();
	return (0);
}
