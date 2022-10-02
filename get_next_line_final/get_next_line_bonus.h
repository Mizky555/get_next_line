/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 04:06:57 by tsirirak          #+#    #+#             */
/*   Updated: 2022/10/03 04:30:53 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_box
{
	char	*str;
	int		len;
}	t_box;

void	*ft_memset(void *b, int c, size_t len);
int		ft_strlen(char *s);
char	*ft_strchr_l(char *s, int i);
int		len_nl(char *buf, int len_buf, int mode);
char	*ft_join(char *s1, char *s2, int len_s2);
char	*get_next_line(int fd);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strlen(char *s);
char	*ft_strjoin_2(char *s1, char *s2, int len_s2, int len);
char	*get_next_line_2(int fd, char *buf, t_box *b);

#endif
