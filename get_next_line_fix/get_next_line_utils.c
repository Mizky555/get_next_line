#include "get_next_line.h"

void    *fee(char *s)
{
    if (s)
     free(s);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = c;
		i++;
	}
	return (b);
}

int   ft_strlen(char *s)
{
    int    i;

    i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}

char	*ft_strchr_l(char *s)
{
	int	i;
	char *str;

	i = 0;
	str = NULL;
	if (s && s[i])
	{
		while (i < ft_strlen(s))
		{
			if (s[i] == '\n')
			{
				str = ft_strjoin(str, &s[i + 1], ft_strlen(&s[i + 1]));
				if (!str[0])
				{
					free(str);
					str = NULL;	
				}
				fee(s);
				return (str);
			}
			i++;
		}
	}
	fee(s);
	return (NULL);
}//25

int	len_newline(char *buf,int len_buf, int mode)
{
    int i;

    i = 0;
	if (buf)
	{
		while(i <= len_buf)
		{
			if (buf[i] == '\n')
				return (i + 1);
			i++;
		}
		if (mode == 1)
			return (len_buf);
		else if (mode == 2)
			return (0);
	}
	return (0);
}