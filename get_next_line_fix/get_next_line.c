#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2, int len_s2)
{
	char	*str;
	int	i;
	int		j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
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
}//31

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
	if (b.str != NULL && len_newline(b.str,ft_strlen(b.str),1) == ft_strlen(b.str))
		str = b.str;
	while (b.str == NULL || len_newline(b.str,ft_strlen(b.str),1) == ft_strlen(b.str))
	{
		len_buf = read(fd, buf, BUFFER_SIZE);
		if (len_buf == 0)
			break;
		buf[len_buf] = 0;
		str = ft_strjoin(str,buf,len_newline(buf, len_buf,1));
		if (len_newline(buf, len_buf, 2) != 0)
			break;
	}
	if (str == NULL) 
	{
		str = ft_strjoin(str,b.str,len_newline(b.str, ft_strlen(b.str),1));
		b.str = ft_strchr_l(b.str);
		if (buf)
		{
			free(buf);
			buf = NULL;
		}
		return (str);
	}
	
	b.str = ft_strchr_l(buf);
	return (str);
} //39

