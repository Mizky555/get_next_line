#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strchr_l(char *s, int i)
{
	char *str;

	str = NULL;
	if (s && s[i])
	{
		while (i < ft_strlen(s))
		{
			if (s[i] == '\n')
			{
				str = ft_strjoin(str, &s[i + 1], ft_strlen(&s[i + 1]));
				if (!str[0])
				{
					free(str);
					str = NULL;	
				}
				if (s)
					free(s);
				return (str);
			}
			i++;
		}
	}
	if (s)
		free(s);
	return (NULL);
}

int	len_newline(char *buf,int len_buf, int mode){
    int i;

    i = 0;
	if (buf)
	{
		while(i <= len_buf)
		{
			if (buf[i] == '\n')
				return (i + 1);
			i++;
		}
		if (mode == 1)
			return (len_buf);
		else if (mode == 2)
			return (0);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, int len_s2)
{
	char	*str;
	int	len;

	len = 0;
	
	if (!s1 && !s2)
		return (NULL);
	if (s1 == NULL)
		len = len_s2;
	else
		len = ft_strlen(s1) + len_s2;
	
	str = wai_koi_kid(s1, s2, len_s2,len);


	if (s1)
		free(s1);
	return (str);
}

char	*ft_strjoin_2(char *s1, char *s2, int len_s2, int len)
{
	int i = 0;
	int j =  0;
	char	*str;

	str = NULL;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, len + 1);

	while (s1 != NULL && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 != NULL && j < len_s2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char *get_next_line(int fd)
{
    char *buf;
	char *str;
	static t_box b;

	buf = NULL;
	str = NULL;
	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buf == NULL)
		return (NULL);
	str = wai_koi_kid_2(fd ,buf , &b);
	if (str == NULL) 
	{
		str = ft_strjoin(str,b.str,len_newline(b.str, ft_strlen(b.str), 1));
		b.str = ft_strchr_l(b.str, 0);
		if (buf)
		{
			free(buf);
			buf = NULL;
		}
		return (str);
	}
	b.str = ft_strchr_l(buf, 0);
	return (str);
}

char	*get_next_line_2(int fd, char *buf, t_box *b)
{
	char *str;
	int len_buf;
	
	str = NULL;
	ft_memset(buf, 0, BUFFER_SIZE + 1);
	if (b->str != NULL && len_newline(b->str,ft_strlen(b->str),1) == ft_strlen(b->str))
		str = b->str;
	while (b->str == NULL || len_newline(b->str,ft_strlen(b->str),1) == ft_strlen(b->str))
	{
		len_buf = read(fd, buf, BUFFER_SIZE);
		if (len_buf == 0)
			break;
		buf[len_buf] = 0;
		str = ft_strjoin(str,buf,len_newline(buf, len_buf,1));
		if (len_newline(buf, len_buf, 2) != 0)
			break;
	}
	return (str);
}