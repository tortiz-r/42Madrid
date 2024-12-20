#include<unistd.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void	ptr_argv(int i);

int	main(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	printf("%i \n",  argc);
	printf("%s \n", *(argv + 1));
	while (i <argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			printf("%c \n", argv[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
