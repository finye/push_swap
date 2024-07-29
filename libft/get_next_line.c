/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsolomon <fsolomon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:05:39 by fsolomon          #+#    #+#             */
/*   Updated: 2024/07/29 15:04:38 by fsolomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*free_stash(char **stash)
{
	if (*stash != NULL)
	{
		free (*stash);
		*stash = NULL;
	}
	return (NULL);
}

static char	*check_validity(ssize_t bytes_read, char **stash)
{
	if (bytes_read < 0)
		free_stash(stash);
	if ((bytes_read == 0 && (*stash == NULL || *stash[0] == '\0')))
		free_stash(stash);
	return (*stash);
}

static void	reader(int fd, char **stash, char **temp)
{
	ssize_t		bytes_read;
	char		buff[BUFFER_SIZE + 1];

	bytes_read = read(fd, buff, BUFFER_SIZE);
	check_validity(bytes_read, stash);
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		if (!*stash)
			*stash = ft_strdup(buff);
		else
		{
			*temp = ft_strjoin(*stash, buff);
			free (*stash);
			*stash = *temp;
		}
		if (ft_strchr(*stash, '\n'))
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*temp;

	line = NULL;
	temp = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	reader(fd, &stash, &temp);
	if (stash)
	{
		line = extract_line(stash);
		if (!line)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		temp = ft_strdup(stash + ft_strlen(line));
		free(stash);
		stash = temp;
	}
	return (line);
}
