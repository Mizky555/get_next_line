#include "main.h"

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

char    *get_next_line(int fd)
{
    char    *buf;
    int len_buf;
    static  box b;
    char    *str;

    buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    b.str = (char *)malloc(sizof(char) * BUFFER_SIZE + 1);
    while (1)
    {
        int i_buf;

        i_buf = 0;
        buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
        len_buf = read(fd, buf ,BUFFER_SIZE);
        while (BUFFER_SIZE > i_buf)
        {
            if (buf[i_buf] == '\n' || buf[i_buf] == '\0')
            {
                b.str = buf;
                return (str);
            }
            str = ft_strjoin(str, buf[i_buf]);
            i_buf++;
        }
    }
}


int main()
{
    int fd;
    fd = open("opal_i",O_RDONLY);
    printf("--get_next_line--\n%s",get_next_line(fd));
    close(fd);
}