/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esoylu <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:59:59 by esoylu            #+#    #+#             */
/*   Updated: 2022/02/09 14:29:58 by esoylu           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line(char *holder)
{
	int		i;
	char	*line;

	i = 0;
	if (!holder[i])
		return (NULL);
	while (holder[i] && holder[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (holder[i] && holder[i] != '\n')
	{
		line[i] = holder[i];
		i++;
	}
	if (holder[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*hold(char *holder)
{
	char	*new_holder;
	int		i;
	int		j;

	i = 0;
	while (holder[i] && holder[i] != '\n')
		i++;
	if (!holder[i])
	{
		free(holder);
		return (NULL);
	}
	new_holder = (char *)malloc((ft_strlen(holder) - i) * sizeof(char));
	if (!new_holder)
		return (NULL);
	j = 0;
	while (holder[++i])
		new_holder[j++] = holder[i];
	new_holder[j] = 0;
	free(holder);
	return (new_holder);
}

char	*read_and_hold(int fd, char *holder)
{
	int		byte_read;
	char	*buf;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	byte_read = 1;
	while (!ft_strchr(holder, '\n') && byte_read)
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[byte_read] = 0;
		holder = ft_strjoin(holder, buf);
	}
	free(buf);
	return (holder);
}

char	*get_next_line(int fd)
{
	static char	*holder = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	holder = read_and_hold(fd, holder);
	if (!holder)
		return (NULL);
	line = get_line(holder);
	holder = hold(holder);
	return (line);
}
