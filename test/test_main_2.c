char    *get_next_line(int fd)
{
    char    *buf;
    int len_buf;


    buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    len_buf = read(fd,buf,BUFFER_SIZE);
    return()
}

int main()
{
    int fd;
    fd = open("opal_i",O_RDONLY);
    printf("--get_next_line--\n%s",get_next_line(fd));
    close(fd);
}