/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:21:21 by aaboukha          #+#    #+#             */
/*   Updated: 2020/01/30 13:22:11 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_precision2(char *arg, t_data *data)
{
	int	l;

	l = ft_strlen(arg);
	if (data->precision < data->len)
	{
		if (data->minus == 1)
			filling_spaces(arg, data->precision, l);
		else
		{
			str_reverse(arg);
			data->index1 = -1;				
			while (++data->index1 < (data->len - data->precision))
				arg++;
			filling_spaces(arg, l - (data->len - data->precision), l);
			arg = str_reverse(arg);
		}
	}
	return (arg);
}

char	*ft_precision(char *s, t_data *data, char *arg)
{
	if (*s == 0)
		data->precision = 0;
	else if (data->star == 0 || data->star == 1)
			data->precision = ft_atoi(s);
	if (arg == NULL)
	{
		if (data->specif == 'd' || data->specif == 'i' || data->specif == 'u')
			arg = (data->specif == 'u') ? ft_uitoa_precision(va_arg(data->arg, unsigned int), data) : ft_itoa_precision(va_arg(data->arg, int), data);
		else
		{
			data->string = va_arg(data->arg, char *);
			data->len = ft_strlen(data->string);
			data->min = (data->precision < data->len) ? data->precision : data->len;
			if (!(arg = malloc(data->min + 1)))
				return (NULL);
			data->index1 = -1;
			while (++data->index1 < data->min)
				arg[data->index1] = data->string[data->index1];
			arg[data->index1] = 0;
		}
	}
	else
		arg = ft_precision2(arg, data);
	return (arg);
}
