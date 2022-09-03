#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	size_t i;
	size_t len;
	int j1;
	int j2;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * len + 1);
	i = 0;
	j1 = 0;
	j2 = 0;
	if ((s1 == NULL && s2 == NULL) || (str == NULL))
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

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (size <= 0)
		return (srcsize);
	else if (srcsize + 1 < size)
		ft_memcpy(dst, src, srcsize + 1);
	else
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (srcsize);
}
