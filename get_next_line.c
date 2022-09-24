#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

size_t    ft_strlen(const char *s)
{
    size_t    i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char	*ft_strchr_l(const char *s)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == '\n')
		{
			return ((char *)&s[i + 1]);
		}
		i++;
	}
	return (0);
}



int	len_newline(char *buf,int len_buf){
    int i;

    i = 0;
    while(i <= len_buf)
    {
        if (buf[i] == '\n')
            return (i);
        i++;
    }
    return (len_buf);
}
char	*ft_strjoin(char const *s1, char const *s2, size_t len_s2)
{
	char	*str;
	size_t	i;
	int		j1;
	int		j2;
	size_t	len;

	len = ft_strlen(s1) + len_s2;
	str = malloc(sizeof(char) * len + 1);
	i = 0;
	j1 = 0;
	j2 = 0;
	if (str == NULL)
		return (NULL);
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	while (i < len)
	{
		if (i < ft_strlen(s1))
			str[i] = s1[j1++];
		else if (i < len)
			str[i] = s2[j2++];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *get_next_line(int fd)
{
    char *buf;
    int len_buf;
	char *str;
	static box b;

	printf("aaa\n");
    buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (buf == NULL)
		return (NULL);
	len_buf = read(fd, buf, BUFFER_SIZE);
	printf("len_buf = %d",len_buf);
    str = ft_strjoin(str,buf,len_newline(buf, len_buf));
	printf("str strjoin(str,buf,num) = %s\n",str);
	b.str = ft_strchr_l(buf);
	printf("b.str ft_strchr = %s \n",b.str);
   
}

int main()
{
    int	fd;
		//printf("ft_strchr_l = %s\n",ft_strchr_l("opal\n123",'a'));
    	fd = open("opal", O_RDONLY);
    	printf("get_next_line = %s\n",get_next_line(fd));
}
