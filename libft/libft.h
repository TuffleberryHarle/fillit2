/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanhand <mcanhand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:52:20 by mcanhand          #+#    #+#             */
/*   Updated: 2019/05/09 20:33:20 by mcanhand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_list_push_back(t_list **begin_list, void *data);
void				*ft_memalloc(size_t size);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putnbr(int n);
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
void				ft_bzero(void *s, size_t n);
void				ft_strclr(char *s);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isalpha(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_any(char **tab, int (*f)(char*));
int					ft_count_if(char **tab, int (*f)(char*));
int					get_next_line(int const fd, char **line);

char				*ft_strcpy(char *dest, const char *src);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strdup(const char *src);
char				*ft_strcat(char *dest, const char *src);
char				*ft_itoa(int n);
char				*ft_reverse(char *s);
char				*ft_strnew(size_t size);
char				*strchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr(const char *str, const char *to_find,
size_t len);
char				*ft_strncat(char *dest, const char *src, size_t nb);
char				*ft_strncpy(char *dst, const char *src, size_t len);

size_t				ft_strlen(char const *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_create_elem(void *data);
t_list				*ft_list_at(t_list *begin_list, unsigned int nbr);

#endif
