/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:16:28 by siyang            #+#    #+#             */
/*   Updated: 2022/12/02 16:46:25 by siyang           ###   ########.fr       */
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

#define MINUS_ZERO_ON 9
#define PLUS_BLANK_ON 6

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

void	ft_del_info(void *field_info);
void	ft_field_init(t_info *field_info);

int		ft_parser(t_list **record, char *format);
void	ft_parse_text(t_info *field_info, t_list **record, char **format);
void	ft_parse_flags(t_info *field_info, char **format);
void	ft_parse_width(t_info *field_info, char **format);
void	ft_parse_percision(t_info *field_info, char **format);
int		ft_parse_type(t_info *field_info, t_list **record, char **format);

void	ft_printer(va_list pargs, t_list *record, int *result);
void	ft_print_text(t_info *field_info, int *result);
void	ft_print_char(va_list pargs, t_info *field_info, int *result);
void	ft_print_str(va_list pargs, t_info *field_info, int *result);
void	ft_print_ptr(va_list pargs, t_info *field_info, int *result);
void	ft_print_sint(va_list pargs, t_info *field_info, int *result);
void	ft_print_uint(va_list pargs, t_info *field_info, int *result);
void	ft_print_lhex(va_list pargs, t_info *field_info, int *result);
void	ft_print_uhex(va_list pargs, t_info *field_info, int *result);
void	ft_print_percent(va_list pargs, t_info *field_info, int *result);

void	ft_putchar_iter(char c, int len, int *result);
void	ft_putsign(t_info *field_info, int num, int *result);
int		ft_num_to_hex(size_t num, char *array, int is_addr, int is_upper);
int		ft_num_to_str(int num, char *array);
int		ft_unum_to_str(unsigned int num, char *array);

#endif
