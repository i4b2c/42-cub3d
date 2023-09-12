/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icaldas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:32:58 by icaldas           #+#    #+#             */
/*   Updated: 2023/01/26 18:52:53 by icaldas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <string.h>
# include <stdio.h>
# include <strings.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <inttypes.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

int				ft_isalpha(int x);
int				ft_isdigit(int x);
int				ft_isascii(int x);
int				ft_isalnum(int x);
int				ft_isprint(int x);
int				ft_strlen(char *x);
int				ft_memcmp(const void *x, const void *y, size_t z);
int				ft_toupper(int x);
int				ft_tolower(int x);
int				ft_strncmp(char *x, char *y, unsigned int z);
int				ft_atoi(const char *x);
int				ft_lstsize(t_list *lst);
int				ft_printf(const char *s, ...);
int				print_n_cont(va_list args, char ch);
int				ft_pointer(void *s);
int				ft_uphexa(unsigned int n);
int				ft_hexa(unsigned int n);
int				ft_lenhexa(unsigned int n);
int				ptrlen(void *p);
int				ft_printstr(char *s);
int				ft_putchar_rint(int i);
int				ft_printuinumb(unsigned int n);
int				ft_unumlen(unsigned int n);
int				ft_printnumb(int n);
void			ft_putnbr_fd(int x, int y);
void			*ft_memset(void *x, int y, size_t z);
void			ft_bzero(void *x, size_t y);
void			*ft_memcpy(void *x, const void *y, size_t z);
void			*ft_memmove(void *x, const void *y, size_t z);
void			*ft_memchr(const void *x, int y, size_t z);
void			*ft_calloc(size_t x, size_t y);
void			ft_putstr_fd(char *x, int y);
void			ft_putchar_fd(char x, int y);
void			ft_putendl_fd(char *x, int y);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_lstadd_front(t_list **x, t_list *y);
void			ft_lstadd_back(t_list **x, t_list *y);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_putunbr_fd(unsigned int i, int fd);
void			ft_lstiter(t_list *lst, void (*f)(void *));
size_t			ft_strlcpy(char *x, const char *y, size_t z);
size_t			ft_strlcat(char *x, const char *y, unsigned int z);
char			*ft_strchr(char *x, int y);
char			*ft_strcpy(char *s, char *c);
char			*ft_strrchr(const char *x, int y);
char			*ft_strnstr(const char *x, const char *y, size_t z);
char			*ft_strdup(const char *x);
char			*ft_substr(char const *x, unsigned int y, size_t z);
char			*ft_strjoin(char *x, char *y);
char			*ft_strtrim(char const *x, char const *y);
char			*ft_itoa(int x);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			ft_ptr_hexa(int n);
char			*ft_uitoa(unsigned int n);
char			ft_ptr_hexa(int n);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*));
char			*get_next_line(int x);
char			*get_str(int x, char *y);
char			*get_new_str(char *x);
char			*get_line(char *x);
int				ft_strlen(char *str);
char			*get_line(char *str);
char			*get_new_str(char *str);
char			*get_str(int fd, char *str);
char			*get_next_line(int fd);
char			*ft_gnl_strchr(char *s, int c);
char			*ft_gnl_strjoin(char *s1, char *s2);

#endif
