/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:51:17 by siyang            #+#    #+#             */
/*   Updated: 2022/12/02 16:45:59 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_unum_to_str(unsigned int num, char *array)
{
//	array 마지막 자리 null
//	(while) 숫자 0이상 일때까지
//		뒤에서부터 array를 채워넣음
//		i++
//	i 반환

	int	i;

	ft_bzero(array, 11);
	i = 9;
	while (num / 10 > 0)
	{
		array[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	array[i] = num % 10 + '0';
	return (i);
}

int	ft_num_to_hex(size_t num, char *array, int is_addr, int is_upper)
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
	if (num == 0)
	{
		array[i] = '0';
		i--;
	}
	while (num > 0)
	{
		if (num % 16 > 9)
			array[i] = num % 16 + 87 - is_upper;
		else
			array[i] = num % 16 + 48;
		num = num / 16;
		i--;
	}
	if (is_addr == 1)
	{
		array[i] = 'x';
		i--;
		array[i] = '0';
	}
	else
		return (i + 1);
	return (i);
}

int	ft_num_to_str(int num, char *array)
{
//	array 마지막 자리 null
//	(while) 숫자 0이상 일때까지
//		뒤에서부터 array를 채워넣음
//		i++
//	i 반환

	int	i;
	int	sign;

	ft_bzero(array, 11);
	i = 9;
	sign = 1;
	if (num < 0)
		sign = -1;
	while (num / 10 * sign > 0)
	{
		if (sign == 1)
			array[i] = num % 10 + '0';
		else if (sign == -1)
			array[i] = num % 10 * -1 + '0';
		num = num / 10;
		i--;
	}
	if (sign == 1)
		array[i] = num % 10 + '0';
	else if (sign == -1)
		array[i] = num % 10 * -1 + '0';
	return (i);
}

void	ft_putsign(t_info *field_info, int num, int *result)
{
//	(if) flags에 '+' or ' '이 있을 때
//		(if) 양수일때
//			(if) flags가 +이면
//				+출력
//			(else if) flags가 ' '이면
//				' '출력
//		(else if) 음수일때
//			-출력
//		field_info->width -= 1
//		result++
	char	flag;

	flag = field_info->flags;
	if (num >= 0)
	{
		if (flag & PLUS_ON)
		{
			write(1, "+", 1);
			*result += 1;
		}
		else if (flag & BLANK_ON)
		{
			write(1, " ", 1);
			*result += 1;
		}
	}
	else
	{
		write (1, "-", 1);
		*result += 1;
	}
}
