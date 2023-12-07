/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvan-hal <jvan-hal@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:40:46 by jvan-hal      #+#    #+#                 */
/*   Updated: 2022/10/21 14:38:43 by jvan-hal      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

static void	recursive_putnbr(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		c = '-';
		write(fd, &c, 1);
		n *= -1;
	}
	if (n >= 10)
	{
		recursive_putnbr(n / 10, fd);
		recursive_putnbr(n % 10, fd);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	recursive_putnbr(n, fd);
}
