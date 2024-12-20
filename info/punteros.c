int main(void)
{
	long a = 2;
	long *apuntoaA = a;	
	long *apuntoadirA= &a;
	void *voidaA = &a;
	long *apuntoa_apuntoaA = &apuntoaA;

	printf("apuntoaA: %p \n apunroadirA: %p \n voidaA: %p \n apuntoa_apuntoaA: %p \n", apuntoaA, apuntoadirA, voidaA, apuntoa_apuntoaA);
	return 0;
}
