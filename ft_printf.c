#include	"ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		i;
	int		buffer_size;
	va_list	ap;

	i = 0;
	buffer_size = 0;
	va_start(ap, s);
	if(!s)
		return (-1);
	while(s[i] != 0)
	{

	}
	va_end(ap);
	return (buffer_size);
}