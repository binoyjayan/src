
#include<stdio.h>

typedef struct tagNODE
{
	struct tagNODE *lptr;
	int data;
	struct tagNODE *rptr;
}NODE;

#define SIZE 50
NODE *stack[SIZE];
int top = -1;

void push(NODE *p)
{
	if(top >= SIZE-1)
	{
		printf("Stack overflow!\n");
		exit(0);
	}
	top++;
	stack[top] = p;
}

NODE *pop()
{
	if(top < 0)
	{
		printf("Stack underflow!\n");
		exit(0);
	}	
	top--;
	return stack[top+1];
}

//Preorder traversal

void preorder(NODE *t)
{
	NODE *p = t;
	top = -1;
	push(p);
	while(top >= 0)
	{
		p = pop();
		while(p != NULL)
		{
			printf("%d\t", p->data);
			if(p->rptr != NULL)
				push(p->rptr);
			p = p->lptr;
		}
	}
	printf("\n");
}

//inorder traversal
void inorder(NODE *t)
{
	NODE *p = t;
	top = -1;
	
	while(top >= 0 || p != NULL)
	{
		if(p != NULL)
		{
			push(p);
			p = p->lptr;
		}
		else
		{
			p = pop();
			printf("%d\t", p->data);
			p = p->rptr;
		}
	}
	printf("\n");
}

void rinsert(NODE **t, int n)
{
	if(*t == NULL)
	{
		*t = (NODE*) malloc(sizeof(NODE));
		(*t)->data = n;
		(*t)->lptr = (*t)->rptr = NULL;
		return;
	}
	if(n < (*t)->data)
		rinsert(&(*t)->lptr, n);
	else if(n > (*t)->data)
		rinsert(&(*t)->rptr, n);
	else
		printf("Repetition detected!\n");
}

void insert(NODE **head, int n)
{
	NODE *t, *x, *prev;
	
	//initialize
	x = (NODE*) malloc(sizeof(NODE));
	if(x == 0)
	{
		printf("Memory unavailable !\n");
		exit(0);
	}
	x->data = n;
	x->lptr = x->rptr = NULL;
	
	//check 4 root
	if(*head == NULL)
	{
		*head = x;
		return;
	}
	
	//start traverse
	prev = t = *head;
	
	while(t != NULL )
	{
		prev = t;
		if(n < t->data)
			t = t->lptr;
		else if(n > t->data)
			t = t->rptr;
		else
		{
			printf("Repetition detected!\n");
			return;
		}
	}
	if(n < prev->data)
		prev->lptr  = x;
	else
		prev->rptr = x;
}

main()
{
	NODE *t = NULL;
	int n, i, ch;
	while(1)
	{
	system("clear");
	printf("\nOPTIONS\n\n");
	printf("[1] INSERT\n");
	printf("[2] INSERT RECURSIVELY\n");
	printf("[3] PREORDER\n");
	printf("[4] INORDER\n");
	printf("[5] EXIT\n");
	printf("\nEnter choice:");
	scanf("%d", &ch);
	switch(ch)
	{
	case 1:	
		printf("Enter value:");
		scanf("%d", &n);
		insert(&t, n);
		break;
	case 2:
		printf("Enter value:");
		scanf("%d", &n);
		rinsert(&t, n);
		break;
	case 3:
		preorder(t);
		break;
	case 4:
		inorder(t);
		break;
	case 5:
		exit(0);
	default:
		printf("Wrong choice\n");
	}
	getchar();
	getchar();
	}
}




