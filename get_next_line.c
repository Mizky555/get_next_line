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
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	printf("len_s2 = %d\n",len_s2);
	if (s1 == NULL)
		len = len_s2;
	else
		len = ft_strlen(s1) + len_s2;
	
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);

	while (s1 != NULL && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 != NULL && j < len_s2)
		str[i++] = s2[j++];
	// while (i < len)
	// {

	// 	if (i < ft_strlen(s1))
	// 		str[i] = s1[j1++];
	// 	else if (i < len)
	// 		str[i] = s2[j2++];
	// 	i++;
	// }
	str[i] = '\0';
	return (str);
}

char *get_next_line(int fd)
{
    char *buf;
    int len_buf;
	char *str;
	static box b;

	str = NULL;
    buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (buf == NULL)
		return (NULL);

	while (b.str == NULL || len_newline(b.str,ft_strlen(b.str)) == ft_strlen(b.str))
	{
		len_buf = read(fd, buf, BUFFER_SIZE);
		str = ft_strjoin(str,buf,len_newline(buf, len_buf));
		if (len_newline(buf, len_buf) != len_buf) //ถ้าเจอ \n ให้ต่อแล้วเบรก
			break;

		// if (len_buf == 0)
		// {
		// 	buf = b.str;
		// 	printf("Sssssssssssssssssssssssssssssssssssssss\n");
		// 	len_buf = ft_strlen(buf);
		// 	break;
		// }
		// else
		// 	len_buf = read(fd, buf, BUFFER_SIZE);
		// if (len_newline(buf, len_buf) != len_buf) //ถ้าเจอ \n ให้ต่อแล้วเบรก
		// {
		// 	str = ft_strjoin(b.str,buf,len_newline(buf, len_buf));
		// 	printf("buf = %s\n",buf);
		// 	printf("len_buf = %d\n",len_buf);
		// 	printf("str strjoin(str,buf,num) = %s\n",str);
		// 	break;
		// }
	}
	if (str == NULL)
	{
		str = ft_strjoin(str,b.str,len_newline(b.str, ft_strlen(b.str)));
		b.str = ft_strchr_l(b.str);
		printf("b.str ft_strchr = %s \n",b.str);
		return (str);
	}
	b.str = ft_strchr_l(buf);
	printf("b.str ft_strchr = %s \n",b.str);
	return (str);
}

int main()
{
    int	fd;
		//printf("ft_strchr_l = %s\n",ft_strchr_l("opal\n123",'a'));
    	fd = open("opal", O_RDONLY);
    	printf("get_next_line = %s\n",get_next_line(fd));
		printf("get_next_line = %s\n",get_next_line(fd));
		//printf("get_next_line = %s\n",get_next_line(fd));
}
