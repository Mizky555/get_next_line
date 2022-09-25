#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = c;
		i++;
	}
	return (b);
}

int   ft_strlen(char *s)
{
    int    i;

    i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}

char	*ft_strchr_l(char *s)
{
	int	i;
	char *str;

	i = 0;
	str = NULL;
	if (s && s[i])
	{
		while (i < ft_strlen(s))
		{
			if (s[i] == '\n')
			{
				str = ft_strjoin(str, &s[i + 1], ft_strlen(&s[i + 1]));
				//return ((char *)&s[i + 1]);
				// printf("debug: %d\n", s[i+1]);
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

int	len_newline(char *buf,int len_buf){
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
		return (len_buf);
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, int len_s2)
{
	char	*str;
	int	i;
	int		j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	// printf("len_s2 = %d\n",len_s2);
	// printf("nee\n");
	str = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (s1 == NULL)
		len = len_s2;
	else
		len = ft_strlen(s1) + len_s2;
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
	if (s1)
		free(s1);
	return (str);
}

char *get_next_line(int fd)
{
    char *buf;
    int len_buf;
	char *str;
	static t_box b;

	buf = NULL;
	str = NULL;
	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
    buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (buf == NULL)
		return (NULL);
	ft_memset(buf, 0, BUFFER_SIZE + 1);
	if (b.str != NULL && len_newline(b.str,ft_strlen(b.str)) == ft_strlen(b.str)) //ถ้าเจอ \n ใน b.str และ ตำแหน่งของ \n อยู่ทีตำแหน่งสุเท้ายของ b.str ให้ str = b.str
		str = b.str;
	while (b.str == NULL || len_newline(b.str,ft_strlen(b.str)) == ft_strlen(b.str)) //b.str == NULL หรือ ถ้าเจอ \n ใน b.str และ ตำแหน่งของ \n อยู่ทีตำแหน่งสุเท้ายของ b.str
	{
		len_buf = read(fd, buf, BUFFER_SIZE);//อ่านไฟล์ใส่เข้า buf
		if (len_buf == 0) //ถ้าอ่านหมดไฟล์แล้ว len_buf จะเป็น 0 > Break
			break;
		buf[len_buf] = 0;
		str = ft_strjoin(str,buf,len_newline(buf, len_buf)); // ถ้าอ่านเจอจะจับ buf ที่จนถึง \n ไปต่อท้าย
		printf("str = %s\n", str);
		if (len_newline(buf, len_buf) != len_buf) //ถ้าเจอ \n ใน buf จะถูกเตะออก
			break;
	}
	printf("exit\n");
	// printf("store bstr = %s\n", b.str);
	if (str == NULL) 
	{
		// printf("remaining\n");
		str = ft_strjoin(str,b.str,len_newline(b.str, ft_strlen(b.str)));
		// printf("remaining2\n");
		b.str = ft_strchr_l(b.str);
		// printf("b.str ft_strchr = %s \n",b.str);
		if (buf)
		{
			free(buf);
			buf = NULL;
		}
		// printf("after strchr = %s\n", b.str);
		return (str);
	}
	
	b.str = ft_strchr_l(buf);
	// printf("after strchr = %s\n", b.str);
	// if (buf)
	// {
	// 	free(buf);
	// 	buf = NULL;
	// }
	//printf("b.str ft_strchr = %s \n",b.str);
	return (str);
}

