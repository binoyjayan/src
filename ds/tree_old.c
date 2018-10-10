
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

void preorder(TREE *s)
{
	printf("Hai\n");
}

void inorder(TREE *s)
{
	printf("Not implemented\n");
}

void postorder(TREE *s)
{
	printf("Not implemented\n");
}



