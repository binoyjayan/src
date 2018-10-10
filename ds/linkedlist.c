
#include <stdio.h>

struct NODE
{
	int data;
	struct NODE *ptr;
};

struct NODE *head = NULL;

struct NODE* allocate()
{
	struct NODE *p;

	p = (struct NODE*) malloc(sizeof(struct NODE));
	if(p == NULL)
	{
		printf("\nMemory un-available !\n");
		exit(0);
	}
	return p;
}
int insert(int n, int loc)
{
	int i;
	struct NODE *curr, *t;
	if(loc < 1)
	{
		printf("Invalid location\n");
		return 0;
	}
	if(head == NULL)
	{
		head = allocate();
		head->data = n;
		head->ptr = NULL;
		return 1;
	}
	if(loc == 1)
	{
		curr = allocate();
		curr->data = n;
		curr->ptr  = head;
		head = curr;
		return 1;
	}
	//insert at middle
	i = 2;
	curr = head;
	while(i < loc && curr->ptr != NULL)
	{
		//printf("i = %d loc = %d\n", i, loc);
		curr = curr->ptr;
		i++;
	}
	t = allocate();
	t->data = n;
	t->ptr = curr->ptr;
	curr->ptr = t;
	return 1;	
}
int delete(int n)
{
	struct NODE *curr, *prev;
	if(head == NULL)
	{	
		printf("List is empty\n");
		return 0;
	}
	//initialize search
	curr = head;
	
	//find n
	while(curr->data !=n && curr->ptr != NULL)
	{
		prev = curr;
		curr = curr->ptr;
	}
	
	//end of list?
	if(curr->data != n)
	{
		printf("Number not found\n");
		return 0;
	}
	//delete n
	if(head->data == n)
	{
		free(head);
		head = head->ptr;
		return 1;
	}
	prev->ptr = curr->ptr;
	free(curr);
	return 1;	
}
int view()
{
	struct NODE *curr;
	int i;
	i = 0;
	curr = head;
	if(curr == NULL)
	{
		printf("\nLinked list is empty\n");
		return 0;
	}
	printf("\nLinked list elements\n");
	printf("\n%-20s%-20s%-20s\n" , "DATA","ADDRESS", "PTR");
	while(curr != NULL)
	{
		printf("%-20d%-20u%-20u\n", curr->data ,curr, curr->ptr);
		curr = curr->ptr;
		i++;
	}
	printf("\nTotal %d\n", i);
	return i;
}
main()
{
	int ch, n, loc;
	while(1)
	{
		printf("\nOPTIONS\n\n");
		printf("[1] INSERT\n");
		printf("[2] DELETE\n");
		printf("[3] VIEW\n");
		printf("[4] EXIT\n");
		printf("Enter choice:");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
			printf("Enter the number:");
			scanf("%d", &n);
			printf("Enter location:");
			scanf("%d", &loc);
			insert(n, loc);
			break;
		case 2:
			printf("Enter the number to delete:");
			scanf("%d", &n);
			delete(n);
			break;
		case 3:
			view();
			break;
		case 4:
			return 0;
		default:
			printf("Invalid choice!\n");
			break;
		}
	}
}
