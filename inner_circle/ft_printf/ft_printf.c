/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:28:40 by siyang            #+#    #+#             */
/*   Updated: 2022/11/22 16:39:30 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

typedef enum e_type
{
	TEXT, CHAR, STR, PTR, SINT, UINT, HEXL, HEXU, PERCENT
} t_type;

typedef struct s_info
{
	t_type	type;
	char	*text;
	int		len_text;
	char	minus;
	char	plus;
	char	blank;
	char	zero;
	char	hash;
	char	width;
	char	precision;
} t_info;

int	ft_printf(const char *format, ...)
{
	va_list	pargs;
	t_list	feild;

	result = parser(&field, format);
	if (result < 0)
		lst_clear(&field, del_info);
		return (result);
	va_start(pargs, format);
	result = printer(pargs, field, format);
	va_end(pargs);
	lst_clear;
	return (result);
}

int parser(t_list *field, char *format)
{
	t_info	field_info;

	while(*format)
		if (*format != '%')
			field_info.type = 
			new = list_new(field_info);
		else if 
}

int printer(va_list pargs,t_list *field, char *format)
{

}

void	del_info(void *field_info)
{

}
