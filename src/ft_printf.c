#include "../includes/ft_printf.h"

static char	*ft_char2str(char c)
{
	char	*str;

	str = ft_strnew(2);
	str[0] = c;
	str[1] = 0;
	return (str);
}

static char	*parser(va_list pa, const char *format)
{
	char *tmp;

	tmp = NULL;	
	if (*format == '%')
		return("%");
	if (*format == 'd' || *format == 'i')
		return (ft_itoa(va_arg(pa, int)));
	if (*format == '-')
	{
		ft_putstr_color(CRED, "salut", CEND);
	}
	if (*format == '+' && !(va_arg(pa, int) < 0))
		ft_putchar('+');
//	if (*format == 's')
//		return (va_arg(pa, char *));
//	if (*format == 'c')
//		return (ft_char2str(va_arg(pa, int)));
//	if (*format ==e'o')
//		return (ft_convert_base(ft_itoa(va_arg(pa, int)), "0123456789", "01234567"));
	return("");
}

int		ft_printf(const char *format, ...)
{
	va_list 	pa;
	char		*str;
	char		*final;

	final = ft_strnew(1);
	str = NULL;
	va_start(pa, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			str = parser(pa, ++format);
		}
		else
			str = ft_char2str(*format);
		final = ft_strjoin(final, str);
		++format;
	}
	ft_putstr(final);
	free(final);
	va_end(pa);
	return (ft_strlen(final));
}



/*
 *
 * %
 *---------------------------
 *option
 * -	()
 * +	()
 * #	(???)
 * "0"	(<- char (optionel, sinon space) a caller a gauche) -> nb de ce char
 *---------------------------
 *largeur 
 	(int de la taille minmale)
 *---------------------------
 *precision
 	(float)
 *---------------------------
 *taille
 *---------------------------
 *type de convertion
 *	(sSpdDioOuUxXcC)
*/

