#include "main.h"

size_t    ft_strlen(const char *s)
{
    int    i;

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
    return (str);
}

char    *get_next_line(int fd)
{
    char    *buf;
    int len_buf;
    static  box b;
    char    *str;
    int i_buf;

    b.str = (char *) malloc(sizeof(char) * BUFFER_SIZE + 1);
    i_buf = 0;
    while (1)
    {
        buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
        len_buf = read(fd, buf ,BUFFER_SIZE);
        if (b.len == 0)
            b.len = 0;
        while(i_buf < BUFFER_SIZE)
        {
            
            // if (buf[i_buf] == '\n' || buf[i_buf] == '\0')
            // {
            //     return (str);
            // }
            // str = ft_strjoin_cha(str, buf[i_buf]);
            // i_buf++;
            if (buf[i_buf] == '\n' || buf[i_buf] == '\0')
            {
                b.str = buf;
                str = ft_strjoin_cha(str, buf[i_buf]);
                if (buf[i_buf] != '\0')
                    str = ft_strjoin_cha(str, '\0');
                b.len = i_buf + 1;
                return (str);
            }
            str = ft_strjoin_cha(str, buf[i_buf]);
            i_buf++;
        }
        free(buf);
    }
}


int main()
{
    int fd;
    fd = open("opal_i", O_RDONLY);
    printf("line = %s\n", get_next_line(fd));
    printf("line = %s\n", get_next_line(fd));
    printf("line = %s\n", get_next_line(fd));
    close(fd);
}