
/* 
Program to design a circular doubly linked list (C-DLL)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tNODE
{
        struct tNODE  *left;
        int data ;
        struct tNODE  *right;
}NODE;

void insertlast(NODE *, int);
void insertfirst(NODE *, int);
void insertafter(NODE *, int, int);
void view(NODE *);
int  getcount(NODE *);
void deleteitem(NODE *, int );

main()
{
        NODE *p = NULL;
	int ch, n, loc;

	/* Create an empty C-DLL*/
	p = (NODE *) malloc(sizeof(NODE));
	p->left  = p;
	p->data  = 0;
	p->right = p;

	while(1)
	{
		system("clear");
		printf("\nOPTIONS\n\n");
		printf("[1] INSERT AT THE END\n");
		printf("[2] INSERT AT FIRST\n");
		printf("[3] DISPLAY LIST\n");
		printf("[4] GET COUNT\n");
		printf("[5] INSERT AFTER LOC\n");
		printf("[6] DELETE AN ITEM\n");
		printf("[7] EXIT\n");
		printf("\nChoice:");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
			printf("Enter no:");
			scanf("%d", &n);
        		insertlast(p, n);
			view(p);
			break;
		case 2:
			printf("Enter no:");
			scanf("%d", &n);
			insertfirst(p, n);
			view(p);
			break;
		case 3:
			view(p);
			break;
		case 4:
        		printf("\nNo. of elements = %d\n", getcount(p));
			break;
        	case 5:
			printf("Enter no:");
                        scanf("%d", &n);
			printf("Insert after :");
			scanf("%d", &loc);
			insertafter(p, loc, n);
			view(p);
			break;	
		case 6:
			if(p->right == p)
			{
				view(p);
				break;
			}
			printf("Enter no:");
			scanf("%d", &n);
	        	deleteitem(p, n);
			view(p);
			break;
		case 7:
			return 0;
		}
		getchar();
		getchar();
	}
}

/* adds a new node at the end of the doubly linked list */
void insertlast(NODE *s, int num)
{
	NODE *r, *q = s;
        
	/* traverse the linked list till the last node is reached*/
	while(q->right != s)
		q = q->right;

	/* add a new node at the end */
	r = (NODE*) malloc(sizeof(NODE));
	r->data = num;
	r->right = s;
	r->left = q;
	q->right = r;
	s->left = r;
}

/* adds a new node at the begining of the linked list */
void insertfirst(NODE *s, int num)
{
        NODE *q ;

        /* create a new node */
        q = (NODE*) malloc(sizeof(NODE)) ;

        /* assign data and pointer to the new node */
        q->left = s;
        q->data = num;
        q->right = s->right;

	/*make the old first node's left ptr point to the first node*/
	q->right->left = q;
        /* make new node the first node*/
	s->right = q;
}

/* adds a new node after the specified number of nodes in loc*/
void insertafter(NODE *s, int loc, int num)
{
	NODE *r, *q;
	int i;
	q = s->right;
	/* skip to desired node */
	for(i = 1 ; i<loc; i++)
	{
		q = q->right;
		/* if end of linked list is encountered */
		if(q == s)
		{
			printf("\nThere are less than %d elements", loc);
			return;
		}
	}
	if(q == s)
	{
		return;
	}
	r = (NODE*) malloc(sizeof(NODE));
	r->left = q;
        r->data = num;
        r->right = q->right;

        q->right = r;
        r->right->left = r;
}

/* displays the contents of the linked list */
void view(NODE *s)
{
	NODE *q;
	
	if(s->right == s)
	{
		printf("\nThe CIRCULAR DLL is empty\n");
		return;
	}
	printf("\nCIRCULAR DLL ELEMENTS\n");
	
	q = s;
	printf("%u : (%u : %d) : %u\n",  q->left, q, q->data, q->right);

	q = s->right;
	/* traverse the entire linked list */
	while(q != s)
	{
		printf("%u : (%u : %d) : %u\n",  q->left, q, q->data, q->right);
//		printf("%d\t", q->data);
		q = q->right;
	}
	printf("\n\n");
}
/* counts the number of nodes present in the linked list */
int getcount(NODE *s)
{
	NODE *q;
        int count = 0 ;
        /* traverse the entire linked list */
	q = s->right;
        while(q != s)
        {
                q = q->right ;
                count++ ;
        }
        return count;
}

/* deletes the specified node from the doubly linked list */
void deleteitem(NODE *s, int num)
{
	NODE *q = s->right;

	/* traverse the entire linked list */
        while(q != s)
	{
		/* if node to be deleted is found */
        	if(q->data == num)
			break;
		q = q->right;
	}
	if(q->data == num && q != s)
	{
		q->left->right = q->right;
		q->right->left = q->left;
		free(q);
		printf("Deleted %d\n", num);
	}
	else
	        printf ( "\n%d not found in the C-DLL.\n", num);
}

