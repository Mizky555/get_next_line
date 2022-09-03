#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char get_next_line(int fd)
{
    char *buf;
    size_t len;

    len = read(fd ,*buf ,5);
    printf("len = %zu,*buf = %s",len, buf);
    return(0);

}

int main()
{
    get_next_line(open("opal"));
}