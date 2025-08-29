/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:37:21 by fsalomon          #+#    #+#             */
/*   Updated: 2024/03/01 11:18:10 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_and_null_or_alloc(char *str, char *str2, int flags)
{
	if (flags == 1)
	{
		free(str);
		return (NULL);
	}
	else if (flags == 2)
	{
		free(str);
		free(str2);
		return (NULL);
	}
	else
	{
		str = malloc(2);
		if (!str)
			return (NULL);
		str[0] = 0;
		return (str);
	}
}

int	ft_how_many_bytes_for_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 2);
		i++;
	}
	return (i + 1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i] != 0)
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	i = 0;
	while (src[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *stack, char *buffer)
{
	size_t	stack_len;
	size_t	buffer_len;
	size_t	index;
	char	*new_stack_string;

	if (!stack || !buffer)
		return (NULL);
	stack_len = ft_there_is_lf_or_strlen(stack, 0);
	buffer_len = ft_there_is_lf_or_strlen(buffer, 0);
	index = 0;
	new_stack_string = malloc(sizeof(char) * ((stack_len + buffer_len) + 1));
	if (!new_stack_string)
		return (NULL);
	ft_strlcpy(new_stack_string, stack, stack_len + 1);
	while (*new_stack_string != 0)
	{
		new_stack_string++;
		index++;
	}
	ft_strlcpy(new_stack_string, buffer, buffer_len + 1);
	new_stack_string -= index;
	free(stack);
	return (new_stack_string);
}

int	ft_there_is_lf_or_strlen(char *s, int flags)
{
	int	i;

	i = 0;
	if (flags)
	{
		while (s[i])
		{
			if (s[i] == '\n')
				return (1);
			i++;
		}
		return (0);
	}
	else
	{
		while (s[i])
			i++;
		return (i);
	}
}
