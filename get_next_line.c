#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

char get_next_line(int fd)
{
    char *buf;
    size_t len_buf;

    buf = (char *)malloc(BUFFER_SIZE * (sizeof(char)) + 1);
    while (1)
    {
        len_buf = read(fd, buf, BUFFER_SIZE);
        int i;
        char *srtjoy;
        i = 0;
        while (i < len_buf)
        {
            if (buf[i] == "\n")
            {
                return (srtjoy);
            }
            i++;
        }
    }
    buf[len_buf] = '\0';
    printf("len_buf = %zu,*buf = %s",len_buf, buf);
    return(0);

}

int main()
{
    get_next_line(open("opal",O_RDONLY));
}
