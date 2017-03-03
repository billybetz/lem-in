/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <bbetz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 19:35:30 by bbetz             #+#    #+#             */
/*   Updated: 2017/02/27 01:49:19 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <dirent.h>
# define I_MIN -2147483648
# define I_MAX 2147483647
# define BASE2 01
# define BASE10 0123456789
# define BASE16 0123456789ABCDEFG
# define BUFF_SIZE 42
# define DEFAULT "\033[0m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define WHITE "\x1B[37m"
# define BLUE "\x1B[0;34m"
# define BROWN "\x1B[0;33m"
# define CYAN "\x1B[0;36m"
# define GREY "\x1B[1;30m"
# define PURPLE "\x1B[0;35m"
# define LIGHT_BLACK "\033[1;30m"
# define LIGHT_RED "\033[1;31m"
# define LIGHT_GREEN "\033[1;32m"
# define LIGHT_YELLOW "\033[1;33m"
# define LIGHT_BLUE "\033[1;34m"
# define LIGHT_PURPLE "\033[1;35m"
# define LIGHT_CYAN "\033[1;36m"
# define LIGHT_GREY "\033[1;37m"
# define ABS(Value) (Value < 0 ? -Value : Value)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl
{
	int				i;
	int				ret;
	char			buff[BUFF_SIZE + 1];
}					t_gnl;

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

int					ft_success(char *str, int ret_value);
void				*ft_failure(char *str, void *ret_value);
void				ft_exit_error(char *msg);
void				ft_debug(void);
int					ft_error_msg(char *str, int ret);
void				ft_free_double_pointer(void ***pointer);
double				ft_get_distance(t_point pos_char, t_point p1);
int					ft_exit_failure_malloc(void);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putcolor(char *s, char *color);
void				ft_putcolorendl(char *s, char *color);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbrcolor(int n, char *color);
void				ft_putnbrendl(int nbr);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
size_t				ft_strlen(const char *str);
int					ft_nbrlen(int nb);
int					ft_count_words(const char *str);
int					ft_get_size_tab(void **tab);
void				ft_print_strtab(char **str);
char				**ft_strtabdup(const char **tab);
void				ft_strtabadd(char ***tab, char *str);
char				**ft_strtabtrim(char **input);
int					ft_str_is_void(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strdup_f_t(const char *src, size_t from, size_t to);
int					ft_strfindchar(char *str, char c);
char				*ft_str_spacearround(const char *str, char c);
int					ft_str_count_c(char *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strsub(char	const *s, size_t start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_str_to_tab(char const *str);
char				**ft_strsplit(char const *s, char c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcpy_f_t(char *s, const char *s2, size_t f, size_t t);
char				*ft_strncpy(char *dest, char *src, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strstr(char *str, char *to_find);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, int nb);
size_t				ft_strlcat(char *s1, const char *s2, size_t size);
int					ft_get_file(char *av, char ***map);
void				ft_get_stdin(char ***map);
int					ft_str_is_number(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isspace(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isdirectory(char *path);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_have_return(char *s);
int					ft_have_digit(char *s);
int					ft_have_alpha(char *s);
int					ft_atoi(const char *str);
char				*ft_itoa(int nbr);
char				*ft_convert_base(char *nb, char *b_f, char *b_to);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					get_next_line(const int fd, char **line);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list*elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
