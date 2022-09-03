char get_next_line(int fd)
{
    void *buf;
    int len;

    len = read(fd ,*buf ,5);
    printf("len = %zu,*buf = %s",len,*buf);
    return(0);

}

int main()
{
    get_next_line(open("opal"));
}