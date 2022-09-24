#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2, size_t len_s2)
{
	char	*str;
	size_t	i;
	int		j1;
	int		j2;
	size_t	len;

	len = ft_strlen(s1) + len_s2;
	str = malloc(sizeof(char) * len + 1);
	i = 0;
	j1 = 0;
	j2 = 0;
	if (str == NULL)
		return (NULL);
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	while (i < len)
	{
		if (i < ft_strlen(s1))
			str[i] = s1[j1++];
		else if (i < len)
			str[i] = s2[j2++];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char get_next_line(int fd)
{
    char *buf;

    len_buf = read(fd, buf, BUFFER_SIZE);
    while (1)
    
}

int main()
{
    int	fd;
    printf("strjoin opal,hello,3",ft_strjoin("opal","hello",3));
    //fd = open("opal_i", O_RDONLY);
    //printf("get_next_line = \n",get_next_line(fd));
}
