/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjungo <qjungo@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:22:48 by qjungo            #+#    #+#             */
/*   Updated: 2022/10/25 17:05:22 by qjungo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

char	*get_next_line(int fd);

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}	t_list;

enum e_bool {
	FALSE,
	TRUE,
	SUCCESS = 0,
	ERROR = 1,
};

void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmem, size_t size);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *string);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *string);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_strlen(const char *string);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_realloc(void *ptr, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memchr(const void *str, int c, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strrchr(char *str, int c);
char	*ft_strchr(char *str, int c);

/// Bonus officiels
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));

/// Non official bonus
void	strrev(char *string);
char	*utoa(unsigned int n);
char	*itoa_base(unsigned long long int n, char *base, unsigned int n_base);
int		strlen_until(const char *string, const char *charset);
char	*char_to_str(char c);
int		is_in_charset(char c, const char *charset);

//	Printf !!
int	ft_printf(const char *string, ...);
#endif

// void	color(int color, int font);
/* enum e_color {
	BLUE,
	RED,
	YELLOW,
	PURPLE,
	GREEN,
	CYAN,
	WHITE,
	RESET,
	BOLD,
	STD,
};

void	ft_color(int color, int font)
{
	if (color == RESET)
		printf("\033[0m");
	if (color == RED)
		printf("\033[0;31m");
	if (color == GREEN)
		printf("\033[0;32m");
	if (color == YELLOW)
		printf("\033[0;33m");
	if (color == BLUE)
		printf("\033[0;34m");
	if (color == PURPLE)
		printf("\033[0;35m");
	if (color == CYAN)
		printf("\033[0;36m");
	if (color == WHITE)
		printf("\033[0;37m");
	if (font == BOLD)
		printf("\033[1m");
}
*/
