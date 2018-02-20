/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minh <minh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:27:22 by minh              #+#    #+#             */
/*   Updated: 2018/01/09 20:35:49 by minh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpham <mpham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:38:11 by mpham             #+#    #+#             */
/*   Updated: 2017/12/18 18:11:04 by mpham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_from_start_to_n(char *str)
{
	int				i;

	i = 0;
	while (str != '\0' && str[i] != '\n')
		i++;
	str = ft_strsub(str, 0, i);
	return (str);
}

static	char	*ft_from_n_to_finish(char *str)
{
	int				i;
	char			*tmp;

	i = 0;
	while (str != '\0' && str[i] != '\n')
		i++;
	tmp = ft_strsub(str, i + 1, ft_strlen(str));
	free(str);
	return (tmp);
}

static	char	*ft_join_and_free(char *str, char *buf)
{
	char			*tmp;

	tmp = ft_strjoin(str, buf);
	free(str);
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static char		*str;

	if (fd < 0 || !line)
		return (-1);
	if (str == NULL)
		str = ft_strnew(BUFF_SIZE);
	while (!ft_strchr(str, '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_join_and_free(str, buf);
	}
	if (ret == -1)
		return (-1);
	*line = (ft_strchr(str, '\n')) ? ft_from_start_to_n(str) : ft_strdup(str);
	if (ft_strchr(str, '\n'))
		str = ft_from_n_to_finish(str);
	else
	{
		if (ret == 0 && *str == '\0')
			return (0);
		ft_strdel(&str);
	}
	return (1);
}
