
int main(int argc, char **argv)
{
    int	fd;
	char *str;

	(void) argc;
	str = NULL;
	fd = open(argv[1], O_RDONLY);

	str = get_next_line(fd);
	printf("get_next_line = %s\n",str);
	free(str);
	str = NULL;

	str = get_next_line(fd);
	printf("get_next_line = %s\n",str);
	free(str);
	str = NULL;

	str = get_next_line(fd);
	printf("get_next_line = %s\n",str);
	free(str);
	str = NULL;

	str = get_next_line(fd);
	printf("get_next_line = %s\n",str);
	free(str);
	str = NULL;

	str = get_next_line(fd);
	printf("get_next_line = %s\n",str);
	free(str);
	str = NULL;

	close(fd);
}