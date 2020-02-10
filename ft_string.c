/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:34:53 by aaboukha          #+#    #+#             */
/*   Updated: 2020/01/30 13:25:37 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_string(char *s, t_data *data)
{
	char	*arg;

	data->len = 0;
	arg = NULL;
	data->dot = ft_strchr(s, '.');
	if (*s == 0 || (*s == '-' && *(s + 1) == 0))
		arg = va_arg(data->arg, char *);
	data->minus = (*s == '-') ? 1 : 0;
	if (*s == '-')
		s++;
	data->star = ft_stars(s, data);
	if ((*s > '0' && *s <= '9') || *s == '*')
		arg = ft_width(s, data, arg);
	if (data->dot)
		arg = ft_precision(data->dot + 1, data, arg);
	data->ret = ft_print(arg);
	return (data->ret);
}		
