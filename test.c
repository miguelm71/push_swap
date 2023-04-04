/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 12:47:17 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/04 07:02:09 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "libft/includes/libft.h"

int	main(void)
{
	char	*r;
	int		fd;
	char	*f = "../autoestopista_galactico/gnl/files/read_error.txt";

	/* file = fopen("./testfile.txt", "w");
	if (file == NULL)
	{
		printf("Error!");
		exit(1);
	}
	fprintf(file, "");
	fclose(file); */
	fd = open(f, O_RDONLY);
	r = get_next_line(fd);
	ft_printf("%s", r);
	r = get_next_line(fd);
	ft_printf("%s", r);
	r = get_next_line(fd);
	ft_printf("%s", r);
	r = get_next_line(fd);
	ft_printf("%s", r);
	
	r = get_next_line(fd);
	
	//write (1, r, strlen(r));
	close(fd);
	fd = open(f, O_RDONLY);
	r = get_next_line(fd);
	ft_printf("%s", r);
	r = get_next_line(fd);
	ft_printf("%s", r);
	close(fd);


	/* fd = open(f, O_RDONLY);
	r = get_next_line(fd);
	if (r == NULL)
		return (NULL);
	else
		write(1, "null", 4);
		while (r != NULL)
		{
			r = get_next_line(fd);
			if (r != NULL)
				write (1, r, strlen(r));
			else
				write (1, "null", 4);
		}
	}
	if (close(fd) != 0)
		printf("close() error");
		*/
	/* if (remove("./testfile.txt") == 0) 
	{
		printf("The file is deleted successfully.");
	}
	else
	{
		printf("The file is not deleted.");
	} */
}
