/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:03:16 by dacrespo          #+#    #+#             */
/*   Updated: 2024/09/04 12:23:44 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*get_next_line es la función principal que el usuario llamará repetidamente para
 obtener cada línea del archivo asociado al descriptor de archivo fd*/

/*Usa una variable estática backup para almacenar cualquier contenido sobrante
 de la lectura anterior.*/

#include "get_next_line.h"

//Leer línea: Llama a read_line para leer contenido adicional del archivo y actualizar backup
/*Propósito: Lee datos del archivo en trozos de tamaño BUFFER_SIZE hasta encontrar un salto
de línea (\n) o hasta que no haya más datos que leer.*/
char	*read_line(int fd, char *backup)
{
	int bytes_read;
	char *buffer;

	bytes_read = 0;
	buffer = (char*)malloc ((BUFFER_SIZE +1))




//Extraer línea: Llama a extract_line para obtener la primera línea completa de backup
// Propósito: Extrae la primera línea completa del
char	*extract_line(char *backup)



//Preparar para la próxima llamada: Llama a next_line para actualizar backup con cualquier
//contenido que quede después de la línea extraída
/*Propósito: Actualiza el backup para contener solo el contenido después de la línea extraída
, preparando backup para la próxima llamada a get_next_line*/
char	*next_line(char *backup)




char	*get_next_line(int fd)
