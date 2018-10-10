
/*
linkst.c : Program to implement stack using linked list.
*/

#include<stdio.h>

typedef struct tagNODE
{
	int data;
	struct tagNODE *ptr;
}NODE;

NODE *top = NULL;
int status = 1;

NODE * allocate()
{
	NODE *p;
	p = (NODE*) malloc(sizeof(NODE));
	return p;
}

void push(int n)
{
	NODE *t;
	t = allocate();
	status = 1;
	if(t == NULL)
	{
		printf("STACK OVERFLOW!\n");
		status = 0;
		return;
	}
	t->data = n;
	t->ptr = top;
	top = t;
}
int pop()
{
	int n;
	NODE *temp;
	status = 1;
	if(top == NULL)
	{
		printf("Stack Underflow!\n");
		status = 0;
		return -1;
	}
	temp = top;
	top = top->ptr;
	n = temp->data;
	free(temp);
	return n;
}
void view()
{
	NODE *curr;
	if(top == NULL)
	{
		printf("STACK IS EMPTY\n");
		return;
	}
	printf("\nSTACK ELEMENTS\n");
	curr = top;
	while(curr != NULL)
	{
		printf("%d\t", curr->data);
		curr = curr->ptr;
	}
	printf("\n");

}
void resetstack()
{
	NODE *t;
	
	while(top != NULL)
	{
		t = top;
		top = top->ptr;
		free(t);
	}
	
}
main()
{
	int ch, n;
	while(1)
	{
		printf("\n\nOPTIONS\n\n");
		printf("[1] PUSH\n");
		printf("[2] POP\n");
		printf("[3] VIEW\n");
		printf("[4] RESET STACK\n");
		printf("[5] EXIT\n");
		printf("Enter choice:");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
			printf("Enter the element:");
			scanf("%d", &n);
			push(n);
			view();
			break;
		case 2:
			n = pop();
			if(status)
				printf("Popped element = %d\n", n);
			view();
			break;
		case 3:
			view();
			break;
		case 4:
			resetstack();
			break;
		case 5:
			resetstack();
			exit(0);
		default:
                        printf("Invalid Choice! Try again\n");
		}
	}
}

