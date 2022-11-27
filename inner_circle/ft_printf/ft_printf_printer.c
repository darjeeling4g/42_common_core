/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:47:43 by siyang            #+#    #+#             */
/*   Updated: 2022/11/27 21:30:30 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

void	ft_putchar_iter(char c, int len, int *result)
{
//	(while) len까지
//		ft_putchar_fd
//		result + 1

	if (len < 1)
		return ;
	while (len)
	{
		ft_putchar_fd(c, 1);
		len--;
		*result += 1;
	}
}

void	print_text(t_info *feild_info, int *result)
{
//	(if) result != -1 일때 : 출력 중 오류가 발생하지 않았을 때만 실행
	//	(while) start부터 end까지
	//		write
	//		result++

	char	*start;
	char	*end;

	if (*result != -1)
	{
		start = feild_info->start;
		end = feild_info->end;
		while (start != end)
		{
			write(1, start, 1);
			start++;
			*result += 1;
		}
	}
}

void	print_char(va_list pargs, t_info *feild_info, int *result)
{
//	(if) + ' ' 0 # || percision(with n)
//		에러 처리
//	(if) 출력 과정 중 오류가 반환되지 않았을 때
//		width : 1보다 클때 좌측에 공백
//		percision(default) : 변화 없음
//		- : width가 1보다 클때 우측으로 공백
//		va_arg로 pargs값 출력
//		pargs 길이만큼 결과값 증가

	char	c;

	c = (char)va_arg(pargs, int);
	if ((feild_info->flags | MINUS_ON) != MINUS_ON || feild_info->precision > 0)
		*result = -1;
	if (*result != -1)
	{
		if (feild_info->flags == ALL_OFF)
			ft_putchar_iter(' ', feild_info->width - 1, result);
		write(1, &c, 1);
		*result += 1;
		if (feild_info->flags == MINUS_ON)
			ft_putchar_iter(' ', feild_info->width - 1, result);
	}
}

void	print_str(va_list pargs, t_info *feild_info, int *result)
{
//	(if) flags에 '-'외에도 존재하면
//		error
//	(if) 출력 중 오류가 반환되지 않았을 때
//		width : len보다 클때 좌측에 공백
//		precision(default) : 문자열이 출력되지 않음
//		precision(with n) : 출력할 문자열의 최대 길이 제한 / 설정한 길이가 문자열보다 크다면 원래 문자열 출력
//		(if) flags가 없을 때
//			좌측 공백 출력
//		precision 크기만큼 문자열 출력
//		(if) minus가 있을 때
//			우측 공백 출력

	char	*s;
	int		len;

	s = (char *)va_arg(pargs, char *);
	len = ft_strlen(s);
	if ((feild_info->flags | MINUS_ON) != MINUS_ON)
		*result = -1;
	if (*result != -1)
	{
		if (len >= feild_info->precision && feild_info->precision > -1)
			len = feild_info->precision;
		if (feild_info->flags == ALL_OFF)
			ft_putchar_iter(' ', feild_info->width - len, result);
		write(1, s, len);
		*result += len;
		if (feild_info->flags == MINUS_ON)
			ft_putchar_iter(' ', feild_info->width - len, result);
	}
}

//void	print_ptr(va_list pargs, t_info *feild_info, int *result)
//
//void	print_sint(va_list pargs, t_info *feild_info, int *result)
//
//void	print_uint(va_list pargs, t_info *feild_info, int *result)
//
//void	print_lhex(va_list pargs, t_info *feild_info, int *result)
//
//void	print_uhex(va_list pargs, t_info *feild_info, int *result)
//
//void	print_uint(va_list pargs, t_info *feild_info, int *result)
//
//void	print_percent(va_list pargs, t_info *feild_info, int *result)

