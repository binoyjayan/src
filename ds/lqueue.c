
#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int val;
	struct stack *ptr;
};

struct stack*  head = NULL;

int s = 1;

int GetLastError()
{
	return s;
}

void push(int m)
{
	s = 1;
	struct stack* curr;
	curr = (struct stack*)malloc(sizeof(struct stack));
	if(curr == NULL)
	{
		s = 0;		//overflow : no memory
		return;
	}
	curr->val = m;		//assign value
	if(head == NULL)
	{
		head = curr;
		head->ptr = NULL;
		return;
	}
	curr->ptr = head;
	head = curr;
}

int pop()
{
	int val;
	struct stack* curr;
	s = 1;
	if(head == NULL)
        {
                s = 0;/*Underflow*/
                return -1;
        }
	curr = head;
	head = head->ptr;
	val = curr->val;
	free(curr);
	return val;
}
int peep(int index)
{
}
void change(int index, int value)
{
}
int view()
{
	int i;
	i = 0;
	struct stack* curr;

	curr = head;
	if(curr == NULL)
	{
		printf("Linked list is empty\n");
		return 0;
	}
	printf("\nLinked list elements\n");
	while(curr != NULL)
	{
		printf("%d\t", curr->val);
		curr = curr->ptr;
		i++;
	}
	printf("\nTotal %d\n", i);
	return i;

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
				printf("\nstruct stack* underflow\n");
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

