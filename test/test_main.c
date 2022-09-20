#include "main.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *str;
	size_t i;
	size_t len;
	int j1;
	int j2;

	i = 0;
	j1 = 0;
	j2 = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * len + 1);

	while (i < len)
	{
		if (i < ft_strlen(s1))
			str[i] = s1[j1++];
		else if (i < len)
			str[i] = s2[j2++];
		i++;
	}
	str[i] = '\0';
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (str);
}

char *get_next_line(int fd)
{
	static box b;
	char *buf;
	int len_buf;
    char *stray;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
  if (b.str == 0)
		b.str = malloc(sizeof(char) * 3);
	
  while (1)
    {
      int i_stray;
      int len_to_newline;
      i_stray = 0;
      len_to_newline = 0;
	  BUFFER_SIZE == BUFFER_SIZE - 1;
      len_buf = read(fd,buf,BUFFER_SIZE);
      b.str = ft_strjoin(b.str,buf);
      while (b.str[len_to_newline] != '\n' || len_to_newline > len_buf)
        {
          printf("len_to_newline %d\n",len_to_newline);
          len_to_newline++;
        }
      stray = malloc(sizeof(char) * (ft_strlen(b.str)-len_to_newline));
      while (len_to_newline <= ft_strlen(b.str))
        {
          b.str[len_to_newline] = stray[i_stray];
          len_to_newline++;
          i_stray++;
        }
      return (b.str);
    }
	return(b.str);
}

int main()
{
	int fd;
	fd = open("opal_i",O_RDONLY);
	printf("get_next_linr = %s",get_next_line(fd));

	close(fd);
}