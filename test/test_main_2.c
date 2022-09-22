#include "main.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *ft_strjoin_cha(char *s1, char c)
{
	char *str;
	size_t i;
	size_t len;
	int j1;
	int j2;

	i = 0;
	len = ft_strlen(s1) + 1;
	str = malloc(sizeof(char) * len + 1);

	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
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

    b.str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    while (1)
    {
        int i_buf;

        i_buf = 0;
        buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
        len_buf = read(fd, buf ,BUFFER_SIZE);
		printf("len_buf  read   = %d\n", len_buf);
		printf("BUFFER_SIZE = %d\n",BUFFER_SIZE);
		printf("i_buf = %d\n",i_buf);
		int buf_int = BUFFER_SIZE;
        while (buf_int > i_buf)
        {
			printf("while i_buf = %d",i_buf);
            if (buf[i_buf] == '\n' || buf[i_buf] == '\0')
            {
                b.str = buf;
				str = ft_strjoin_cha(str, buf[i_buf]);
				printf("b join = %s\n",str);
				if (buf[i_buf] != '\0')
					str = ft_strjoin_cha(str, '\0');
                return (str);
            }
            str = ft_strjoin_cha(str, buf[i_buf]);
			printf("back join = %s\n",str);
            i_buf++;
        }
		return(0);
		free(buf);
    }
}


int main()
{
    int fd;
    fd = open("opal_i",O_RDONLY);
    printf("--get_next_line--\n%s",get_next_line(fd));
    close(fd);
}