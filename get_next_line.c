#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

size_t len_newline(const char *buf)
{
	size_t len;

	len = 0;
	while(buf[len] != '\n')
		len++;
	return (len);
}

char get_next_line(int fd)
{
    char *buf;
	char *str;
    size_t len_buf;

	str = NULL;
    buf = (char *)malloc(BUFFER_SIZE * (sizeof(char)) + 1);
    while (1)
    {
        len_buf = read(fd, buf, BUFFER_SIZE);
        int i;

		i = 0;
		str = ft_strjoin(str, buf);
        while (i < len_buf)
        {
            if (buf[i] == '\n')
            {
                 (str + len_buf);
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
