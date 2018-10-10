
#include<stdio.h>
#include<stdlib.h>

int a[50],top=-1,i,s = 1;

int GetLastError()
{
	return s;
}

void push(int m)
{
	if(top >= 49)
	{
		s = 0;
	}
	else
	{
		s = 1;
		top++;
		a[top]=m;
	}
}

int pop()
{
	if(top==-1)
	{
		s = 0;/*Underflow*/
		return -1;
	}	
	s = 1;
	top--;
	return a[top + 1];
}

int peep(int index)
{
	if(top-index < 0)
	{
		s = 0;
		return -1;
	}
	s = 1;
	return a[top - index];
}
void change(int index, int value)
{
	if(top-index < 0)
	{
		s = 0;
		return;
	}
	s = 1;
	a[top-index] = value;
}
int view()
{
	if(top == - 1)
	{
		printf("No elements!\n");
		return;
	}
	printf("The elements in the stack is:\n");
	for(i=top;i>=0;i--)
		printf("%d\n",a[i]);
}
main()
{
	int ch,n,t,i;
	
	while(1)
	{	
		system("clear");
		printf("\nMAIN MENU\n");
		printf("---------\n\n");
		printf("[1] Push\n");
		printf("[2] Pop\n");
		printf("[3] View\n");
		printf("[4] Peep\n");
		printf("[5] Change\n");
		printf("[6] Exit\n");
		printf("\nEnter the choice:");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
			printf("Enter the number to be push:");
			scanf("%d",&n);
			push(n);
			if(GetLastError()==0)
			{
				printf("Overflow!");
			}
			getchar();
			getchar();
			break;
		case 2:			
			t = pop();
			if(GetLastError())
				printf("The poped element is:%d",t);
			else
			{	
				printf("\nStack underflow\n");
			}
			getchar();
			getchar();
			break;
		case 3:
			view();
			getchar();
			getchar();
			break;
		case 4:
			printf("Enter the index : ");
			scanf("%d", &i);
			t = peep(i);
			if(GetLastError())
				printf("Pepped element is %d\n", t);
			else
			{
				printf("Invalid index\n");
			}
			getchar();
			getchar();
			break;
		case 5:
			printf("Enter the index :");
			scanf("%d", &i);
			printf("Enter new element:");
			scanf("%d", &n);
			change(i, n);
			if(GetLastError() == 0)
			{	
				printf("Invalid index\n");
			}
			getchar();
			getchar();
			break;
		case 6:
			exit(0);	
		default:
			printf("Wrong choice\n");
			getchar();
			getchar();
		}
	}
}

