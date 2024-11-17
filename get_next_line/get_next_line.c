/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omrfrkzu <omrfrkzu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:36:30 by omkuzu            #+#    #+#             */
/*   Updated: 2024/11/17 09:47:04 by omrfrkzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*full_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (free(full_str), full_str = NULL, NULL);
	full_str = read_function(fd, full_str);
	if (!full_str)
		return (NULL);
	line = ft_getline(full_str);
	full_str = ft_getrest(full_str);
	return (line);
}

char	*read_function(int fd, char *str)
{
	char	*tmp;
	int		bytes;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && (bytes != 0))
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
			return (free(tmp), NULL);
		tmp[bytes] = '\0';
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*ft_getline(char *full_str)
{
	int		i;
	char	*line;

	i = 0;
	if (!full_str[i])
		return (NULL);
	while (full_str[i] && full_str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (full_str[i] && full_str[i] != '\n')
	{
		line[i] = full_str[i];
		i++;
	}
	if (full_str[i] == '\n')
	{
		line[i] = full_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_getrest(char *full_str)
{
	int		i;
	int		j;
	char	*restof;

	i = 0;
	while (full_str[i] && full_str[i] != '\n')
		i++;
	if (!full_str[i])
	{
		free(full_str);
		return (NULL);
	}
	restof = (char *)malloc(sizeof(char) * (ft_strlen(full_str) - i));
	if (!restof)
		return (NULL);
	i++;
	j = 0;
	while (full_str[i])
		restof[j++] = full_str[i++];
	restof[j] = '\0';
	free(full_str);
	return (restof);
}
