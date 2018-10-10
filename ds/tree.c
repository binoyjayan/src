
#include<stdio.h>

typedef struct tTREE
{
	struct tTREE *lptr;
	int data;
	struct tTREE *rptr;
}TREE;

/*Declarations*/

TREE* create(int);

void preorder(TREE *);
void inorder(TREE *);
void postorder(TREE *);

void r_preorder(TREE *);
void r_inorder(TREE *);
void r_postorder(TREE *);


main()
{
	int x, n;
	TREE *head;
	printf("\nEnter no: of items:");
	scanf("%d", &n);

	//create a tree
	head = create(n);
	
	//traverse iteratively
	printf("preorder TRAVERSAL\n");
        preorder(head);
        printf("inorder TRAVERSAL\n");
        inorder(head);
        printf("postorder TRAVERSAL\n");
        postorder(head);

	//traverse tree recursively
	printf("\nRecursive preorder TRAVERSAL\n");
	r_preorder(head);
	printf("\nRecursive inorder TRAVERSAL\n");
	r_inorder(head);
	printf("\nRecursive postorder TRAVERSAL\n");
	r_postorder(head);
	printf("\n");
}
TREE * create(int n)
{
	int p;
	TREE *t, *s, *head;
	if(n >= 1)
	{
		head = s = (TREE*) malloc(sizeof(TREE));
		printf("Enter element:");
		scanf("%d", &s->data);
		n--;
		s->lptr = s->rptr = NULL;	//root node
	}
	else
		return NULL;

	while(n--)
	{
		t = (TREE*) malloc(sizeof(TREE));
		printf("Enter element:");
		scanf("%d", &t->data);
		t->lptr = t->rptr = NULL;
		printf("Insert at left(1) or right(2):");
                scanf("%d", &p);
		if(p == 1)
		{
			s->lptr = t;
			s = t;
		}
		else if(p == 2)
		{
			s->rptr = t;
			s = t;
		}
		else
			printf("Invalid option\n");		
	}
	return head;
}

void r_inorder(TREE *s)
{
	if(s == NULL)
		printf("\nTree is empty !\n");
	else
	{
		if(s->lptr != NULL)
			r_inorder((s->lptr));
		printf("%d\t", s->data);
		if(s->rptr != NULL)
			r_inorder((s->rptr));
	}
}

void r_preorder(TREE *s)
{
	if(s == NULL)
		printf("\nTree is empty !\n");
	else
	{
		printf("%d\t",s->data);
		if(s->lptr != NULL)
			r_preorder((s->lptr));
		if(s->rptr != NULL)
			r_preorder((s->rptr));
	}
}

void r_postorder(TREE *s)
{
	if(s == NULL)
		printf("\nTree is empty!\n");
	else
	{
		if(s->lptr !=NULL)
			r_postorder((s->lptr));

		if(s->rptr !=NULL)
			r_postorder((s->rptr));
		printf("%d\t",s->data);
	}
}

#define SIZE 50
TREE *stack[SIZE];
int sign[SIZE];
int top = -1;

void push(TREE *s)
{
	if(top >= SIZE-1)
	{
		printf("Overflow\n");
		return;
	}
	top++;
	stack[top] = s;
}

TREE* pop()
{
        if(top <= -1)
        {
                printf("Underflow !\n");
                return;
        }
        top--;
	return stack[top+1];
}

void preorder(TREE *s)
{
	TREE *p;
	if(s == NULL)
	{
		printf("The tree is empty\n");
		return;
	}
	push(s);
	while(top > -1)
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

void inorder(TREE *s)
{
	TREE *p;
	if(s == NULL)
	{
		printf("The tree is empty\n");
		return;
	}

	p = s;
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

void postorder(TREE *s)
{
	TREE *p;
	if(s == NULL)
        {
                printf("The tree is empty\n");
                return;
        }
	p = s;
	while(1)
	{
		while(p != NULL)
		{
			push(p);
			sign[top] = 1;
			p = p->lptr;
		}
		while(sign[top] < 0)
		{
			p = pop();
			printf("%d\t", p->data);
			if(top == -1)
				return;
		}
		p = (stack[top])->rptr;
		//stack[top] = -stack[top];
		sign[top] *= -1;
	}	
}



