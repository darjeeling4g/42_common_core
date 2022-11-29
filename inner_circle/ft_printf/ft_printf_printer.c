/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:47:43 by siyang            #+#    #+#             */
/*   Updated: 2022/11/29 19:08:31 by siyang           ###   ########.fr       */
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

int	num_to_hex(size_t num, unsigned char *array)
{
//	array[19]을 0으로 memset
//	array[0], [1]에 각각 0, x 할당
//	(while) num을 16으로 나눈 몫이 0이 될 때까지 (size_t를 최대로 나눠도 16개까지 나옴)
//		array[17] 부터 나머지를 채워넣음(array[18]은 '\0'자리로 비우기 위함)
//		i--
//	멈춘지점의 인덱스를 반환

	int	i;

	ft_bzero(array, 19);
	i = 17;
	while (num > 0)
	{
		if (num % 16 > 9)
			array[i] = num % 16 + 87;
		else
			array[i] = num % 16 + 48;
		num = num / 16;
		i--;
	}
	array[i] = 'x';
	i--;
	array[i] = '0';
	return (i);
}

int	num_to_str(int num, unsigned char *array)
{
//	array 마지막 자리 null
//	(while) 숫자 0이상 일때까지
//		뒤에서부터 array를 채워넣음
//		i++
//	i 반환

	int	i;
	int	sign;

	ft_bzero(array, 21);
	i = 20;
	sign = 1;
	if (num < 0)
		sign = -1;
	while (num / 10 * sign > 0)
	{
		if (sign == 1)
			array[i - 1] = num % 10 + '0';
		else if (sign == -1)
			array[i - 1] = num % 10 * -1 + '0';
		num = num / 10;
		i--;
	}
	if (sign == 1)
		array[i - 1] = num % 10 + '0';
	else if (sign == -1)
		array[i - 1] = num % 10 * -1 + '0';
	return (i);
}

void	ft_putsign(t_info *feild_info, int num, int *result)
{
//	(if) flags에 '+' or ' '이 있을 때
//		(if) 양수일때
//			(if) flags가 +이면
//				+출력
//			(else if) flags가 ' '이면
//				' '출력
//		(else if) 음수일때
//			-출력
//		feild_info->width -= 1
//		result++
	char	flag;

	flag = feild_info->flags;
	if (flag & PLUS_ON || flag & BLANK_ON)
	{
		if (num >= 0)
		{
			if (flag & PLUS_ON)
				write(1, "+", 1);
			else if (flag & BLANK_ON)
				write(1, " ", 1);
		}
		else
			write (1, "-", 1);
		feild_info->width -= 1;
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

void	print_ptr(va_list pargs, t_info *feild_info, int *result)
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

	size_t			addr;
	unsigned char	array[19];
	int				i;
	int				len;

	addr = (size_t)va_arg(pargs, void *);
	i = num_to_hex(addr, array);
	len = ft_strlen((char *)&array[i]);
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

void	print_sint(va_list pargs, t_info *feild_info, int *result)
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

	int				num;
	unsigned char	array[21];
	int				i;
	int				len;
	int				pre_len;

	num = va_arg(pargs, int);
	i = num_to_str(num, array);
	len = ft_strlen((char *)&array[i]);
	pre_len = 0;
	if (feild_info->flags & HASH_ON)
		*result = -1;
	if (feild_info->flags & MINUS_ZERO_ON)
		feild_info->flags -= ZERO_ON;
	if (feild_info->flags & PLUS_BLANK_ON)
		feild_info->flags -= BLANK_ON;
	if (*result != -1)
	{
		if (feild_info->precision > len)
			pre_len = feild_info->precision - len;
		ft_putsign(feild_info, num, result);
		if (!(feild_info->flags & MINUS_ON))
		{
			if ((feild_info->flags & ZERO_ON) && (feild_info->precision != 0))
				ft_putchar_iter('0', feild_info->width - len - pre_len, result);
			else if (!(feild_info->flags & MINUS_ON))
				ft_putchar_iter(' ', feild_info->width - len - pre_len, result);
		}
		ft_putchar_iter('0', pre_len, result);
		write(1, &array[i], len);
		*result += len;
		if (feild_info->flags & MINUS_ON)
			ft_putchar_iter(' ', feild_info->width - len - pre_len, result);
	}
}

//void	print_uint(va_list pargs, t_info *feild_info, int *result)
//
//void	print_lhex(va_list pargs, t_info *feild_info, int *result)
//
//void	print_uhex(va_list pargs, t_info *feild_info, int *result)
//
//void	print_percent(va_list pargs, t_info *feild_info, int *result)
