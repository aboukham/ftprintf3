/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:16:04 by aaboukha          #+#    #+#             */
/*   Updated: 2020/01/31 17:35:33 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_integer(char *s, t_data *data)
{
	char	*arg;

	data->len = 0;
	arg = NULL;
	data->dot = ft_strchr(s, '.');
	//printf("%d\n", data->len);
	if (*s == 0 || (*s == '-' && *(s + 1) == 0) || (*s == '0' && *(s + 1) == 0))
		arg = (data->specif == 'u') ? ft_uitoa(va_arg(data->arg, unsigned int)) : ft_itoa(va_arg(data->arg, int));
	//printf("%d\n", data->len);
	data->minus = (*s == '-') ? 1 : 0;
	data->zero = (*s == '0') ? 1: 0;
	if (*s == '-' || *s == '0')
		s++;
	data->star = ft_stars(s, data);
	if (data->dot)
		arg = ft_precision(data->dot + 1, data, arg);
	if ((*s > '0' && *s <= '9') || *s == '*')
		arg = ft_width(s, data, arg);
	data->ret = ft_print(arg);
	return (data->ret);
}
