/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:16:28 by siyang            #+#    #+#             */
/*   Updated: 2022/11/27 21:13:33 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

#define ALL_OFF 0
#define MINUS_ON 1
#define PLUS_ON 2
#define BLANK_ON 4
#define ZERO_ON 8
#define HASH_ON 16

typedef enum e_type
{
	NONE, TEXT, CHAR, STR, PTR, SINT, UINT, LHEX, UHEX, PERCENT
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

void	del_info(void *field_info);
void	field_init(t_info *field_info);

int		parser(t_list **record, char *format);
void	parse_text(t_info *field_info, t_list **record, char **format);
void	parse_flags(t_info *field_info, char **format);
void	parse_width(t_info *field_info, char **format);
void	parse_percision(t_info *field_info, char **format);
int		parse_type(t_info *field_info, t_list **record, char **format);

void	printer(va_list pargs, t_list *record, int *result);
void	print_text(t_info *feild_info, int *result);
void	print_char(va_list pargs, t_info *feild_info, int *result);
void	print_str(va_list pargs, t_info *feild_info, int *result);
//void	print_ptr(va_list pargs, t_info *feild_info, int *result);
//void	print_sint(va_list pargs, t_info *feild_info, int *result);
//void	print_uint(va_list pargs, t_info *feild_info, int *result);
//void	print_lhex(va_list pargs, t_info *feild_info, int *result);
//void	print_uhex(va_list pargs, t_info *feild_info, int *result);
//void	print_uint(va_list pargs, t_info *feild_info, int *result);
//void	print_percent(va_list pargs, t_info *feild_info, int *result);

void	ft_putchar_iter(char c, int len, int *result);

#endif
