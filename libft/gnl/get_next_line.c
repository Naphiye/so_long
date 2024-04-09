/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 11:38:38 by fsalomon          #+#    #+#             */
/*   Updated: 2024/03/29 11:20:56 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_change_stack_adress(char *stack, int stack_len, int line_len)
{
	char	*new_stack;
	int		i;

	new_stack = malloc(sizeof(char) * (stack_len + 1));
	if (!new_stack)
	{
		free(stack);
		return (NULL);
	}
	i = 0;
	while (stack[i + line_len] != 0)
	{
		new_stack[i] = stack[i + line_len];
		i++;
	}
	free(stack);
	return (new_stack);
}

char	*ft_read_next_line(char *buffer, char *stack, int fd)
{
	int	reading;
	int	buffer_read;

	reading = 1;
	buffer_read = 0;
	while (reading != 0)
	{
		reading = read(fd, buffer, BUFFER_SIZE);
		if (reading == -1)
			return (ft_free_and_null_or_alloc(stack, stack, 1));
		if (reading == 0)
		{
			if (buffer_read != 0 || stack[0] != 0)
				break ;
			else
				return (ft_free_and_null_or_alloc(stack, stack, 1));
		}
		buffer[reading] = 0;
		stack = ft_strjoin_gnl(stack, buffer);
		if (ft_there_is_lf_or_strlen(buffer, 1) || reading != BUFFER_SIZE)
			break ;
		buffer_read++;
	}
	return (stack);
}

char	*ft_stack_init(char *stack, char *line, int line_len)
{
	int	stack_len;

	ft_strlcpy(line, stack, line_len);
	stack_len = 0;
	while (stack[stack_len] != 0)
	{
		stack_len++;
	}
	line_len = 0;
	while (line[line_len] != 0)
	{
		line_len++;
	}
	stack_len = stack_len - line_len;
	stack = ft_change_stack_adress(stack, stack_len, line_len);
	if (!stack)
	{
		free(line);
		return (NULL);
	}
	stack[stack_len] = 0;
	return (stack);
}

char	*get_next_line_2(char *buffer, char *line, int fd)
{
	int			line_len;
	static char	*stack;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_and_null_or_alloc(stack, stack, 1));
	if (!stack)
		stack = ft_free_and_null_or_alloc(stack, stack, 0);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free_and_null_or_alloc(stack, stack, 1));
	stack = ft_read_next_line(buffer, stack, fd);
	if (!stack)
		return (ft_free_and_null_or_alloc(buffer, buffer, 1));
	line_len = ft_how_many_bytes_for_line(stack);
	if (line_len == 1)
		return (line = ft_free_and_null_or_alloc(buffer, stack, 2));
	line = malloc(sizeof(char) * line_len + 1);
	if (!line)
		return (ft_free_and_null_or_alloc(buffer, stack, 2));
	stack = ft_stack_init(stack, line, line_len);
	if (!stack)
		handle_malloc_erroc(stack, line, buffer);
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;

	line = get_next_line_2(buffer, line, fd);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char path[] = "pouet.txt";
// 	int fd = open(path, O_RDONLY);
// 	char *line;
// 	line = NULL;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	printf("%s", line);
// 	return (0);
// }