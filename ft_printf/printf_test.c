# include "ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

int main(void)
{
	char *str= "adios";
	//printf("prueba_printf: c es %c ; string es: %s ; d es: %d ; i es: %i ; u es: %u , percent es: %%\n", 'a', " holii ", 5, 0, 4294967296, 4);
	//ft_printf("prueba_printf: c es %c ; string es: %s ; d es: %d ; i es: %i ; u es: %u , percent es: %%\n", 'a', " holii ", 5, 0, 4294967296, 4);
	//slay funciona todo los ph de c, s, d, i , u, %%!!!!!
	// printf("num_args es: %i", 5);
	printf(" PRINTF DEVUELVE %p ,\n", str);
	ft_printf("ptr devuelto es: %p\n", str);
	//ft_printf(" FT_PRINTF DEVUELVE %p .\n", (void *) str);
	//printf("El 0 en hex (l) es: %s", ft_hex_itoa(0, 'u'));

	return (0);
}
// c s p d i u x X %
// Falta:
// p: puntero void * dado como argumento se imprime en formato hexadecimal
// pendiente hacer ptr_hex

//para compilar y ejecutar cosas:
// cc -c sources.o sources.c (paso aux files .c a .o)
// cc -o NAME sources.o -L. -lftprintf

//Con make quedaría:

//make
// cc -c test.o test.c
// cc -o run -L. -lftprintf
// ./run.out