/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:42:50 by afaugero          #+#    #+#             */
/*   Updated: 2025/01/10 18:29:08 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

# define BUFFER_SIZE 80
# define FT_HEX_BASE_LOW "0123456789abcdef"
# define FT_HEX_BASE_UP "0123456789ABCDEF"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
int		ft_atoi(char const *nptr);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(char const *c);
size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char const *src, size_t dstsize);
char	*ft_strchr(char const *s, int c);
char	*ft_strrchr(char const *s, int c);
char	*ft_strdup(char const *s1);
char	*ft_strndup(char const *s1, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strnstr(char const *big, char const *little, size_t len);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_ulong_itoa_base(unsigned long nbr, char const *base_to);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

// linked list
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new_elem);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new_elem);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// printf
int		ft_printf(const char *s, ...);
void	ft_write(va_list args, char const *s, int *count);
int		ft_parse(va_list args, char c);
int		ft_parse_char(char c);
int		ft_parse_str(char *str);
int		ft_parse_void(void *addr);
int		ft_parse_int(int nbr);
int		ft_parse_udec(unsigned int nbr);
int		ft_parse_hex(unsigned long nb, char c);

#endif
