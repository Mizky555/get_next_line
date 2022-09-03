#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char get_next_line(int fd)
{
    char *buf;
    size_t len;

    buf = (char *)malloc(BUFFER_SIZE * (sizeof(char)) + 1);
    while (1)
    {
        len = read(fd, buf, BUFFER_SIZE);
        int i;
        char *srtjoy;
        i = 0;
        while (i < len)
        {
            if (buf[i] == "\n")
            {
                return (srtjoy);
            }
            
        }
    }
    buf[len] = '\0';
    printf("len = %zu,*buf = %s",len, buf);
    return(0);

}

int main()
{
    get_next_line(open("opal",O_RDONLY));
}