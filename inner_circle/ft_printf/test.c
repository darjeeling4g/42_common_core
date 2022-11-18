#include <stdio.h>

int main()
{
	printf("%5d\n", 123);
	printf("% 5d\n", 123);
	printf("%+5d\n", 123);
	printf("%-5d\n", 123);
	printf("%05d\n", 123);
// 	printf("%#5d\n", 123);   //undefined with d
	printf("%             5d\n", 123);
//	printf("%             +5d\n", 123);    //blank is ignored when + is present
	printf("%             -5d\n", 123);
	printf("%+-5d\n", 123);
	printf("%-+5d\n", 123);
	printf("%-+5d\n", 123);
}
