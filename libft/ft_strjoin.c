/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:15:45 by fsalomon          #+#    #+#             */
/*   Updated: 2024/03/29 11:54:40 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* modification de strjoin pour so long '&&' a la place du '||' pour la securite
 et free s1 et retrait des const pour s1  et s2*/

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new_string;
	int		index;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	index = 0;
	new_string = malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, s1, s1_len + 1);
	while (*new_string != 0)
	{
		new_string++;
		index++;
	}
	ft_strlcpy(new_string, s2, s2_len + 1);
	new_string -= index;
	free(s1);
	return (new_string);
}
/*
#include <unistd.h>

void	ft_print_result(char const *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int	main(void)
{
	char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";
	char	*strjoin;

	if (!(strjoin = ft_strjoin(s1, s2)))
		ft_print_result("NULL");
	else
		ft_print_result(strjoin);
}
 */