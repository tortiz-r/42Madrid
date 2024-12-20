#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int i = 0;
	char big[10] = "hoholalaa";
	char litlle[4] = "hol";
	char *ptr;
	ptr = strnstr(big, little, 7);
	while(i < 5)
	{
		printf("%p \n", ptr[i]);
		i++;
	}
}
