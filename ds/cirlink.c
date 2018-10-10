
/*
cirlink.c : Programming circular linked list.
*/

#include<stdio.h>

typedef struct tagNODE
{
	int data;
	struct tagNODE *ptr;
}NODE;

NODE *head = NULL;

NODE * allocate()
{
	NODE *p;
	p = (NODE*) malloc(sizeof(NODE));
	return p;
}

void insertfirst(int n)
{
	NODE *t;
	t = allocate();
	if(t == NULL)
	{
		printf("PANIC : Memory unavailable !\n");
		return;
	}
	t->data = n;
	t->ptr = head->ptr;
	head->ptr = t;
}
void delete(int n)
{
	NODE *temp, *prev;
	if(head->ptr == head)
	{
		printf("LIST IS EMPTY !\n");
		return ;
	}
	prev = head;
	temp = head->ptr;
	while(temp->ptr != head && temp->data != n)
	{
		prev = temp;
		temp = temp->ptr;
	}
	if(temp->data != n)
	{
		printf("%d NOT FOUND IN THE LIST\n");
		return;
	}
	prev->ptr = temp->ptr;
	free(temp);
	printf("Deleted %d Successfully\n", n);
}
void view()
{
	NODE *curr;
	if(head->ptr == head)
	{
		printf("STACK IS EMPTY\n");
		return;
	}
	printf("\nSTACK ELEMENTS\n");
	curr = head->ptr;
	while(curr != head)
	{
		printf("%d\t", curr->data);
		curr = curr->ptr;
	}
	printf("\n");

}
void resetlist()
{
	NODE *t, *curr;
	curr = head->ptr;
	head->ptr = head;

	while(curr != head)
	{
		t = curr;
		curr = curr->ptr;
		free(t);
	}	
}
main()
{
	int ch, n;

	/*Create a HEAD (unused) node first.*/
	head = (NODE*)malloc(sizeof(NODE));
	head->ptr = head;
	while(1)
	{
		printf("\n\nOPTIONS\n\n");
		printf("[1] INSERT AT FIRST\n");
		printf("[2] DELETE\n");
		printf("[3] VIEW ELEMENTS\n");
		printf("[4] EMPTY THE LIST\n");
		printf("[5] EXIT\n");
		printf("\nEnter choice:");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
			printf("Enter the element:");
			scanf("%d", &n);
			insertfirst(n);
			view();
			break;
		case 2:
			printf("Enter the element:");
                        scanf("%d", &n);
			delete(n);
			view();
			break;
		case 3:
			view();
			break;
		case 4:
			resetlist();
			break;
		case 5:
			/*Remove and deallocate elements in LL exept HEAD node*/
			resetlist();

			/*Deallocate the node created first.*/
			free(head);
			exit(0);
		default:
                        printf("Invalid Choice! Try again\n");
		}
	}
}

