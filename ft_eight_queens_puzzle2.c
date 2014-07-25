/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhordern <lhordern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 17:59:02 by lhordern          #+#    #+#             */
/*   Updated: 2014/02/06 11:52:03 by lhordern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_queens_puzzle(void);
int		ft_verif(int *table, int queen);
void	ft_find_queens(int *table, int queen);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putint(int *table, int len);

int		main()
{
	ft_queens_puzzle();
	return (0);
}

int		ft_verif(int *table, int queen)
{
	int		i;

	i = 0;
	while (i < queen)
	{
		if (table[i] == table[queen]
			|| (table[queen] == table[i] + (queen - i))
			|| (table[queen] == table[i] - (queen - i)))
			return (1);
		i++;
	}
	return (0);
}

void		ft_find_queens(int *table, int queen)
{
	static int		possibility = 0;

	table[queen]++;
	if (table[queen] > 8)
	{
		table[queen] = 0;
		ft_find_queens(table, queen - 1);
	}
	else
	{
		while (ft_verif(table, queen) == 1 && table[queen] < 8)
			table[queen]++;
		if (ft_verif(table, queen) == 0 && queen != 7)
			ft_find_queens(table, queen + 1);
		else
		{
			if (queen == 1 && table[0] == 8)
				ft_putnbr(possibility);
			else
			{
				if (queen == 7 && ft_verif(table, queen) == 0 && possibility++)
					ft_putint(table, 8);
				table[queen] = 0;
				ft_find_queens(table, queen - 1);
			}
		}
	}
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_putint(int *table, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_putnbr(table[i]);
		i++;
	}
	ft_putchar('\n');
}

void	ft_queens_puzzle()
{
	int		table[8] = { 0 };

	ft_find_queens(table, 0);
}
