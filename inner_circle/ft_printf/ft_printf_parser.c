/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:07:38 by siyang            #+#    #+#             */
/*   Updated: 2022/12/03 18:46:05 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_text(t_info *field_info, t_list **record, char **format)
{
	t_list	*new;

	field_info->type = TEXT;
	field_info->start = *format;
	while (**format != '%' && **format != 0)
		*format += 1;
	field_info->end = *format;
	new = ft_lstnew(field_info);
	if (new == NULL)
	{
		free(field_info);
		return (-1);
	}
	ft_lstadd_back(record, new);
	return (0);
}

void	ft_parse_flags(t_info *field_info, char **format)
{
	while (**format)
	{
		if (**format == '-')
			field_info->flags = field_info->flags | MINUS_ON;
		else if (**format == '+')
			field_info->flags = field_info->flags | PLUS_ON;
		else if (**format == ' ')
			field_info->flags = field_info->flags | BLANK_ON;
		else if (**format == '0')
			field_info->flags = field_info->flags | ZERO_ON;
		else if (**format == '#')
			field_info->flags = field_info->flags | HASH_ON;
		else
			break ;
		*format += 1;
	}
}

int	ft_parse_width(t_info *field_info, char **format, int error)
{
	char	*ptr;
	int		num;

	if (error == -1)
		return (-1);
	if (**format >= '1' && **format <= '9')
	{
		num = 0;
		ptr = *format;
		while (**format >= '0' && **format <= '9')
		{
			*format += 1;
			num++;
		}
		ptr = ft_substr(ptr, 0, num);
		if (ptr == NULL)
		{
			free(field_info);
			return (-1);
		}
		num = ft_atoi(ptr);
		free(ptr);
		field_info->width = num;
	}
	return (0);
}

int	ft_parse_percision(t_info *field_info, char **format, int error)
{
	char	*ptr;
	int		num;

	if (error == -1)
		return (-1);
	if (**format == '.')
	{
		*format += 1;
		if (**format >= '0' && **format <= '9')
		{
			num = 0;
			ptr = *format;
			while (**format >= '0' && **format <= '9')
			{
				*format += 1;
				num++;
			}
			ptr = ft_substr(ptr, 0, num);
			if (ptr == NULL)
			{
				free(field_info);
				return (-1);
			}
			num = ft_atoi(ptr);
			free(ptr);
			field_info->precision = num;
		}
		else
			field_info->precision = 0;
	}
	return (0);
}

int	ft_parse_type(t_info *field_info, t_list **record, char **format, int error)
{
	t_list	*new;

	if (error == -1)
		return (-1);
	if (**format == 'c')
		field_info->type = CHAR;
	else if (**format == 's')
		field_info->type = STR;
	else if (**format == 'p')
		field_info->type = PTR;
	else if (**format == 'd' || **format == 'i')
		field_info->type = SINT;
	else if (**format == 'u')
		field_info->type = UINT;
	else if (**format == 'x')
		field_info->type = LHEX;
	else if (**format == 'X')
		field_info->type = UHEX;
	else if (**format == '%')
		field_info->type = PERCENT;
	else
		return (-1);
	new = ft_lstnew(field_info);
	if (new == NULL)
	{
		free(field_info);
		return (-1);
	}
	ft_lstadd_back(record, new);
	*format += 1;
	return (0);
}
