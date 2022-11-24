/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:28:40 by siyang            #+#    #+#             */
/*   Updated: 2022/11/24 21:31:17 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	print_text(va_list *pargs, t_info *feild_info, int *result);
void	print_char(va_list *pargs, t_info *feild_info, int *result);
void	print_str(va_list *pargs, t_info *feild_info, int *result);
void	print_ptr(va_list *pargs, t_info *feild_info, int *result);
void	print_sint(va_list *pargs, t_info *feild_info, int *result);
void	print_uint(va_list *pargs, t_info *feild_info, int *result);
void	print_lhex(va_list *pargs, t_info *feild_info, int *result);
void	print_uhex(va_list *pargs, t_info *feild_info, int *result);
void	print_uint(va_list *pargs, t_info *feild_info, int *result);
void	print_percent(va_list *pargs, t_info *feild_info, int *result);

//int main()
//{
//	int res;
//
//	res = ft_printf("just text %- +5.10djust text");
//	printf("res: %d\n", res);
//}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	pargs;
	t_list	*record;

	record = NULL;
	result = parser(&record, (char *)format);

//	while (record)
//	{
//		t_info *test = (t_info *)record->content;
//		printf("start : %p\n", test->start);
//		printf("end : %p\n", test->end);
//		printf("flags : %d\n", test->flags);
//		printf("width : %d\n", test->width);
//		printf("precision : %d\n", test->precision);
//		printf("type : %d\n\n", test->type);
//		record = record->next;
//	}

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
		feild_info = (t_info)record->content;
		if (feild_info->type == TEXT)
			print_text(&pargs, feild_info, result);
		else if (feild_info->type == CHAR)
			print_char(&pargs, feild_info, result);
		else if (feild_info->type == STR)
			print_str(&pargs, feild_info, result);
		else if (feild_info->type == PTR)
			print_ptr(&pargs, feild_info, result);
		else if (feild_info->type == SINT)
			print_sint(&pargs, feild_info, result);
		else if (feild_info->type == UINT)
			print_uint(&pargs, feild_info, result);
		else if (feild_info->type == LHEX)
			print_lhex(&pargs, feild_info, result);
		else if (feild_info->type == UHEX)
			print_uhex(&pargs, feild_info, result);
		else if (feild_info->type == PERCENT)
			print_percent(&pargs, feild_info, result);
		record = record->next;
	}
}

void	print_text(va_list *pargs, t_info *feild_info, int *result)
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
			*result++;
		}
	}
}

void	print_char(va_list *pargs, t_info *feild_info, int *result)
{
//	(if) + ' ' 0 # || percision(with n)
//		에러 처리
//	(else if) 출력 과정 중 오류가 반환되지 않았을 때
//		width : len보다 클때 좌측에 공백
//		percision(default) : 변화 없음
//		- : width가 len보다 클때 우측으로 공백
//		va_arg로 pargs값 출력
//		pargs 길이만큼 결과값 증가

	char	c;

	c = (char)va_arg(pargs, int);
	if (*result != -1)
	{
		if (feild_info->flags == MINUS_ON || feild->percision == 0)
		{
			if (feild_info->width > 1)
			{
			}
			else
			{
				write(1, &c, 1);
				*result += 1;
			}
		}
		else
			*result = -1;
	}
}

void	print_str(va_list *pargs, t_info *feild_info, int *result)
{

}

void	print_ptr(va_list *pargs, t_info *feild_info, int *result)

void	print_sint(va_list *pargs, t_info *feild_info, int *result)

void	print_uint(va_list *pargs, t_info *feild_info, int *result)

void	print_lhex(va_list *pargs, t_info *feild_info, int *result)

void	print_uhex(va_list *pargs, t_info *feild_info, int *result)

void	print_uint(va_list *pargs, t_info *feild_info, int *result)

void	print_percent(va_list *pargs, t_info *feild_info, int *result)

int	field_init(t_info *field_info)
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
