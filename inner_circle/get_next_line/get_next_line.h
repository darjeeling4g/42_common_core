#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char			*get_next_line(int fd);
static char		*ft_strjoin(char const *s1, char const *s2);
static size_t	ft_strlen(const char *s);

#endif
