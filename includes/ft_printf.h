#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int		ft_printf(const char *format, ...);
char	*ft_convert_base(char *lol, char *lel, char *lal);

#endif
