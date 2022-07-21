#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set);
{
	size_t	len;
	char	*ptr;
	char	*start;
	char	*end;

	len = ft_strlen(set);
	while (*set)
	{
		start = strchr(s1, *set);
		end = strrchr(s1, *set);
		if (end ==)
	}
}
