/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:28:40 by siyang            #+#    #+#             */
/*   Updated: 2022/12/02 16:46:37 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	pargs;
	t_list	*record;

	record = NULL;
	result = ft_parser(&record, (char *)format);

	if (result > -1)
	{
		va_start(pargs, format);
		ft_printer(pargs, record, &result);
		va_end(pargs);
	}
	ft_lstclear(&record, ft_del_info);
	return (result);
}

int	ft_parser(t_list **record, char *format)
{
	int		error;
	t_info	*field_info;

	error = 0;
	while(*format)
	{
		field_info = malloc(sizeof(t_info));
		if (field_info == NULL)
			return (-1);
		ft_field_init(field_info);
		if (*format != '%')
			ft_parse_text(field_info, record, &format);
		else if (*format == '%')
		{
			format = format + 1;
			ft_parse_flags(field_info, &format);
			ft_parse_width(field_info, &format);
			ft_parse_percision(field_info, &format);
			error = ft_parse_type(field_info, record, &format);
		}
		if (error == -1)
			break ;
	}
	return (error);
}

void	ft_printer(va_list pargs, t_list *record, int *result)
{
	
//	(while) record list 순환
//		(if) type이 text
//			print_text
//		(else if) type이 char
//			print_char
//		(else if) type이 string
//			print_str
//		(else if) type이 ptr
//			print_ptr
//		(else if) type이 signed int
//			print_sint
//		(else if) type이 unsigned int
//			print_uint
//		(else if) type이 lower hex number
//			print_lhex
//		(else if) type이 upper hex number
//			print_uhew
//		(else if) type이 percent
//			print_percent
//	(return) result

	t_info	*field_info;

	while (record)
	{
		field_info = record->content;
		if (field_info->type == TEXT)
			ft_print_text(field_info, result);
		else if (field_info->type == CHAR)
			ft_print_char(pargs, field_info, result);
		else if (field_info->type == STR)
			ft_print_str(pargs, field_info, result);
		else if (field_info->type == PTR)
			ft_print_ptr(pargs, field_info, result);
		else if (field_info->type == SINT)
			ft_print_sint(pargs, field_info, result);
		else if (field_info->type == UINT)
			ft_print_uint(pargs, field_info, result);
		else if (field_info->type == LHEX)
			ft_print_lhex(pargs, field_info, result);
		else if (field_info->type == UHEX)
			ft_print_uhex(pargs, field_info, result);
		else if (field_info->type == PERCENT)
			ft_print_percent(pargs, field_info, result);
		record = record->next;
	}
}

void	ft_field_init(t_info *field_info)
{
	field_info->start = NULL;
	field_info->end = NULL;
	field_info->flags = ALL_OFF;
	field_info->width = 0;
	field_info->precision = -1;
	field_info->type = NONE;
}

void	ft_del_info(void *field_info)
{
	free(field_info);
	field_info = NULL;
}
