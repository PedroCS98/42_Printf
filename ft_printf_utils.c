#include	"ft_printf.h"

int ft_putchar(char x)
{
	return (write(1, &x, 1));
}

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		ft_putchar(s[i++]);
	return (i);
}

int ft_putnbr(int n)
{
	char	str[12];
	int		index;
	long	nbr;

	str[11] = 0;
	nbr = n;
	index = 10;
	if (n < 0)
		nbr = -nbr;
  if (n == 0)
		return (ft_putstr("0"));
	while (nbr > 0)
	{
		str[index--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		str[index--] = '-';
	ft_putstr(&str[index + 1]);
	return (10 - index);
}

int ft_putunbr(unsigned int u)
{
	char	str[12];
	int		index;
	long	nbr;

	str[11] = 0;
	nbr = u;
	index = 10;
	if (u == 0)
		return (ft_putstr("0"));
	while (nbr > 0)
	{
		str[index--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	ft_putstr(&str[index + 1]);
	return (10 - index);
}