/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omkuzu <omkuzu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:56:50 by omkuzu            #+#    #+#             */
/*   Updated: 2024/11/26 13:16:01 by omkuzu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*full_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	full_str = read_function(fd, full_str);
	if (!full_str)
		return (NULL);
	line = ft_getline(full_str);
	if (!line)
		return (free(full_str), full_str = NULL, NULL);
	full_str = ft_getrest(full_str);
	return (line);
}

char	*read_function(int fd, char *str)
{
	char	*tmp;
	int		bytes;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (free(str), NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && (bytes != 0))
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes == -1)
			return (free(str), free(tmp), NULL);
		tmp[bytes] = '\0';
		str = ft_strjoin(str, tmp);
		if (!str)
			return (free(str), free(tmp), NULL);
	}
	free(tmp);
	return (str);
}

char	*ft_getline(char *full_str)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!full_str[i])
		return (NULL);
	while (full_str[i] && full_str[i] != '\n')
		i++;
	if (full_str[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (full_str[++i] != '\n' && full_str[i])
		line[i] = full_str[i];
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
	size_t	i;
	size_t	j;
	char	*restof;

	i = 0;
	while (full_str[i] && full_str[i] != '\n')
		i++;
	if (!full_str[i])
		return (free(full_str), NULL);
	restof = (char *)malloc(sizeof(char) * (ft_strlen(full_str) - i));
	if (!restof)
		return (free(full_str), NULL);
	i++;
	j = 0;
	while (full_str[i])
		restof[j++] = full_str[i++];
	restof[j] = '\0';
	free(full_str);
	return (restof);
}
