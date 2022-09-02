/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:29:33 by siyang            #+#    #+#             */
/*   Updated: 2022/09/02 13:14:34 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char test_function(unsigned int i, char c)
{
	(void)i;
	c = c - 32;
	return (c);
}
void test_function2(unsigned int i, char *c)
{
	(void)i;
	printf("%c", (*c - 32));
}

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
	char c[] = "memcpy";
	char d[] = "memcpy";
	memcpy(d+1, d, 6);
	ft_memcpy(c+1, c, 6);
	printf("ft_memcpy : %s\n", c);
	printf("memcpy : %s\n", d);

	ft_memcpy(a, c, 9);
	memcpy(b, d, 6);
	printf("ft_memcpy : %s\n", a);
	printf("memcpy : %s\n", b);
	printf("ft_memcpy : %s\n", ft_memcpy(NULL ,NULL, 9));
	printf("memcpy : %s\n", memcpy(NULL ,NULL, 6));
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
	printf("ft_strlcpy : %zu\n", ft_strlcpy(g, i, 0));
	printf("ft_strlcpy : %s\n", g);
	printf("ft_strlcpy : %zu\n", ft_strlcpy(g, i, 5));
	printf("ft_strlcpy : %s\n", g);
	printf("strlcpy : %zu\n", strlcpy(h, i, 0));
	printf("strlcpy : %s\n", h);
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
	printf("ft_memchr : %s, %s, %s\n", (char *)ft_memchr(j, 'g', 12), (char *)ft_memchr(j, 'h', 12), (char *)ft_memchr(j, 0, 12));
	printf("memchr : %s, %s, %s\n", (char *)memchr(j, 'g', 12), (char *)memchr(j, 'h', 12), (char *)memchr(j, 0, 12));
	printf("============<ft_memcmp>==============\n");
	printf("ft_memcmp : %d, %d\n", ft_memcmp(g, i, 4), ft_memcmp(g, i, 5));
	printf("memcmp : %d, %d\n", memcmp(g, i, 4), memcmp(g, i, 5));
	printf("============<ft_strnstr>==============\n");
	char *haystack = "find needle in this string";
	char *needle = "needle";
	printf("ft_strnstr : %s\n", ft_strnstr(haystack, needle, 15));
	printf("strnstr : %s\n", strnstr(haystack, needle, 15));
	printf("ft_strnstr : %s\n", ft_strnstr("", "coucou", -1));
	printf("strnstr : %s\n", strnstr("", "coucou", -1));
	printf("============<ft_atoi>==============\n");
	printf("ft_atoi : %d\n", ft_atoi("2147483647"));
	printf("atoi : %d\n", atoi("2147483647"));
	printf("ft_atoi : %d\n", ft_atoi("-2147483648"));
	printf("atoi : %d\n", atoi("-2147483648"));
	printf("ft_atoi : %d\n", ft_atoi("2147483648"));
	printf("atoi : %d\n", atoi("2147483648"));
	printf("ft_atoi : %d\n", ft_atoi("-2147483648"));
	printf("atoi : %d\n", atoi("-2147483648"));
	printf("ft_atoi : %d\n", ft_atoi("+2147483647"));
	printf("atoi : %d\n", atoi("+2147483647"));
	printf("ft_atoi : %d\n", ft_atoi("   +2147483647string"));
	printf("atoi : %d\n", atoi("   +2147483647string"));
	printf("ft_atoi : %d\n", ft_atoi("   +-2147483647string"));
	printf("atoi : %d\n", atoi("   +-2147483647string"));
	printf("ft_atoi : %d\n", ft_atoi("   +   2147483647string"));
	printf("atoi : %d\n", atoi("   +   2147483647string"));
	printf("==========================\n");
	printf("ft_atoi Max-1 : %d\n", ft_atoi("9223372036854775806"));
	printf("atoi Max-1: %d\n", atoi("9223372036854775806"));
	printf("ft_atoi Max: %d\n", ft_atoi("9223372036854775807"));
	printf("atoi Max: %d\n", atoi("9223372036854775807"));
	printf("ft_atoi Max+1: %d\n", ft_atoi("9223372036854775908"));
	printf("atoi Max+1: %d\n", atoi("9223372036854775908"));
	printf("ft_atoi Max+2: %d\n", ft_atoi("9223372036854775909"));
	printf("atoi Max+2: %d\n", atoi("9223372036854775909"));
	printf("ft_atoi Min+2: %d\n", ft_atoi("-9223372036854775806"));
	printf("atoi Min+2: %d\n", atoi("-9223372036854775806"));
	printf("ft_atoi Min+1: %d\n", ft_atoi("-9223372036854775807"));
	printf("atoi Min+1: %d\n", atoi("-9223372036854775807"));
	printf("ft_atoi Min: %d\n", ft_atoi("-9223372036854775908"));
	printf("atoi Min: %d\n", atoi("-9223372036854775908"));
	printf("ft_atoi Min-1: %d\n", ft_atoi("-9223372036854775909"));
	printf("atoi Min-1: %d\n", atoi("-9223372036854775909"));
	printf("============<ft_calloc>==============\n");
	char *p1 = ft_calloc(5, 1);
	char *p2 = calloc(5, 1);
	printf("ft_calloc : %d, %d\n", p1[0], p1[4]);
	printf("calloc : %d, %d\n", p2[0], p2[4]);
	free(p1);
	free(p2);
	p1 = ft_calloc(0, 1);
	p2 = calloc(0, 1);
	printf("ft_calloc : %d\n", p1[0]);
	printf("calloc : %d\n", p2[0]);
	free(p1);
	free(p2);
	size_t max = SIZE_MAX;
	printf("max value : %zu\n", max * 1);
	printf("max value : %zu\n", max * 2);
	printf("max value : %zu\n", max * 3);
	printf("max value : %zu\n", max * 4);
	printf("max value : %zu\n", max * 100000);
	printf("max value : %zu\n", max * (max-1));
	printf("max value : %zu\n", max * max);
	printf("max value : %zu\n", max - 8192);
	p1 = calloc(max - 8193, 1);
	p2 = ft_calloc(max - 8193, 1);
	printf("calloc : %d\n", p1 == NULL);
	printf("ft_calloc : %d\n", p2 == NULL);
	printf("============<ft_strdup>==============\n");
	printf("ft_strdup : %s\n", ft_strdup("test string"));
	printf("strdup : %s\n", strdup("test string"));
	printf("============<ft_substr>==============\n");
	printf("ft_substr : %s\n", ft_substr("test string", 5, 6));
	printf("ft_substr : %s\n", ft_substr("test string", 5, 0));
	printf("ft_substr : %s\n", ft_substr("test string", 20, 6));
	printf("ft_substr : %s\n", ft_substr("test string", 11, 5));
	printf("============<ft_strjoin>==============\n");
	printf("ft_strjoin : %s\n", ft_strjoin("test", "string"));
	printf("============<ft_strtrim>==============\n");
	printf("ft_strtrim : %s\n", ft_strtrim("acbabbctestcabcbaacbba", "abc"));
	printf("ft_strtrim : %s\n", ft_strtrim("acbabbctestcabcbaacbba", ""));
	printf("ft_strtrim : %s\n", ft_strtrim("", "abc"));
	printf("============<ft_split>==============\n");
	char **sp = ft_split("ccccstring1ccccstring2cstring3", 'c');
	printf("ft_split : %s\n", sp[0]);
	printf("ft_split : %s\n", sp[1]);
	printf("ft_split : %s\n", sp[2]);
	printf("============<ft_itoa>==============\n");
	printf("ft_itoa : %s\n", ft_itoa(+0));
	printf("ft_itoa : %s\n", ft_itoa(-0));
	printf("ft_itoa : %s\n", ft_itoa(+2147483647));
	printf("ft_itoa : %s\n", ft_itoa(-2147483648));
	printf("============<ft_strmapi>==============\n");
	printf("ft_strmapi : %s\n", ft_strmapi("test_string", test_function));
	printf("============<ft_striteri>==============\n");
	char *striteri = "striteri";
	ft_striteri(striteri, test_function2);
	printf("ft_striteri : %s\n", striteri);
	printf("============<ft_putchar_fd>==============\n");
	ft_putchar_fd('c', 1);
	printf("============<ft_putstr_fd>==============\n");
	ft_putstr_fd("test string", 1);
	printf("============<ft_putendl_fd>==============\n");
	ft_putendl_fd("test string", 1);
	printf("============<ft_putnbr_fd>==============\n");
	ft_putnbr_fd(2147483647, 1);
	ft_putnbr_fd(-2147483648, 1);
	printf("============<ft_lstfunction>==============\n");
	t_list	**lst;
	t_list	*l1, *l2, *l3;
	l1 = malloc (sizeof(t_list));
	l2 = malloc (sizeof(t_list));
	l3 = malloc (sizeof(t_list));
	lst = &l1;
	l1->next = l2;
	l1->content = "l1";
	l2->next = l3;
	l2->content = "l2";
	l3->next = NULL;
	l3->content = "l3";
	ft_lstadd_front(lst, ft_lstnew("l0"));
	printf("ft_lstadd_front : %s\n", (char*)((*lst)->content));
	printf("ft_lstsize : %d\n", ft_lstsize(*lst));
	ft_lstadd_back(lst, ft_lstnew("l4"));
	printf("ft_lstadd_back : %s\n", (char*)(ft_lstlast(*lst)->content));
	printf("ft_lstsize : %d\n", ft_lstsize(*lst));
	return (0);
}
