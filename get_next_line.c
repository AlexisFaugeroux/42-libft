/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:27:33 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/10 18:35:38 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(char *buffer, char *tmp)
{
	char	*res;

	res = ft_strjoin(buffer, tmp);
	return (free(buffer), res);
}

char	*ft_read(char *buffer, int fd)
{
	char	*tmp;
	ssize_t	bytes_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(tmp), NULL);
		tmp[bytes_read] = '\0';
		buffer = ft_join(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	if (*buffer == '\0')
		return (free(buffer), free(tmp), NULL);
	return (free(tmp), buffer);
}

char	*ft_line(char *buffer)
{
	int		i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (*(buffer + i) && *(buffer + i) != '\n')
		i++;
	if (!ft_strchr(buffer, '\n'))
		return (ft_strndup(buffer, i));
	return (ft_strndup(buffer, i + 1));
}

void	*ft_offset(char *dest, void const *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;

	if (!src || !dest)
		return (NULL);
	ft_memmove(dest, src, n);
	*(dest + ft_strlen(dest)) = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_SETSIZE];
	char		*line;
	ssize_t		l_len;
	ssize_t		b_len;

	if (fd < 0 || fd > FD_SETSIZE || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd] || !ft_strchr(buffer[fd], '\n'))
		buffer[fd] = ft_read(buffer[fd], fd);
	line = ft_line(buffer[fd]);
	l_len = ft_strlen(line);
	b_len = ft_strlen(buffer[fd]);
	buffer[fd] = ft_offset(buffer[fd], buffer[fd] + l_len, b_len - l_len + 1);
	if (!buffer[fd])
		return (free(line), NULL);
	return (line);
}
