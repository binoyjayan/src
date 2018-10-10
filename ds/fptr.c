
void display()
{
	printf("Hello World\n");
}

int sum(int a, int b)
{
	return a+b;
}
int avg(int a, int b)
{
	return (a+b)/2;
}

main()
{
	int i, n;
	void (*ptr)();
	int (*sptr)(int, int);
	int (*arr[10])();
	sptr = sum;
	ptr = display;
	(*ptr)();
	printf("sum = %d\n", (*sptr)(10, 20));
	sptr = avg;
	printf("avg = %d\n", sptr(10, 20));
	printf("Enter n:");
	scanf("%d", &n);
	for(i = 0;i<n;i++)
	{
		arr[i] = sum;
		i++;
		arr[i] = avg;
	}
	for(i=0;i<n;i++)
		printf("Avg/sum =%d\n", (*arr[i])(10, 20));
}
