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

void	*ft_memset(void *b, int c, size_t len);
int   ft_strlen(char *s);
char	*ft_strchr_l(char *s);
int	len_newline(char *buf,int len_buf, int mode);
char	*ft_strjoin(char *s1, char *s2, int len_s2);
char *get_next_line(int fd);
void	*ft_memset(void *b, int c, size_t len);
int   ft_strlen(char *s);


#endif
