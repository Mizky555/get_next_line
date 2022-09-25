#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_box
{
	char	*str;
	char	*stray;
	int	len;
}	t_box;

char *get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2, int len_s2);

#endif
