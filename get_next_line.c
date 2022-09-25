#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int   ft_strlen(const char *s)
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

char	*ft_strchr_l(const char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (i <= ft_strlen(s))
		{
			if (s[i] == '\n')
			{
				return ((char *)&s[i + 1]);
			}
			i++;
		}
	}
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
				return (i);
			i++;
		}
		return (len_buf);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2, int len_s2)
{
	char	*str;
	int	i;
	int		j;
	int	len;

	i = 0;
	j = 0;
	// printf("len_s2 = %d\n",len_s2);
	// printf("nee\n");
	if (!s1 && !s2)
		retuern (NULL);
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
	str[i] = '\0';
	return (str);
}

char *get_next_line(int fd)
{
    char *buf;
    int len_buf;
	char *str;
	static t_box b;

	str = NULL;
    buf = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (buf == NULL)
		return (NULL);
	if (b.str != NULL && len_newline(b.str,ft_strlen(b.str)) == ft_strlen(b.str)) //ถ้าเจอ \n ใน b.str และ ตำแหน่งของ \n อยู่ทีตำแหน่งสุเท้ายของ b.str ให้ str = b.str
		str = b.str;
	while (b.str == NULL || len_newline(b.str,ft_strlen(b.str)) == ft_strlen(b.str)) //b.str == NULL หรือ ถ้าเจอ \n ใน b.str และ ตำแหน่งของ \n อยู่ทีตำแหน่งสุเท้ายของ b.str
	{
		len_buf = read(fd, buf, BUFFER_SIZE);//อ่านไฟล์ใส่เข้า buf
		if (len_buf == 0) //ถ้าอ่านหมดไฟล์แล้ว len_buf จะเป็น 0 > Break
			break;
		str = ft_strjoin(str,buf,len_newline(buf, len_buf)); // ถ้าอ่านเจอจะจับ buf ที่จนถึง \n ไปต่อท้าย
		if (len_newline(buf, len_buf) != len_buf) //ถ้าเจอ \n ใน buf จะถูกเตะออก
			break;
	}
	if (str == NULL) 
	{
		// printf("remaining\n");
		str = ft_strjoin(str,b.str,len_newline(b.str, ft_strlen(b.str)));
		// printf("remaining2\n");
		b.str = ft_strchr_l(b.str);
		// printf("b.str ft_strchr = %s \n",b.str);
		return (str);
	}
	else
		b.str = ft_strchr_l(buf);
	//printf("b.str ft_strchr = %s \n",b.str);
	return (str);
}

int main()
{
    int	fd;
    	fd = open("opal", O_RDONLY);
    	printf("get_next_line = %s\n",get_next_line(fd));
		printf("get_next_line = %s\n",get_next_line(fd));
		printf("get_next_line = %s\n",get_next_line(fd));
		printf("get_next_line = %s\n",get_next_line(fd));
		printf("get_next_line = %s\n",get_next_line(fd));
		printf("get_next_line = %s\n",get_next_line(fd));
		
}
