/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:07:52 by fsalomon          #+#    #+#             */
/*   Updated: 2024/03/29 11:20:59 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	handle_malloc_erroc(void *to_free1, void *to_free2, void *to_free3)
{
	if (to_free1)
		free(to_free1);
	if (to_free2)
		free(to_free2);
	if (to_free3)
		free(to_free3);
	exit(0);
}
