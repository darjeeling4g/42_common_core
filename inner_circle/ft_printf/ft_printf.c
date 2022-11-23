/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:28:40 by siyang            #+#    #+#             */
/*   Updated: 2022/11/23 22:21:57 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#include "libft.h"
#include <stdarg.h>

#define ALL_OFF 0
#define MINUS_ON 1
#define PLUS_ON 2
#define BLANK_ON 4
#define ZERO_ON 8
#define HASH_ON 16

typedef enum e_type
{
	NONE, TEXT, CHAR, STR, PTR, SINT, UINT, HEXL, HEXU, PERCENT
} t_type;

typedef struct s_info
{
	char	*start;
	char	*end;
	char	flags;
	int		width;
	int		precision;
	t_type	type;
} t_info;

int		ft_printf(const char *format, ...);
int		parser(t_list *record, char *format);
void	parse_text(t_info *field_info, t_list *record, char **format);
void	parse_flags(t_info *field_info, char **format);
void	parse_width(t_info *field_info, char **format);
void	parse_percision(t_info *field_info, char **format);
int		parse_type(t_info *field_info, t_list *record, char **format);
//int		printer(va_list pargs,t_list *record);
void	del_info(void *field_info);
void	field_init(t_info *field_info);

int main()
{
	int res;

	res = ft_printf("just text");
	printf("res: %d\n", res);
}

int	ft_printf(const char *format, ...)
{
	int		result;
//	va_list	pargs;
	t_list	*record;

	record = NULL;
	result = parser(record, (char *)format);

	while (record)
	{
		t_info *test = (t_info *)record->content;
		printf("start : %p\n", test->start);
		printf("end : %p\n", test->end);
		printf("flags : %c\n", test->flags);
		printf("width : %d\n", test->width);
		printf("precision : %d\n", test->precision);
		printf("type : %d\n", test->type);
		record = record->next;
	}

//	if (result > -1)
//	{
//		va_start(pargs, format);
//		result = printer(pargs, record);
//		va_end(pargs);
//	}
	ft_lstclear(&record, del_info);
	return (result);
}

int	parser(t_list *record, char *format)
{
	int		error;
	t_info	field_info;

	error = 1;
	while(*format)
	{
		field_init(&field_info);
		if (*format != '%')
			parse_text(&field_info, record, &format);
		else if (*format == '%')
		{
			parse_flags(&field_info, &format);
			parse_width(&field_info, &format);
			parse_percision(&field_info, &format);
			error = parse_type(&field_info, record, &format);
		}
		if (error == -1)
			break ;
	}
	return (error);
}

void	parse_text(t_info *field_info, t_list *record, char **format)
{
	field_info->type = TEXT;
	field_info->start = *format;
	while (**format != '%' || **format != '\0')
		format = *format + 1;
	field_info->end = *format;
	ft_lstadd_back(&record, ft_lstnew(field_info));
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
		format = *format + 1;
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
		while (**format >= '1' && **format <= '9')
		{
			format = *format + 1;
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
		format = *format + 1;
		if (**format >= '0' && **format <= '9')
		{
			num = 0;
			ptr = *format;
			while (**format >= '0' && **format <= '9')
			{
				format = *format + 1;
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

int	parse_type(t_info *field_info, t_list *record, char **format)
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
		field_info->type = HEXL;
	else if (**format == 'X')
		field_info->type = HEXU;
	else if (**format == '%')
		field_info->type = PERCENT;
	else
		return (-1);
	ft_lstadd_back(&record, ft_lstnew(field_info));
	return (1);
}

//int	printer(va_list pargs,t_list *record)
//{
//
//}

void	del_info(void *field_info)
{
	t_info	*info;

	info = (t_info *)field_info;
	field_init(info);
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
