/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:07:38 by siyang            #+#    #+#             */
/*   Updated: 2022/11/27 22:01:00 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_text(t_info *field_info, t_list **record, char **format)
{
	field_info->type = TEXT;
	field_info->start = *format;
	while (**format != '%' && **format != 0)
		*format += 1;
	field_info->end = *format;
	ft_lstadd_back(record, ft_lstnew(field_info));
}

void	parse_flags(t_info *field_info, char **format)
{
	while (**format)
	{
		if (**format == '-' && (field_info->flags & MINUS_ON) == ALL_OFF)
			field_info->flags = field_info->flags | MINUS_ON;
		else if (**format == '+' && (field_info->flags & PLUS_ON) == ALL_OFF)
			field_info->flags = field_info->flags | PLUS_ON;
		else if (**format == ' ' && (field_info->flags & BLANK_ON) == ALL_OFF)
			field_info->flags = field_info->flags | BLANK_ON;
		else if (**format == '0' && (field_info->flags & ZERO_ON) == ALL_OFF)
			field_info->flags = field_info->flags | ZERO_ON;
		else if (**format == '#' && (field_info->flags & HASH_ON) == ALL_OFF)
			field_info->flags = field_info->flags | HASH_ON;
		else
			break ;
		*format += 1;
	}
}

void	parse_width(t_info *field_info, char **format)
{
	char	*ptr;
	int		num;

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
		num = ft_atoi(ptr);
		field_info->width = num;
	}
}

void	parse_percision(t_info *field_info, char **format)
{
	char	*ptr;
	int		num;

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
			num = ft_atoi(ptr);
			field_info->precision = num;
		}
		else
			field_info->precision = 0;
	}
}

int	parse_type(t_info *field_info, t_list **record, char **format)
{
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
	ft_lstadd_back(record, ft_lstnew(field_info));
	*format += 1;
	return (0);
}
