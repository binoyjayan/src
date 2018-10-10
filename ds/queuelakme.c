#define SIZE 5
int q[SIZE], f=-1, r=-1;

void insert(int x)
{
	if(f==0 && r == (SIZE-1) || f == r+1)
	{
		printf("Overflow\n");
		return;
	}
	if(r == SIZE-1)
		r = 0;
	else
		r++;
	q[r] = x;
	
	if(f == -1)
		f = 0;
}
int delete()
{
	int y;
	if(f == -1)
	{	
		printf("Underflow\n");
		return 0;
	}
	y = q[f];
        q[f] = 0;
	if(f == r)
		f = r = -1;
	else
	{
		if(f == SIZE -1)
			f = 0;
		else
			f++;
	}
	return y;
}
/*
void view()
{
	int i;
	if(f == -1)
	{
		printf("Queue is empty\n");
		exit(0);
	}
	printf("The elements are (f = %d, r = %d):\n", f, r);
	i = f;
	while(1)
	{
		if(i == SIZE)
			i = 0;
		printf("%d\n", q[i]);
		if(i == r)
			break;
		i++;
	}
	printf("\n");
}
*/
void view()
   {
    int i;
    for(i=0;i<SIZE;i++)
     {
       printf(" %d ",q[i]);
      }
}

main()
{
	int ch,n;
	while(1)
	{
		printf("\nOPTIONS\n");
		printf("[1] INSERT\n");
		printf("[2] DELETE\n");
		printf("[3] VIEW\n");
		printf("[4] EXIT\n");
		printf("Choice :");
		scanf("%d", &ch);
		
		switch(ch)
		{
		case 1:
			printf("Enter element:");
			scanf("%d", &n);
			insert(n);
			view();
			break;
		case 2:
			printf("Deleted element : %d\n", delete());
			view();
			break;
		case 3:
			view();
			break;
		case 4:
			return;
		}
	}		

}
