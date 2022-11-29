
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void va_test(int n, ...)
{
	va_list pargs;

	va_start(pargs, n);
	printf("%c, %d, %s",va_arg(pargs, int), va_arg(pargs, int), va_arg(pargs, char *));
	va_end(pargs);
}

int main()
{
	va_test(1, 'c', 4, "string\n");
	
	int res;
	char *ptr;
	char c;

	c = 'c';
	ptr = &c;

	res = printf("%p\n", ptr);
	printf("res  : %d\n", res);
//	res = printf("test : %9223372036854775807d", 10);
//	printf("res : %d\n", res);

	res = printf("test : %+05d\n", 3);
	printf("res : %d\n", res - 8);
	res = printf("test : %0+3d\n", 3);
	printf("res : %d\n", res - 8);
	res = printf("test : %0 3d\n", 3);
	printf("res : %d\n", res - 8);
	res = printf("test : %0+.4d\n", 3);
	printf("res : %d\n", res - 8);
	res = printf("test : %0 .4d\n", 3);
	printf("res : %d\n", res - 8);

	res = printf("test : %+-3.d\n", 0);
	printf("res : %d\n", res - 8);
	res = printf("test : %0 3.d\n", 0);
	printf("res : %d\n", res - 8);
}
