/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:16:28 by siyang            #+#    #+#             */
/*   Updated: 2022/11/24 15:40:30 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//#include <stdio.h>

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
int		parser(t_list **record, char *format);
void	parse_text(t_info *field_info, t_list **record, char **format);
void	parse_flags(t_info *field_info, char **format);
void	parse_width(t_info *field_info, char **format);
void	parse_percision(t_info *field_info, char **format);
int		parse_type(t_info *field_info, t_list **record, char **format);
void	printer(va_list pargs, t_list *record, int *result);
void	del_info(void *field_info);
void	field_init(t_info *field_info);

#endif
