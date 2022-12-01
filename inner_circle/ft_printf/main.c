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

	res = ft_printf("this is SNUM : %020.d\n", 42);
	printf("ft_result : %d\n", res);
	res = printf("this is SNUM : %020.d\n", 42);
	printf("result : %d\n", res);

	res = ft_printf("this is UNUM : %020.u\n", -1);
	printf("ft_result : %d\n", res);
	res = printf("this is UNUM : %020.u\n", -1);
	printf("result : %d\n", res);

	res = ft_printf("this is LHEX : %.5x\n", 42);
	printf("ft_result : %d\n", res);
	res = printf("this is LHEX : %.5x\n", 42);
	printf("result : %d\n", res);

	res = ft_printf("this is UHEX : %-20.5X\n", 42);
	printf("ft_result : %d\n", res);
	res = printf("this is UHEX : %-20.5X\n", 42);
	printf("result : %d\n", res);

	res = ft_printf("this is PERCENT : %+ -020.6%\n");
	printf("ft_result : %d\n", res);
	res = printf("this is PERCENT : %+ -020.6%\n");
	printf("result : %d\n", res);
}
