/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:11:21 by fmontes           #+#    #+#             */
/*   Updated: 2023/11/21 14:52:17 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_line(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*line;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	len = i;
	while (str[i++])
		j++;
	line = malloc(j + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, str + (len + 1), j + 1);
	free(str);
	return (line);
}

char	*act_line(char *str)
{
	int		i;
	char	*ret;

	if (!*str)
		return (NULL);
	i = 0;
	while (str[i] && (str[i] != '\n'))
		i++;
	ret = malloc(i + 2);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, str, i + 2);
	return (ret);
}

char	*read_file(char *str, int fd)
{
	int		len;
	char	*temp;

	len = 1;
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (len > 0 && !ft_strchr(str, '\n'))
	{
		len = read(fd, temp, BUFFER_SIZE);
		if (len < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[len] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_file(str, fd);
	if (!str)
		return (NULL);
	ret = act_line(str);
	str = new_line(str);
	return (ret);
}
