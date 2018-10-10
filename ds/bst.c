
#include<stdio.h>

typedef struct tTREE
{
	struct tTREE *lptr;
	int data;
	struct tTREE *rptr;
}TREE;

/*Declarations*/
void insert(TREE**,int);
void preorder(TREE*);
void inorder(TREE*);
void postorder(TREE*);

main()
{
	int x, i, n;
	TREE *t = NULL;
	printf("\nEnter no: of items:");
	scanf("%d", &n);

	//create bs-tree
	for(i=0;i<n;i++)
	{
		printf("Enter element : ");
		scanf("%d", &x);
		insert(&t, x);
	}

	//traverse in three ways
	printf("Inorder Traversal - Sorted order\n");
        inorder(t);
	printf("Preorder Traversal\n");
	preorder(t);
	printf("Postorder traversal\n");
	postorder(t);
}
void insert(TREE **s,int ele)
{
	TREE *n,*temp;
	if(*s == NULL)
	{
		*s = (TREE*) malloc(sizeof(TREE));
		(*s)->data=ele;
		(*s)->lptr=(*s)->rptr = NULL;
		return;
	}
	if(((*s)->data) > ele)
		insert(&((*s)->lptr), ele);
	else if(((*s)->data) < ele)
		insert(&((*s)->rptr), ele);
	else
		printf("\nERROR : duplication\n");
}
void inorder(TREE *s)
{
	if(s == NULL)
		printf("\nTree is empty\n");
	else
	{
		if(s->lptr !=NULL)
			inorder((s->lptr));
		printf("%d\n",s->data);
		if(s->rptr !=NULL)
			inorder((s->rptr));
	}
}
void preorder(TREE *s)
{
	if(s == NULL)
		printf("\nTree is empty\n");
	else
	{
		printf("%d\n",s->data);
		if(s->lptr !=NULL)
			preorder((s->lptr));
		if(s->rptr !=NULL)
			preorder((s->rptr));
	}
}
void postorder(TREE *s)
{
	if(s == NULL)
		printf("\nTree is empty\n");
	else
	{
		if(s->lptr !=NULL)
			postorder((s->lptr));
		if(s->rptr !=NULL)
			postorder((s->rptr));
		printf("%d\n",s->data);
	}
}

