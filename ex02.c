/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.c                                             :+:      :+:    :+:   */
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

int *get_arr(char *line)
{
	int i;
	int *res;
	char **arr;

	arr = ft_split(line, ' ');
	i = 0;
	while(arr[i])
		i++;
	res = (int *)malloc((i+1)*sizeof(int));
	if (!res)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		res[i] = ft_atoi(arr[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

int	main(int ac, char *av[])
{
	int fd;
	int is_asc;
	int *arr;
	char *line;
	char **str;
	int result;
	int start;
	int i;

	if (ac != 2)
		return (-1);
	start = 1;
	result = 0;
	fd = open(av[1], O_RDONLY);
	while (start || line)
	{
		i = 0;
		is_asc = 1;
		start = 0;
		line = get_next_line(fd);
		//ft_printf("Line: %s",line);
		if (line)
		{
			arr = get_arr(line);
			while (arr[i] && is_asc)
			{
				if (arr[i] >= arr[i+1] && arr[i+1] != 0)
					is_asc = 0;
				i++;
			}
			if (is_asc)
				result++;
		}
	}
	ft_printf("Result: %i\n",result);
}