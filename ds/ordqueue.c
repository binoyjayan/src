
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int q[SIZE];
int f=-1, r=-1;
int flag;

void view()
{
	int i;
	printf("\nQueue elements(f = %d, r= %d)\n", f, r);
	for(i=0;i<SIZE;i++)
		printf("%d\t", q[i]);
	printf("\n");
}
void qinsert(int x, int w)
{
	if(w == 1)
	{
		if(f == -1)
		{
			f = r = 0;
			q[f] = x;
			return;
		}
		else if(f == 0)
		{
			printf("No space at front!\n");
			return;
		}
		f--;
		q[f] = x;	
	}
	else if(w == 2)
	{
		if(r >= SIZE-1)
                {
                        printf("Overflow!\n");
                        return;
                }
		r++;
                q[r] = x;
		if(f == -1)
			f = 0;
	}
	else
		printf("Invalid Input\n");
}
int qdelete()
{
	//deleting at front is easy!
	int y;
	flag = 0;
	if(f == -1)
        {
		flag = 1;
		printf("Underflow!\n");
        	return 0;
	}
	y = q[f];
	q[f] = 0;
	if(f == r)
		f = r = -1;
	else
		f++;
	return y;
}
main()
{
	int n, ch, w;
	while(1)
	{		
		system("clear");
		printf("\n    OPTIONS\n");
		printf("-----------------\n");
		printf("|  [1] INSERT   |\n");
		printf("|  [2] DELETE   |\n");
		printf("|  [3] VIEW     |\n");
		printf("|  [4] EXIT     |\n");
		printf("-----------------\n");
		printf("\nEnter choice:");
		scanf("%d", &ch);
		
		switch(ch)
		{
		case 1:
			printf("Enter element :");
			scanf("%d", &n);
			printf("At Front(1)/Rear(2) :");
	        	scanf("%d", &w);
			qinsert(n, w);
			view();
			break;
		case 2:
			qdelete();
			view();
			break;
		case 3:
			view();
			break;
		case 4:
			exit(0);
		}
		printf("\nPress enter to continue...");
		getchar();
		getchar();
	}
}
