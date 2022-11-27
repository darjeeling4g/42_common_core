#include <stdio.h>

int main()
{
	char ptr;
// conversion specifier + '#'
	printf("\n=====conversion specifier + '#'=====\n");
//	printf("%#c\n", 'c');
//	printf("%#s\n", "string");
//	printf("%#p\n", &ptr);
//	printf("%#d\n", 42);
//	printf("%#i\n", 42);
//	printf("%#u\n", -42);
	printf("x : %#x\n", 42);
	printf("X : %#X\n", 42);
	printf("%% : %#%\n");

// conversion specifier + '0'
	printf("\n=====conversion specifier + '0'=====\n");
//	printf("%0c\n", 'c');
//	printf("%0s\n", "string");
//	printf("%0p\n", &ptr);
	printf("d : %0d\n", 42);
	printf("i : %0i\n", 42);
	printf("u : %0u\n", -42);
	printf("x : %0x\n", 42);
	printf("X : %0X\n", 42);
	printf("%% : %0%\n");

// conversion specifier + '-'
	printf("\n=====conversion specifier + '-'=====\n");
	printf("c : %-c\n", 'c');
	printf("s : %-s\n", "string");
	printf("p : %-p\n", &ptr);
	printf("d : %-d\n", 42);
	printf("i : %-i\n", 42);
	printf("u : %-u\n", -42);
	printf("x : %-x\n", 42);
	printf("X : %-X\n", 42);
	printf("%% : %-%\n");

// conversion specifier + ' '
	printf("\n=====conversion specifier + ' '=====\n");
//	printf("% c\n", 'c');
//	printf("% s\n", "string");
//	printf("% p\n", &ptr);
	printf("d : % d\n", 42);
	printf("i : % i\n", 42);
//	printf("% u\n", -42);
//	printf("% x\n", 42);
//	printf("% X\n", 42);
	printf("%% : % %\n");

// conversion specifier + '+'
	printf("\n=====conversion specifier + '+'=====\n");
//	printf("%+c\n", 'c');
//	printf("%+s\n", "string");
//	printf("%+p\n", &ptr);
	printf("d : %+d\n", 42);
	printf("i : %+i\n", 42);
//	printf("%+u\n", -42);
//	printf("%+x\n", 42);
//	printf("%+X\n", 42);
	printf("%% : %+%\n");

// conversion specifier + .percision
	printf("\n=====conversion specifier + .percision=====\n");
	printf("c : %.c\n", 'c');
	printf("s : %.s\n", "string");
	printf("p : %.p\n", &ptr);
	printf("d : %.d\n", 42);
	printf("i : %.i\n", 42);
	printf("u : %.u\n", -42);
	printf("x : %.x\n", 42);
	printf("X : %.X\n", 42);
	printf("%% : %.%\n");

// conversion specifier + .percision(with number)
	printf("\n=====conversion specifier + .percision(with number=====\n");
//	printf("%.3c\n", 'c');
	printf("s : %.3s\n", "string");
//	printf("%.3p\n", &ptr);
	printf("d : %.3d\n", 42);
	printf("i : %.3i\n", 42);
	printf("u : %.3u\n", -42);
	printf("x : %.3x\n", 42);
	printf("X : %.3X\n", 42);
	printf("%% : %.3%\n");

// conversion specifier + minimum width
	printf("\n=====conversion specifier + minimum width=====\n");
	printf("c : %5c\n", 'c');
	printf("s : %5s\n", "string");
	printf("p : %5p\n", &ptr);
	printf("d : %5d\n", 42);
	printf("i : %5i\n", 42);
	printf("u : %5u\n", -42);
	printf("x : %5x\n", 42);
	printf("X : %5X\n", 42);
	printf("%% : %5%\n");

	printf("s : %5.3s\n", "string");
	printf("s : %5.s\n", "string");
}
