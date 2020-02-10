/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 13:23:20 by aaboukha          #+#    #+#             */
/*   Updated: 2020/01/30 13:24:20 by aaboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_width_2(t_data *data, char *arg)
{
	data->index2 = data->len;
	data->index1 = ft_strlen(data->string) - 1;
	while (--data->index2 >= 0)
	{
		if (arg[data->index2] != '-')
			data->string[data->index1] = arg[data->index2];
		else
			data->string[0] = '-';
		data->index1--;
	}
	data->index1++;
	if (data->zero && (data->specif == 'd' || data->specif == 'i') && !data->dot)
	{
		if (data->string[0] == '-')
			data->string[data->index1] = '0';
		while (--data->index1 >= 1)
			data->string[data->index1] = '0';
		if (arg[0] == '-')
			data->string[0] = '-';
		else
			data->string[0] = '0';
	}	
	return (data->string);
}

char	*ft_width(char *s, t_data *data, char *arg)
{
	if (data->star == 0 || data->star == 2)
		data->width = ft_atoi(s);
	if (data->specif == 's')
		arg = va_arg(data->arg, char *);
	if (arg == NULL)
		arg = (data->specif == 'u') ? ft_uitoa(va_arg(data->arg, unsigned int)) : ft_itoa(va_arg(data->arg, int));
	data->len = ft_strlen(arg);
	data->max = (data->len < data->width) ? data->width : data->len;
	if (!(data->string = malloc(data->max + 1)))
		return (NULL);
	filling_spaces(data->string, 0, data->max);
	if (data->minus == 1)
	{
		data->index1 = -1;
		while (++data->index1 < data->len)
			data->string[data->index1] = arg[data->index1];
		if (data->width < data->len)
			data->string[data->index1] = 0;
	}
	else
		data->string = ft_width_2(data, arg);
	return (data->string);
}
