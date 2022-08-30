# Libft
> Your very first own library
>> This project is about coding a C library.
It will contain a lot of general purpose functions your programs will rely upon.

## Part 1 - Libc functions

<details>
<summary>INDEX</summary>

1. [isalpha](#ft\_isalpha)
1. [isdigit](#ft\_isdigit)
1. [isalpha](#ft\_isalpha)
1. [isalpha](#ft\_isalpha)
1. [isalpha](#ft\_isalpha)
1. [isalpha](#ft\_isalpha)
1. [isalpha](#ft\_isalpha)
1. [isalpha](#ft\_isalpha)
1. [isalpha](#ft\_isalpha)
1. [isalpha](#ft\_isalpha)
1. [isalpha](#ft\_isalpha)

</details>

### form
- Detail

	|Function name||
	---|---
	Prototype|` `
	Parameters|
	Return value|
	External functions|-
	Description|


- Original function
	```c

	```
- Result
	```c

	```

### ft\_isalpha
- Detail

	|Function name|ft\_isalpha|
	---|---
	Prototype|`int	ft_isalpha(int c);`
	Parameters|c : The character to be tested.
	Return value|The isalpha() function returns zero if the character tests false and returns non-zero if the character tests true.
	External functions|-
	Description|The isalpha() function tests for any character for which isupper(3) or islower(3) is true. <br> The value of the argument must be representable as an unsigned char or the value of EOF.


- Original function
	```c
	int
	isalpha(c)
		int c;
	{
		/*
		 * Depends on ASCII-like character ordering.
		 */
		return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? 1 : 0);
	}
	```
- Result
	```c
	int	ft_isalpha(int c)
	{
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
			return (1);
		else
			return (0);
	}
	```

### ft\_isdigit
- Detail

	|Function name|ft\_isdigit|
	---|---
	Prototype|`int	ft_isdigit(int c);`
	Parameters|c : The character to be tested.
	Return value|The isdigit() and isnumber() functions return zero if the character tests false and return non-zero if the character tests true.
	External functions|-
	Description|The isdigit() function tests for a decimal digit character. <br> The value of the argument must be representable as an unsigned char or the value of EOF.


- Original function
	```c
	int
	isdigit(c)
		int c;
	{
		/*
		 * Depends on ASCII-like character ordering.
		 */
		return (c >= '0' && c <= '9' ? 1 : 0);
	}
	```
- Result
	```c
	int	ft_isdigit(int c)
	{
		if (c >= '0' && c <= '9')
			return (1);
		else
			return (0);
	}
	```

## Reference
