/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpaparon <rpaparon@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:46:50 by rpaparon          #+#    #+#             */
/*   Updated: 2025/03/03 20:02:33 by rpaparon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h> 
# include <fcntl.h>

//libft
//chars
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *little, size_t len);

//ints

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_bzero(void *s, int n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_printf(const char *str, ...);

//size_t

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, unsigned int dstsize);

//void

void	*ft_memset(void *ptr, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//ft_printf

void	ft_putchar_fd(char c, int fd);
void	ft_printp(unsigned long long value, int *counter);
void	ft_putnbr_fd(int n, int fd);
void	ft_printu(unsigned int value, int *counter);
void	ft_printhex(unsigned int value, const char c, int *counter);
void	ft_printid(int value, int *counter);

//gnl

char    *get_next_line(int fd);
char    *stash_filling(int fd, char *stash, char *buffer);
char    *extract_line(char *stash);
char    *extract_new_stash(char *stash);

#endif
