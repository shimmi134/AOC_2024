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


void fill_arr(int *arr1, int *arr2, char *av[]) 
{
	int fd;
	int i;
	char *line;
	int start;
	char **split_line;
	
	fd = open(av[1], O_RDONLY);
	i = 0;
	line = NULL;
	start = 1;
	while(start || line)
	{
		start = 0;
		line = get_next_line(fd);
		if (line)
		{
			split_line = ft_split(line, ' ');
			arr1[i] = ft_atoi(split_line[0]);
			arr2[i] = ft_atoi(split_line[1]);
			i++;
		}
	}
}

int	get_number(char *av[])
{
	int	fd;
	int	i;
	int start;
	char	*line;

	i = 0;
	line = NULL;
	start = 1;
	fd = open(av[1], O_RDONLY);
	while (start || line)
	{
		line = get_next_line(fd);
		i++;
		start = 0;
	}
	close (fd);
	return (i);
}

void	sort_arr(int *arr1, int *arr2)
{
	int i;
	int j;
	//int count1 = 0;
	//int count2 = 0;
	int temp;

	j = 0;
	while (arr1[j] && arr2[j])
	{
		i = 0;
		while (arr1[i] && arr2[i])
		{
			if (arr1[i] > arr1[i+1] && arr1[i+1] != 0)
			{
				temp = arr1[i];
				arr1[i] = arr1[i+1];
				arr1[i+1] = temp;
				//count1++;
			}
			if (arr2[i] > arr2[i+1] && arr2[i+1] != 0)
			{
				temp = arr2[i];
				arr2[i] = arr2[i+1];
				arr2[i+1] = temp;
				//count2++;
			}
			i++;
		}
		j++;
	}
	//ft_printf("Moves1: %i\n", count1);
	//ft_printf("Moves2: %i\n", count2);
}

int part_1(int *arr1, int *arr2)
{
	int i;
	int result;
	int temp;
	
	i = 0;
	result = 0;
	temp = 0;
	while (arr1[i] && arr2[i])
	{
		temp = arr1[i] - arr2[i];
		if (temp < 0)
			temp = -temp;
		result = result + temp;
		i++;
	}
	return (result);
}

int part_2(int *arr1, int *arr2)
{
	int i;
	int j;
	int result;
	int temp;

	i = 0;
	result = 0;
	while (arr1[i])
	{
		temp = 0;
		j = 0;
		while (arr2[j])
		{
			if (arr1[i] == arr2[j])
				temp = temp + arr1[i];
			j++;
		}
		result = result + temp;
		i++;
	}
	return (result);
}

int main(int ac, char *av[])
{
	int i;
	int result;
	int *arr1;
	int *arr2;

	if (ac != 2)
		return (-1);

	i = get_number(av);
	arr1 = (int *)malloc((i+1) * sizeof(int));
	arr2 = (int *)malloc((i+1) * sizeof(int));
	arr1[i] = 0;
	arr2[i] = 0;

	fill_arr(arr1, arr2, av);

	sort_arr(arr1,arr2);

	result = part_1(arr1,arr2);
	ft_printf("Result: %i\n", result);
	result = part_2(arr1,arr2);
	ft_printf("Result: %i\n", result);

}
