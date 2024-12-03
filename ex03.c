/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex03.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:59:29 by shimi-be          #+#    #+#             */
/*   Updated: 2024/12/01 18:15:50 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./gnl_src/get_next_line.h"
#include "./printf_src/libprintft.h"
#include "./libft_src/libft.h"
#include <fcntl.h>

int ft_mult(char *line)
{
	char *start;
	int i;
	int temp;
	int temp2;
	int result;
	int corr;

	if (!line)
		return (0);
	result = 0;
	temp = 0;
	temp2 = 0;
	start = ft_strnstr(line, "mul(", ft_strlen(line));
	while (start) // Problem around here, I changed libft strnstr to return the position of the number;
	{
		i = 0;
		temp = 0;
		temp2 = 0;
		corr = 1;
		while (ft_isdigit(start[i]))
		{
			temp = temp * 10 + (start[i] - '0');
			i++;
		}
		if (start[i] == ',')
			i++;
		else
			corr = 0;
		while (ft_isdigit(start[i]))
		{
			temp2 = temp2 * 10 + (start[i] - '0');
			i++;
		}
		if (start[i] != ')')
			corr = 0;
		if (corr)
			result = result + (temp*temp2);
		start = ft_strnstr(start, "mul(", ft_strlen(start));
		i = 4;
	}
	return (result);
}

int main(int ac, char *av[])
{
	char	*line;
	int	fd;
	int result;

	if (ac != 2)
		return (-1);
	result = 0;	
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		result = result + ft_mult(line);
		free(line);
		line = get_next_line(fd);
	}
	ft_printf("Result: %i", result);
}
