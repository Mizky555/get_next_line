#include "main.h"

char    *get_next_line(int fd)
{
    char    *buf;
    int len_buf;
    static  box b;

    buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    len_buf = read(fd,buf,BUFFER_SIZE);
    b.str = buf;
    return(b.str);

    while (1)
    {
        while (BUFFER_SIZE>)
    }
}

int main()
{
    int fd;
    fd = open("opal_i",O_RDONLY);
    printf("--get_next_line--\n%s",get_next_line(fd));
    close(fd);
}