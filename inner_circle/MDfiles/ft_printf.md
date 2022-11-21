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
- Prototype : `return_type func_name(type arg1, ...)
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
- `#` : Alternate form`
	> for g and G type : trailing zeros are not removed  
	> for f, F, e, E, g, G type : the output always contains a decimal point  
	> for o, x, X type : the text 0, 0x, 0X, respectively, is prepended to non-zero numbers

#### Width field
- Width field specifies a minimum number of charaters to output
	> it does not cause truncation of oversized fields
- The width field may be **omitted**, or a **numeric integer value**, or a **dynamic value** when passed as another argument when indicated by an asterisk `*`.
	> example : `printf("%*d", 5, 10)` ==> `   10`
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

#### 


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
