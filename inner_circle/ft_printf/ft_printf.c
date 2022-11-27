/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:28:40 by siyang            #+#    #+#             */
/*   Updated: 2022/11/27 20:28:35 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	pargs;
	t_list	*record;

	record = NULL;
	result = parser(&record, (char *)format);

	if (result > -1)
	{
		va_start(pargs, format);
		printer(pargs, record, &result);
		va_end(pargs);
	}
	ft_lstclear(&record, del_info);
	return (result);
}

int	parser(t_list **record, char *format)
{
	int		error;
	t_info	*field_info;

	error = 0;
	while(*format)
	{
		field_info = malloc(sizeof(t_info));
		if (field_info == NULL)
			return (-1);
		field_init(field_info);
		if (*format != '%')
			parse_text(field_info, record, &format);
		else if (*format == '%')
		{
			format = format + 1;
			parse_flags(field_info, &format);
			parse_width(field_info, &format);
			parse_percision(field_info, &format);
			error = parse_type(field_info, record, &format);
		}
		if (error == -1)
			break ;
	}
	return (error);
}

void	printer(va_list pargs, t_list *record, int *result)
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

	t_info	*feild_info;

	while (record)
	{
		feild_info = record->content;
		if (feild_info->type == TEXT)
			print_text(feild_info, result);
		else if (feild_info->type == CHAR)
			print_char(pargs, feild_info, result);
		else if (feild_info->type == STR)
			print_str(pargs, feild_info, result);
//		else if (feild_info->type == PTR)
//			print_ptr(pargs, feild_info, result);
//		else if (feild_info->type == SINT)
//			print_sint(pargs, feild_info, result);
//		else if (feild_info->type == UINT)
//			print_uint(pargs, feild_info, result);
//		else if (feild_info->type == LHEX)
//			print_lhex(pargs, feild_info, result);
//		else if (feild_info->type == UHEX)
//			print_uhex(pargs, feild_info, result);
//		else if (feild_info->type == PERCENT)
//			print_percent(pargs, feild_info, result);
		record = record->next;
	}
}



void	field_init(t_info *field_info)
{
	field_info->start = NULL;
	field_info->end = NULL;
	field_info->flags = ALL_OFF;
	field_info->width = 0;
	field_info->precision = -1;
	field_info->type = NONE;
}

void	del_info(void *field_info)
{
	free(field_info);
	field_info = NULL;
}
