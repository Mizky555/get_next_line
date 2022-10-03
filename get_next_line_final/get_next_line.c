/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 00:54:50 by tsirirak          #+#    #+#             */
/*   Updated: 2022/10/03 02:47:30 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2, int len_s2)
{
	char	*str;
	int		len;

	len = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1 == NULL)
		len = len_s2;
	else
		len = ft_strlen(s1) + len_s2;
	str = ft_strjoin_2(s1, s2, len_s2, len);
	if (s1)
		free(s1);
	return (str);
}

char	*ft_strjoin_2(char *s1, char *s2, int len_s2, int len)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, len + 1);
	while (s1 != NULL && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 != NULL && j < len_s2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char			*buf;
	char			*str;
	static t_box	b;

	buf = NULL;
	str = NULL;
	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	str = get_next_line_2(fd, buf, &b);
	if (str == NULL)
	{
		str = ft_strjoin(str, b.str, len_newline(b.str, ft_strlen(b.str), 1));
		b.str = ft_strchr_l(b.str, 0);
		if (buf)
		{
			free(buf);
			buf = NULL;
		}
		return (str);
	}
	b.str = ft_strchr_l(buf, 0);
	return (str);
}

char	*get_next_line_2(int fd, char *buf, t_box *b)
{
	char	*str;
	int		len_buf;
	int		b_len;
	int		len_nl;

	str = NULL;
	b_len = ft_strlen(b->str);
	len_nl = len_newline(b->str, b_len, 1);
	ft_memset(buf, 0, BUFFER_SIZE + 1);
	if (b->str != NULL && len_nl == b_len)
		str = b->str;
	while (b->str == NULL || (b->str && len_nl == b_len))
	{
		len_buf = read(fd, buf, BUFFER_SIZE);
		if (len_buf == 0)
			break ;
		buf[len_buf] = 0;
		str = ft_strjoin(str, buf, len_newline(buf, len_buf, 1));
		if (len_newline(buf, len_buf, 2) != 0)
			break ;
	}
	return (str);
}
/*
ft_lennewline ไว้หาความยาวจนกว่าจะเจอจัว \n <- ใช้ เก็บ ตัด แบ่ง แบะๆ
b.str = เก็บค่าไว้ใช้ในการเรียก get_next_line รอบถัดไป
74 b.str = ft_strchr_l(b.str, 0);
   เก็บค่าตั้งแต่หลัง \n เป็นต้นไป ใน ft_strchr_l มีเรียกใช้ ft_strjoin
96 memset เพื่อกันขยะที่อาจจะมีอยู่ก่อน
97 b.str ต้องมีค่า และ ต้องเจอ \n <- จะไม่เข้าเงื่อนไขนี้ในการเรียก gnl รอบแรก (เพราะรอบแรกb.strจะยังไม่มีค่าเก็บ)
   จะให้ str = b.str
99 ถ้า b.str มีค่า หรือ (b.str มีค่า และ ยังไม่เจอ \n) จึงเข้าลูป
   ลูปจะหยุดก็ต่อเมื่อเจอ \n แล้ว
*/