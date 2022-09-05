# Libft
> Your very first own library
>> This project is about coding a C library.
It will contain a lot of general purpose functions your programs will rely upon.

## Part 1 - Libc functions

<details>
<summary>INDEX</summary>

1. [ft\_isalpha](#ft\_isalpha)
1. [ft\_isdigit](#ft\_isdigit)
1. [ft\_isalnum](#ft\_isalpha)
1. [ft\_isascii](#ft\_isalpha)
1. [ft\_isprint](#ft\_isprint)
1. [ft\_strlen](#ft\_strlen)
1. [ft\_memset](#ft\_memset)
1. [ft\_bzero](#ft\_bzero)
1. [ft\_memcpy](#ft\_memcpy)
1. [ft\_strlcpy](#ft\_strlcpy)
1. [ft\_strlcat](#ft\_strlcat)
1. [ft\_toupper](#ft\_toupper)
1. [ft\_tolower](#ft\_tolower)
1. [ft\_strchr](#ft\_strchr)
1. [ft\_strrchr](#ft\_strrchr)
1. [ft\_strncmp](#ft\_strncmp)
1. [ft\_memchr](#ft\_memchr)
1. [ft\_memcmp](#ft\_memcmp)
1. [ft\_strnstr](#ft\_strnstr)
1. [ft\_atoi](#ft\_atoi)
1. [ft\_calloc](#ft\_calloc)
1. [ft\_strdup](#ft\_strdup)
1. [ft\_substr](#ft\_substr)
1. [ft\_strjoin](#ft\_strjoin)
1. [ft\_strtrim](#ft\_strtrim)
1. [ft\_split](#ft\_split)
1. [ft\_itoa](#ft\_itoa)
1. [ft\_strmapi](#ft\_strmapi)
1. [ft\_striteri](#ft\_striteri)
1. [ft\_putchar\_fd](#ft\_putchar\_fd)
1. [ft\_putstr\_fd](#ft\_putstr\_fd)
1. [ft\_putendl\_fd](#ft\_putendl\_fd)
1. [ft\_putnbr\_fd](#ft\_putnbr\_fd)
1. [ft\_lstnew](#ft\_lstnew)
1. [ft\_lstadd\_front](#ft\_lstadd\_front)
1. [ft\_lstsize](#ft\_lstsize)
1. [ft\_lstlast](#ft\_lstlast)
1. [ft\_lstadd\_back](#ft\_lstlast)
1. [ft\_lstdelone](#ft\_lstdelone)
1. [ft\_lstclear](#ft\_lstclear)
1. [ft\_lstiter](#ft\_lstiter)
1. [ft\_lstmap](#ft\_lstmap)

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
- Apple Open Source
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
- Apple Open Source
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
- Apple Open Source
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

### ft\_isalnum
- Detail
	|Function name|ft\_isalnum|
	---|---
	Prototype|`int	ft_isalnum(int c);`
	Parameters|c : The character to be tested.
	Return value|The isalnum() function returns zero if the character tests false and returns non-zero if the character tests true.
	External functions|-
	Description|The isalnum() function tests for any character for which isalpha(3) or isdigit(3) is true.  The value of the argument must be representable as an unsigned char or the value of EOF.
- Result
	```c
	int	ft_isalnum(int c)
	{
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
			return (1);
		else if (c >= '0' && c <= '9')
			return (1);
		else
			return (0);
	}
	```

### ft\_isascii
- Detail
	|Function name|ft\_isascii|
	---|---
	Prototype|`int	ft_isascii(int c);`
	Parameters|c : The charater to be tested.
	Return value|The isascii() function returns zero if the character tests false and returns non-zero if the character tests true.
	External functions|-
	Description|The isascii() function tests for an ASCII character, which is any character between 0 and octal 0177 inclusive.
- Result
	```c
	int	ft_isascii(int c)
	{
		if (c >= 0 && c <= 127)
			return (1);
		else
			return (0);
	}
	```

### ft\_isprint
- Detail
	|Function name|ft\_isprint|
	---|---
	Prototype|`int	ft_isprint(int c);`
	Parameters|c : The charater to be tested.
	Return value|The isprint() function returns zero if the character tests false and returns non-zero if the character tests true.
	External functions|-
	Description|The isprint() function tests for any printing character, including space (` ').  The value of the argument must be representable as an unsigned char or the value of EOF.
- Result
	```c
	int	ft_isprint(int c)
	{
		if (c >= 32 && c <= 126)
			return (1);
		else
			return (0);
	}
	```

### ft\_strlen
- Detail
	|Function name|ft\_strlen|
	---|---
	Prototype|`size_t	ft_strlen(const char *s);`
	Parameters|s : The string to be scanned.
	Return value|The strlen() function returns the number of characters that precede the terminating NUL character.
	External functions|-
	Description|The strlen() function computes the length of the string s.
- Apple Open Source
	```c
	size_t
	strlen(str)
		const char *str;
	{
		register const char *s;

		for (s = str; *s; ++s);
		return(s - str);
	}
	```
- Result
	```c
	size_t	ft_strlen(const char *s)
	{
		size_t	len;

		len = 0;
		while (*s)
		{
			s++;
			len++;
		}
		return (len);
	}
	```

### ft\_memset
- Detail
	|Function name|ft\_memset|
	---|---
	Prototype|`void	*ft_memset(void *b, int c, size_t len);`
	Parameters|b : The address of array to be:
	Return value|The memset() function returns its first argument.
	External functions|-
	Description|The memset() function writes len bytes of value c (converted to an unsigned char) to the string b.
- Apple Open Source
	```c

	```
- Result
	```c
	void	*ft_memset(void *b, int c, size_t len)
	{
		unsigned char	*temp;
		unsigned char	value;
		size_t			i;

		temp = b;
		value = (unsigned char)c;
		i = 0;
		while (i < len)
		{
			temp[i] = value;
			i++;
		}
		return (b);
	}
	```

## Reference
