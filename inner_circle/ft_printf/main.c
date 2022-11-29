#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int res;

//	res = ft_printf("this is CHAR : %-5.c\n", '1');
//	printf("ft_result : %d\n", res);
//	res = printf("this is CHAR : %-5.c\n", '1');
//	printf("result : %d\n", res);

//	res = ft_printf("this is STR : %-10.5s\n", "yes i'm string");
//	printf("ft_result : %d\n", res);
//	res = printf("this is STR : %-10.5s\n", "yes i'm string");
//	printf("result : %d\n", res);

//	res = ft_printf("this is PTR : %-16.p\n", "yes i'm ptr");
//	printf("ft_result : %d\n", res);
//	res = printf("this is PTR : %-16.p\n", "yes i'm ptr");
//	printf("result : %d\n", res);
//	printf("test : %d\n", 5);

	res = ft_printf("this is SNUM : %d\n", 3);
	printf("ft_result : %d\n", res);
	res = printf("this is SNUM : %d\n", 3);
	printf("result : %d\n", res);
}
