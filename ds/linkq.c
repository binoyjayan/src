
/*
linkq.c : Program to implement queue using linked list.
*/

#include<stdio.h>

typedef struct tagNODE
{
	int data;
	struct tagNODE *ptr;
}NODE;

NODE *f = NULL, *r = NULL;
int status = 1;

NODE * allocate()
{
	NODE *p;
	p = (NODE*) malloc(sizeof(NODE));
	return p;
}

void insert(int n)
{
	NODE *t;
	t = allocate();
	status = 1;
	if(t == NULL)
	{
		printf("QUEUE OVERFLOW!\n");
		status = 0;
		return;
	}
	t->data = n;
	t->ptr = NULL;
	if(r == NULL)
	{
		f = r = t;
		return;
	}
	r->ptr = t;
	r = t;
}
int delete()
{
	int n;
	NODE *temp;
	status = 1;
	if(f == NULL)
	{
		printf("Queue Underflow!\n");
		status = 0;
		return -1;
	}
	if(f == r)
	{
		n = f->data;
		free(f);
		f = r = NULL;
		return n;
	}
	temp = f;
	f = f->ptr;
	n = temp->data;
	free(temp);
	return n;
}
void view()
{
	NODE *curr;
	if(f == NULL)
	{
		printf("QUEUE IS EMPTY\n");
		return;
	}
	printf("\nQUEUE ELEMENTS\n");
	curr = f;
	while(curr != NULL)
	{
		printf("%d\t", curr->data);
		curr = curr->ptr;
	}
	printf("\n");

}
void resetqueue()
{
	NODE *t;
	
	while(f != NULL)
	{
		t = f;
		f = f->ptr;
		free(t);
	}
	r = NULL;	
}
main()
{
	int ch, n;
	while(1)
	{
		printf("\nOPTIONS\n");
		printf("[1] INSERT\n");
		printf("[2] DELETE\n");
		printf("[3] VIEW\n");
		printf("[4] RESET QUEUE\n");
		printf("[5] EXIT\n");
		printf("Enter choice:");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
			printf("Enter the element:");
			scanf("%d", &n);
			insert(n);
			view();
			break;
		case 2:
			n = delete();
			if(status)
				printf("Deleted element = %d\n", n);
			view();
			break;
		case 3:
			view();
			break;
		case 4:
			resetqueue();
			break;
		case 5:
			resetqueue();
			exit(0);
		default:
			printf("Invalid Choice! Try again\n");
		
		}
	}
}

