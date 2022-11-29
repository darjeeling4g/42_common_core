# ft\_printf
> Because ft\_putnbr() and ft\_putstr() aren't enough
>> The goal of this project is pretty straightforward.  
>> You will recode printf().  
>> You will mainly learn about using a variable number of arguments.
>> How cool is that??  
>> It is actually pretty cool :)

## Before start

### Variadic function in C
> Function with variable number of arguments

#### Understanding the Macro Functions Defined in <stdarg.h>
1. `va_start(va_list pargs, last)`
	- Prototype : `void va_start(va_list pargs, last);`
	- arguments
		- First argument : A variable declared as `va_list` type, which is an argument pointer variable
		- Second argument : The last fixed argument accepted by the variadic function
	- This macro initialises the argument pointer variable **pargs** to point to the first optional argument accepted by the variadic function
1. `va_arg(va_list pargs, type)`
	- Prototype : `type va_arg(va_list pargs, type);`
	- arguments
		- First argument : same as the first argument in `va_start()` macro
		- Second argument : specified the expected data type poined by **pargs**
		> 이때,`char`, `short`등의 자료형은 `int`로 / `float`은 `double`로 적어주어야 한다
		>> 가변인자를 받을 때 스택의 구조를 이용하는데, 이에 효율적으로 각 데이터에 접근하기 위해서 `바이트 패딩(byte padding)`이 적용되어 매개변수가 포인터 크기로 승격된다(각 데이터가 포인터 크기의 스택으로 구성되면 한번의 접근에 하나씩 데이터에 접근할 수 있게 됨)
		>>> 이때 승격되는 데이터 크기는 시스템환경(32bit, 64bit)에 따라 다르므로 특정 데이터 크기로 가변인자를 꺼내오면 다른 값을 얻을 수도 있음. `va_arg`는 이를 방지하기 위한 표준
	- This function returns the value of the argument pointed by **pargs**, and also update the **pargs** to point to the next argument in the list
1. `va_end(va_list pargs)`
	- Prototype : `void va_end(va_list pargs);`
	- This macro ends the use of **pargs**
	- after calling `va_end(pargs)`, futther `va_arg` calls with pargs may not work
		> in GNU C library, `va_end` does nothing

1. `va_copy(va_list dst, va_list src)`
	- Prototype : `void va_copy(va_list pargs);`
	- arguments
	- This macro copy src to dst

#### Declaration of a Variadic Function
- Prototype : `return_type func_name(type arg1, ...)`
	> ... : ellipsis

#### Example
```c
#include <stdio.h>
#include <stdarg.h>
/* Function prototype for averaging n double-typed numbers */
double average(unsigned int n, ...);
int main() {
   double avg1, avg2;
   avg1 = average(2, 50.3, 49.7);
   avg2 = average(5, 12.45, 2.87, 0.256, 90.1532, 6320.12);
   printf("avg1: %f\navg2: %f", avg1, avg2);
}
double average(unsigned int n, ...) {
   /* pointer to the variable arguments list */
   va_list pargs;
   
   /* Initialise pargs to point to the first optional argument */ 
   va_start(pargs, n);
   
   double sum = 0;
   unsigned int i;
   for(i=0;i<n;i++) {  /* iterate though the optional arguments */
    double x = va_arg(pargs, double);
    sum += x;
   }
   va_end(pargs);
   return (n > 0)? (sum / n):0.00;
}
```
```c
avg1: 50.000000
avg2: 1285.169840
```

### Format of printf

#### Syntax
`%[parameter][flags][width][.precision][length]type`

#### Parameter field
> POSIX extention and not in C99
- n$

#### Flags field
- `-` : left-align the output of this placeholder(the default is to right-align the output)
- `+` : Prepends a plus for positive signed-numeric types. (positive = +, negative = -)
	> default : doesn't prepend anything in front of positive numbers
- ` ` : Prepends a plus for positive signed-numeric types. (positive =  , negative = -)
	> this flag is ignored if the + flag exists
	>> default : doesn't prepend anything in front of positive numbers
- `0` : When the 'width' option is specified, prepends zeros for numeric types.
	> dafault : prepends spaces
	>> example : `printf("%4x", 3)` ==> `   3` / `printf(%04x", 3)` ==> `0003`
- `'` : The integer or exponent of a decimal has the thousands grouping separator applied
- `#` : Alternate form
	> for g and G type : trailing zeros are not removed  
	> for f, F, e, E, g, G type : the output always contains a decimal point  
	> for o, x, X type : the text 0, 0x, 0X, respectively, is prepended to non-zero numbers

#### Width field
- Width field specifies a minimum number of charaters to output
	> it does not cause truncation of oversized fields
- The width field may be **omitted**, or a **numeric integer value**, or a **dynamic value** when passed as another argument when indicated by an asterisk `*`.
	> example : `printf("%*d", 5, 10)` ==>    10
	>> 1. a leading zero is interpreted as the zero-padding flag mentioned above
	>> 1. negative value is treated as the positive value in conjunction with the left-alignment - flag also mentioned above.

#### Precision field
- Precision field specifies a maximum limit on the output
	> 1. floating-point numeric type : it specifies the number of digits to the right of the decimal point that the output should be rounded
	> 1. string type : it limits the number of characters that should be output, after which the string is truncated.
- The width field may be **omitted**, or a **numeric integer value**, or a **dynamic value** when passed as another argument when indicated by an asterisk `*`.
	> example : `printf("%.*s", 3, "abcdef")` ==> `abc`

#### Type field

- c : prints single charater
- s : prints a string(as defined by the common C convention)
- p : The void * pointer argument has to be printed hexadecimal format
- d : prints a decimal(base10) number
- i : prints an integer in base 10
- u : prints an unsinged decimal (base 10) number
- x : prints a number in hexadecimal (base 16) lowercase format
- X : prints a number in hexadecimal (base 16) uppercase format
- % : prints a percent sign

### Rules

|-|width|percision(default=0)|percision(with n)|-|+|' '|0|#|
|---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|c|o|o|x|o|x|x|x|x|
|s|o|o|o|o|x|x|x|x|
|p|o|o|x|o|x|x|x|x|
|d|o|o|o|o|o|o|o|x|
|i|o|o|o|o|o|o|o|x|
|u|o|o|o|o|x|x|o|x|
|x|o|o|o|o|x|x|o|o|
|X|o|o|o|o|x|x|o|o|
|%|o|o|o|o|o|o|o|o|

#### c
- width : len보다 클 때 좌측 공백
- precision(default) : 변화 없음
- '-' : width가 len보다 클 때 우측 공백

#### s
- width : len보다 클 때 좌측 공백
- precision(default) : 문자열이 출력되지 않음
- precision(with n) : 출력할 문자열의 최대길이 제한
	- 설정한 길이가 문자열보다 크다면 원래 문자열 출력
	> 즉, `len > precision >= 0` 구간일 때 `len = precision` 이라고 볼 수 있음
- '-' : width가 len보다 클 때 우측 공백

#### p
- width : len보다 클 때 좌측 공백
- precision(default) : 변화 없음
- '-' : width가 len 보다 클 때 우측 공백

#### d
- width : len보다 클 때 좌측 공백
- precision(default) : 0 flags가 있을 경우 무시
	- precision이 0이면서 숫자가 0일경우 숫자를 출력하지 않음
- precision(with n) : len보다 작으면 무시, len보다 크면 남는자리를 0으로 채움 / width는 해당 precision동작이 적용된 길이를 제외하고 적용
- '-' : width가 len보다 클 때 우측 공백
	- '-' 와 '0' 이 동시에 존재하면 '0' 은 무시
- '+' : 출력할 숫자 앞에 부호표시
	- '+' 와 ' ' 가 동시에 존재하면 ' ' 은 무시
- ' ' : 출력할 숫자 앞에 공백표시(음수이 때는 - 표시)
	> '+' 와 ' '처럼 부호표시의 경우 width 범위에 포함되지만 공백보다 선행해서 출력된다
- '0' : width가 공백을 출력하는 대신 0을 출력



#### i

#### u

#### x

#### X

#### %

#### 추가 고려사항
- result 가 int를 초과했을 때 에러
	- long long을 초과했을 경우에는 정상임 ==> width, precision에 값이 담길때 atoi를 거치기 때문으로 추측됨(atoi가 ll까지 받지만 int초과하는 수에 대해서 에러)

## Mandatory part

|Program name|libftprintf.a|
|---|---|
|Turn in files|Makefile, \*.h, \*/\*.h, \*.c, \*/\*.c|
|Makefile|NAME, all, clean, fclean, re|
|External functs|malloc, free, write, va\_start, va\_arg, va\_copy, va\_end|
|libft authorized|yes|
|description|write a library that contains ft\_printf(), a function that will mimic the original printf()|

- prototype : `int	ft_printf(const char *, ...)`
- Don't implement the buffer management
- handle the following conversions: cspdiuxX%

## Bonus part

- Manage any combination of the following flags : '-0.' and the feild minimum width under all conversions
- Manage all the follwing flags : '# +'

## Reference
[Variadic function in C programming](https://medium.com/swlh/variadic-function-in-c-programming-d3632315a48e)

[printf format string](https://en.wikipedia.org/wiki/Printf_format_string)

[가변인자 규칙과 매개변수 스택](https://blog.naver.com/wkdghcjf1234/221738196805)
