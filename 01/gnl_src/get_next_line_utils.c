/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimi-be <shimi-be@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:34:40 by shimi-be          #+#    #+#             */
/*   Updated: 2024/11/26 15:53:24 by shimi-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *str, int flag)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (flag)
			{
				if (str[i + 1] == '\0')
					return (NULL);
				return (ft_strjoin_gnl(NULL, &str[i + 1]));
			}
			else
			{
				if (str[i + 1] == '\0')
					return (NULL);
				return (&str[i + 1]);
			}
		}
		i++;
	}
	return (NULL);
}

char	*trim_line(char *str)
{
	char	*arr;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	arr = (char *)malloc(sizeof(char) * (len +1));
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = str[i];
		i++;
	}
	arr[len] = '\0';
	return (arr);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*arr;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	arr = (char *)malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2)) + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		arr[i + j] = s2[j];
		j++;
	}
	arr[i + j] = '\0';
	return (arr);
}

char	*get_line(char *stash, int fd, int br)
{
	char	*buff;
	char	*arr;
	char	*temp;

	arr = NULL;
	temp = NULL;
	stash = NULL;
	buff = mall_buff();
	while (br > 0 && !temp)
	{
		br = read(fd, buff, BUFFER_SIZE);
		if (br > 0)
		{
			buff[br] = '\0';
			arr = ft_strjoin_gnl(stash, buff);
			if (!arr)
				return (NULL);
			free(stash);
			stash = arr;
		}
		else if (br < 0)
			return (free(buff), NULL);
		temp = find_nl(buff);
	}
	return (free(buff), arr);
}
