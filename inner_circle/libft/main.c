/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:29:33 by siyang            #+#    #+#             */
/*   Updated: 2022/07/12 12:07:19 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "./ft_isalpha.c"
#include "./ft_isdigit.c"
#include "./ft_isalnum.c"
#include "./ft_isascii.c"
#include "./ft_isprint.c"
#include "./ft_strlen.c"
#include "./ft_memset.c"
#include "./ft_bzero.c"
#include "./ft_memcpy.c"
#include "./ft_memmove.c"
#include "./ft_strlcpy.c"
#include "./ft_strlcat.c"
#include "./ft_strncmp.c"
#include "./ft_toupper.c"
#include "./ft_tolower.c"
#include "./ft_strchr.c"
#include "./ft_strrchr.c"
#include "./ft_memchr.c"
#include "./ft_memcmp.c"

int main()
{
	printf("============<ft_isalpha>==============\n");
	printf("ft_isalpha : %d\n", ft_isalpha('a'));
	printf("isalpha : %d\n", isalpha('a'));
	printf("ft_isalpha : %d\n", ft_isalpha('4'));
	printf("isalpha : %d\n", isalpha('4'));
	printf("============<ft_isdigit>==============\n");
	printf("ft_isdigit : %d\n", ft_isdigit(5));
	printf("isdigit : %d\n", isdigit(5));
	printf("ft_isdigit : %d\n", ft_isdigit('4'));
	printf("isdigit : %d\n", isdigit('4'));
	printf("============<ft_isalnum>==============\n");
	printf("ft_isalnum : %d\n", ft_isalnum('a'));
	printf("isalnum : %d\n", isalnum('a'));
	printf("ft_isalnum : %d\n", ft_isalnum('4'));
	printf("isalnum : %d\n", isalnum('4'));
	printf("ft_isalnum : %d\n", ft_isalnum(4));
	printf("isalnum : %d\n", isalnum(4));
	printf("============<ft_isascii>==============\n");
	printf("ft_isascii : %d\n", ft_isascii('a'));
	printf("isascii : %d\n", isascii('a'));
	printf("ft_isascii : %d\n", ft_isascii('4'));
	printf("isascii : %d\n", isascii('4'));
	printf("============<ft_isprint>==============\n");
	printf("ft_isprint : %d\n", ft_isprint(128));
	printf("isprint : %d\n", isprint(128));
	printf("ft_isprint : %d\n", ft_isprint(32));
	printf("isprint : %d\n", isprint(32));
	printf("============<ft_strlen>==============\n");
	printf("ft_strlen : %lu\n", ft_strlen("This is test string."));
	printf("strlen : %lu\n", strlen("This is test string."));
	printf("============<ft_memset>==============\n");
	char a[] = "test string";
	char b[] = "test string";
	ft_memset(a, '*', 5);
	memset(b, '*', 5);
	printf("ft_memset : %s\n", a);
	printf("memset : %s\n", b);
	printf("============<ft_bzero>==============\n");
	ft_bzero(a, 5);
	printf("ft_bzero : %d, %c\n", a[4], a[5]);
	bzero(b, 5);
	printf("bzro : %d, %c\n", b[4], b[5]);
	printf("============<ft_memcpy>==============\n");
	char c[] = "ft_memcpy";
	char d[] = "memcpy";
	ft_memcpy(c+1, c, 9);
	memcpy(d+1, d, 6);
	printf("ft_memcpy : %s\n", c);
	printf("memcpy : %s\n", d);
	printf("============<ft_memmove>==============\n");
	char e[] = "ft_memmove";
	char f[] = "memmove";
	ft_memmove(e+1, e, 9);
	memmove(f+1, f, 6);
	printf("ft_memmove : %s\n", e);
	printf("memmove : %s\n", f);
	printf("============<ft_strlcpy>==============\n");
	char g[] = "string";
	char h[] = "string";
	char i[] = "test";
	printf("ft_strlcpy : %zu\n", ft_strlcpy(g, i, 5));
	printf("ft_strlcpy : %s\n", g);
	printf("strlcpy : %zu\n", strlcpy(h, i, 5));
	printf("strlcpy : %s\n", h);
	printf("============<ft_strlcat>==============\n");
	printf("ft_strlcat : %zu\n", ft_strlcat(g, i, 7));
	printf("ft_strlcat : %s\n", g);
	printf("strlcat : %zu\n", strlcat(h, i, 7));
	printf("strlcat : %s\n", h);
	printf("============<ft_strncmp>==============\n");
	printf("ft_strncmp : %d, %d\n", ft_strncmp(g, i, 4), ft_strncmp(g, i, 5));
	printf("strncmp : %d, %d\n", strncmp(g, i, 4), strncmp(g, i, 5));
	printf("============<ft_toupper>==============\n");
	printf("ft_toupper : %c\n", ft_toupper('c'));
	printf("toupper : %c\n", toupper('c'));
	printf("============<ft_tolower>==============\n");
	printf("ft_tolower : %c\n", ft_tolower('C'));
	printf("tolower : %c\n", tolower('C'));
	printf("============<ft_strchr>==============\n");
	char j[] = "test string";
	printf("ft_strchr : %s, %s, %s\n", ft_strchr(j, 'g'), ft_strchr(j, 'h'), ft_strchr(j, 0));
	printf("strchr : %s, %s, %s\n", strchr(j, 'g'), strchr(j, 'h'), strchr(j, 0));
	printf("============<ft_strrchr>==============\n");
	printf("ft_strrchr : %s, %s, %s\n", ft_strrchr(j, 'g'), ft_strrchr(j, 'h'), ft_strrchr(j, 0));
	printf("strrchr : %s, %s, %s\n", strrchr(j, 'g'), strrchr(j, 'h'), strrchr(j, 0));
	printf("============<ft_memchr>==============\n");
	printf("ft_memchr : %s, %s, %s\n", ft_memchr(j, 'g', 12), ft_memchr(j, 'h', 12), ft_memchr(j, 0, 12));
	printf("memchr : %s, %s, %s\n", memchr(j, 'g', 12), memchr(j, 'h', 12), memchr(j, 0, 12));
	printf("============<ft_memcmp>==============\n");
	printf("ft_memcmp : %d, %d\n", ft_memcmp(g, i, 4), ft_memcmp(g, i, 5));
	printf("memcmp : %d, %d\n", memcmp(g, i, 4), memcmp(g, i, 5));
	return (0);
 }
