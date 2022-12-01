/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printer_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:47:43 by siyang            #+#    #+#             */
/*   Updated: 2022/12/01 17:08:54 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf_bonus.h"

void	ft_print_text(t_info *feild_info, int *result)
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

void	ft_print_char(va_list pargs, t_info *feild_info, int *result)
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
	if (c == 0)
	{
		*result = -1;
		return ;
	}
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

void	ft_print_str(va_list pargs, t_info *feild_info, int *result)
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
	if (s == NULL)
	{
		*result = -1;
		return ;
	}
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

void	ft_print_ptr(va_list pargs, t_info *feild_info, int *result)
{
//	(if) flags가 '-'외에 또 존재하면
//		error
//	(if) 출력 중 오류가 반환되지 않았을때,
//		width : len보다 클때 좌측에 공백
//		precision(default) : 정확도 무시
//	(if) flags 가 없을 때
//		좌측 공백출력
//	포인터 변수 값(메모리 주소) 16진수 변환 후 출력
//	(if) minus일때
//		우측 공백출력

	size_t	addr;
	char	array[19];
	int		i;
	int		len;

	addr = (size_t)va_arg(pargs, void *);
	if (addr == 0)
	{
		*result = -1;
		return ;
	}
	i = ft_num_to_hex(addr, array, 1, 0);
	len = ft_strlen(&array[i]);
	if ((feild_info->flags | MINUS_ON) != MINUS_ON)
		*result = -1;
	if (*result != -1)
	{
		if (feild_info->flags == ALL_OFF)
			ft_putchar_iter(' ', feild_info->width - len, result);
		write(1, &array[i], len);
		*result += len;
		if (feild_info->flags == MINUS_ON)
			ft_putchar_iter(' ', feild_info->width - len, result);
	}
}

void	ft_print_sint(va_list pargs, t_info *feild_info, int *result)
{
//	(if) flags가 hash on일 경우
//		error
//	(if) flags가 plus on이면서 blank on일 경우
//		plus on만 적용
//	(if) flags가 minus on이면서 zero on일 경우
//		minus on만 적용
//	(if) 출력 중 오류가 반환되지 않았을 때
//		width : len보다 클때 좌측 공백
//		precision(default) : 0 flags를 무시한다
//		precision(with n) : len보다 작으면 무시, len보다 크면 남는자리 0으로 대체 / width는 precision 적용한 길이를 제외하고 적용됨
//		(if) flags가 없으면 좌측 공백 (zero on일 경우 0으로 대체)
//		precision 적용된 10진수 출력(+, ' ' 옵션 적용시 부호출력)
//		precision이 0이면서 nbr이 0인경우 0을 출력하지 않음
//		(if) minus면 우측공백

	int		num;
	char	array[11];
	int		i;
	int		len;

	num = va_arg(pargs, int);
	if (num == 0)
	{
		*result = -1;
		return ;
	}
	i = ft_num_to_str(num, array);
	len = ft_strlen(&array[i]);
	if (feild_info->flags & HASH_ON)
		*result = -1;
	if ((feild_info->flags & MINUS_ZERO_ON) == MINUS_ZERO_ON)
		feild_info->flags -= ZERO_ON;
	if ((feild_info->flags & PLUS_BLANK_ON) == PLUS_BLANK_ON)
		feild_info->flags -= BLANK_ON;
	if (feild_info->flags & PLUS_BLANK_ON)
		feild_info->width -= 1;
	if ((feild_info->flags & ZERO_ON) && (feild_info->precision >= 0))
		feild_info->flags -= ZERO_ON;
	if (feild_info->precision > len)
		feild_info->width -= feild_info->precision - len;
	if (*result != -1)
	{
		if (!(feild_info->flags & MINUS_ON) && !(feild_info->flags & ZERO_ON))
			ft_putchar_iter(' ', feild_info->width - len, result);
		ft_putsign(feild_info, num, result);
		if (feild_info->flags & ZERO_ON)
			ft_putchar_iter('0', feild_info->width - len, result);
		ft_putchar_iter('0', feild_info->precision - len, result);
		if (!(num == 0 && feild_info->precision == 0))
		{
			write(1, &array[i], len);
			*result += len;
		}
		if (feild_info->flags & MINUS_ON)
			ft_putchar_iter(' ', feild_info->width - len, result);
	}
}

void	ft_print_uint(va_list pargs, t_info *feild_info, int *result)
{
//	(if) flags가 minus, zero외에 또 존재하는 경우
//		error
//	(if) flags가 minus on이면서 zero on일 경우
//		minus on만 적용
//	(if) 출력 중 오류가 반환되지 않았을 때
//		width : len보다 길면 좌측 공백
//		precision(default) : 0 flags를 무시한다
//		precision(with n) : len보다 작으면 무시, len보다 크면 남는자리 0으로 대체 / width는 precision 적용한 길이를 제외하고 적용됨
//		(if) flags가 없으면 좌측 공백 (zero on일 경우 0으로 대체)
//		precision 적용된 10진수 출력
//		precision이 0이면서 nbr이 0인경우 0을 출력하지 않음
//		(if) minus면 우측공백
	unsigned int	num;
	char			array[11];
	int				i;
	int				len;

	num = va_arg(pargs, unsigned int);
	if (num == 0)
	{
		*result = -1;
		return ;
	}
	i = ft_unum_to_str(num, array);
	len = ft_strlen(&array[i]);
	if ((feild_info->flags | MINUS_ZERO_ON) != MINUS_ZERO_ON)
		*result = -1;
	if ((feild_info->flags & MINUS_ZERO_ON) == MINUS_ZERO_ON)
		feild_info->flags -= ZERO_ON;
	if ((feild_info->flags & ZERO_ON) && (feild_info->precision >= 0))
		feild_info->flags -= ZERO_ON;
	if (feild_info->precision > len)
		feild_info->width -= feild_info->precision - len;
	if (*result != -1)
	{
		if (!(feild_info->flags & MINUS_ON) && !(feild_info->flags & ZERO_ON))
			ft_putchar_iter(' ', feild_info->width - len, result);
		if (feild_info->flags & ZERO_ON)
			ft_putchar_iter('0', feild_info->width - len, result);
		ft_putchar_iter('0', feild_info->precision - len, result);
		if (!(num == 0 && feild_info->precision == 0))
		{
			write(1, &array[i], len);
			*result += len;
		}
		if (feild_info->flags & MINUS_ON)
			ft_putchar_iter(' ', feild_info->width - len, result);
	}
}

void	ft_print_lhex(va_list pargs, t_info *feild_info, int *result)
{
//	(if) flags가 plus, blank이면
//		error
//	(if) flags가 minus on이면서 zero on일 경우
//		minus on만 적용
//	(if) 출력 중 오류가 반환되지 않았을 때
//		width : len보다 길면 좌측 공백
//		precision(default) : 0 flags를 무시한다
//		precision(with n) : len보다 작으면 무시, len보다 크면 남는자리 0으로 대체 / width는 precision 적용한 길이를 제외하고 적용됨
//		hash : hex이므로 출력값 앞에 0x를 추가한다
//		(if) flags가 없으면 좌측 공백 (zero on일 경우 0으로 대체)
//		precision 적용된 10진수 출력
//		precision이 0이면서 nbr이 0인경우 0을 출력하지 않음
//		(if) minus면 우측공백
	unsigned int	num;
	char			array[19];
	int				i;
	int				len;

	num = va_arg(pargs, unsigned int);
	if (num == 0)
	{
		*result = -1;
		return ;
	}
	i = ft_num_to_hex(num, array, 0, 0);
	len = ft_strlen(&array[i]);
	if (feild_info->flags & PLUS_BLANK_ON)
		*result = -1;
	if ((feild_info->flags & MINUS_ZERO_ON) == MINUS_ZERO_ON)
		feild_info->flags -= ZERO_ON;
	if ((feild_info->flags & ZERO_ON) && (feild_info->precision >= 0))
		feild_info->flags -= ZERO_ON;
	if (feild_info->precision > len)
		feild_info->width -= feild_info->precision - len;
	if (feild_info->flags & HASH_ON)
		feild_info->width -= 2;
	if (*result != -1)
	{
		if (!(feild_info->flags & MINUS_ON) && !(feild_info->flags & ZERO_ON))
			ft_putchar_iter(' ', feild_info->width - len, result);
		if (feild_info->flags & HASH_ON)
		{
			write(1, "0x", 2);
			*result += 2;
		}
		if (feild_info->flags & ZERO_ON)
			ft_putchar_iter('0', feild_info->width - len, result);
		ft_putchar_iter('0', feild_info->precision - len, result);
		if (!(num == 0 && feild_info->precision == 0))
		{
			write(1, &array[i], len);
			*result += len;
		}
		if (feild_info->flags & MINUS_ON)
			ft_putchar_iter(' ', feild_info->width - len, result);
	}
}

void	ft_print_uhex(va_list pargs, t_info *feild_info, int *result)
{
	unsigned int	num;
	char			array[19];
	int				i;
	int				len;

	num = va_arg(pargs, unsigned int);
	if (num == 0)
	{
		*result = -1;
		return ;
	}
	i = ft_num_to_hex(num, array, 0, 32);
	len = ft_strlen(&array[i]);
	if (feild_info->flags & PLUS_BLANK_ON)
		*result = -1;
	if ((feild_info->flags & MINUS_ZERO_ON) == MINUS_ZERO_ON)
		feild_info->flags -= ZERO_ON;
	if ((feild_info->flags & ZERO_ON) && (feild_info->precision >= 0))
		feild_info->flags -= ZERO_ON;
	if (feild_info->precision > len)
		feild_info->width -= feild_info->precision - len;
	if (feild_info->flags & HASH_ON)
		feild_info->width -= 2;
	if (*result != -1)
	{
		if (!(feild_info->flags & MINUS_ON) && !(feild_info->flags & ZERO_ON))
			ft_putchar_iter(' ', feild_info->width - len, result);
		if (feild_info->flags & HASH_ON)
		{
			write(1, "0X", 2);
			*result += 2;
		}
		if (feild_info->flags & ZERO_ON)
			ft_putchar_iter('0', feild_info->width - len, result);
		ft_putchar_iter('0', feild_info->precision - len, result);
		if (!(num == 0 && feild_info->precision == 0))
		{
			write(1, &array[i], len);
			*result += len;
		}
		if (feild_info->flags & MINUS_ON)
			ft_putchar_iter(' ', feild_info->width - len, result);
	}
}

void	ft_print_percent(va_list pargs, t_info *feild_info, int *result)
{
	if ((feild_info->flags & MINUS_ZERO_ON) == MINUS_ZERO_ON)
		feild_info->flags -= ZERO_ON;
	if (*result != -1)
	{
		if (!(feild_info->flags & MINUS_ON) && !(feild_info->flags & ZERO_ON))
			ft_putchar_iter(' ', feild_info->width - 1, result);
		if (feild_info->flags & ZERO_ON)
			ft_putchar_iter('0', feild_info->width - 1, result);
		write(1, "%", 1);
		*result += 1;
		if (feild_info->flags & MINUS_ON)
			ft_putchar_iter(' ', feild_info->width - 1, result);
	}
}
