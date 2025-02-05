/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacrespo <dacrespo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:03:16 by dacrespo          #+#    #+#             */
/*   Updated: 2025/02/05 15:18:02 by dacrespo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*get_next_line es la función principal que el usuario llamará repetidamente
para obtener cada línea del archivo asociado al descriptor de archivo fd*/

/*Usa una variable estática backup para almacenar cualquier contenido sobrante
 de la lectura anterior.*/


/*Leer línea: Se llama a read_line para leer contenido adicional del archivo y
actualizar backup.
Propósito: Lee datos del archivo en trozos de tamaño BUFFER_SIZE hasta
encontrar un salto de línea (\n) o hasta que no haya más datos que leer.
- Esta función lee el archivo (**`fd`**) y guarda la información leída en un
búfer (**`buffer`**).
- El bucle se ejecuta hasta que encuentra un carácter de nueva línea (**`'\n'`**)
en el búfer existente (**`backup`**).
- El búfer se va concatenando a **`backup`** hasta que se encuentra un carácter
de nueva línea o se llega al final del archivo.
- Si se produce un error al leer el archivo, la función libera la memoria
asignada y devuelve **`NULL`**.
- Finalmente, libera la memoria del búfer y devuelve el nuevo **`backup`**. */

/* PSEUDOCODIGO
función read_line(fd, backup):
   inicializar bytes_read a 0
   reservar memoria para buffer con tamaño BUFFER_SIZE + 1
   si la reserva de memoria falla:
       retornar NULL


   mientras no se encuentre un salto de línea ('\n') en backup:
       leer hasta BUFFER_SIZE bytes desde fd en buffer
       si hubo un error al leer (bytes_read == -1):
           liberar buffer y retornar NULL
       colocar el carácter nulo ('\0') al final de buffer
       si no se leyeron más bytes (bytes_read == 0):
           romper el bucle


       concatenar el contenido de backup y buffer
       asignar el resultado a backup

   liberar buffer
   retornar backup*/
   
#include "get_next_line.h"

char	*read_line(int fd, char *backup)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 0;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(backup, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (bytes_read == 0)
			break ;
		backup = ft_joinandfree(backup, buffer);
	}
	free(buffer);
	return (backup);
}







































//Extraer línea: Llama a extract_line para obtener la primera línea completa de backup
/*
- Esta función toma **`backup`** y extrae la línea hasta el primer carácter de nueva línea (**`'\n'`**).
- El resultado es una nueva cadena que contiene la línea extraída.
- Si **`backup`** está vacío, devuelve **`NULL`**.*/

char	*extract_line(char *backup)
{
	char	*line;
	int 	i;
}


//Preparar para la próxima llamada: Llama a next_line para actualizar backup con cualquier
//contenido que quede después de la línea extraída
/*Propósito: Actualiza el backup para contener solo el contenido después de la línea extraída
, preparando backup para la próxima llamada a get_next_line*/
/*
- Esta función crea una nueva cadena (**`new_backup`**) que contiene el contenido de **`backup`** después de la primera línea.
- Libera la memoria de **`backup`** y devuelve la nueva cadena.
- Si **`backup`** está vacío, devuelve **`NULL`**.*/

char	*next_line(char *backup);
{
	char	*nex_backup;
	int		count;
	int		i;
}

/*
- Esta función principal se encarga de obtener la siguiente línea del archivo.
- Si hay un error en los parámetros de entrada o en la lectura del archivo, libera la memoria y devuelve **`NULL`**.
- Utiliza las funciones anteriores para leer la línea, extraerla y actualizar el **`backup`** para la siguiente llamada.
- Devuelve la línea leída o **`NULL`** si se llega al final del archivo.
*/

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
}
