/* 
Program to design a doubly linked list (DLL)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tNODE
{
        struct tNODE  *left;
        int data ;
        struct tNODE  *right;
}NODE;

void insertlast(NODE **, int);
void insertfirst(NODE **, int);
void insertafter(NODE *, int, int);
void view(NODE *);
int  getcount(NODE *);
void deleteitem(NODE **, int );

main()
{
        NODE *p = NULL ;  /* Create an empty DLL*/
	int ch, n, loc;
	
	while(1)
	{
		system("clear");
		printf("\nOPTIONS\n\n");
		printf("[1] INSERT AT THE END\n");
		printf("[2] INSERT AT FIRST\n");
		printf("[3] DISPLAY LIST\n");
		printf("[4] GET NUMBER OF ELEMENTS\n");
		printf("[5] INSERT AFTER\n");
		printf("[6] DELETE AN ITEM\n");
		printf("[7] EXIT\n");
		printf("\nChoice:");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
			printf("Enter no:");
			scanf("%d", &n);
        		insertlast( &p, n);
			view(p);
			break;
		case 2:
			printf("Enter no:");
			scanf("%d", &n);
			insertfirst(&p, n);
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
			printf("Enter location:");
			scanf("%d", &loc);
			insertafter(p, loc, n);
			view(p);
			break;	
		case 6:
			printf("Enter no:");
			scanf("%d", &n);
	        	deleteitem(&p, n);
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
void insertlast( NODE **s, int num )
{
	NODE *r, *q = *s ;
        /* if the linked list is empty */
        if ( *s == NULL )
        {
                /*create a new node */
                *s = (NODE*)malloc ( sizeof ( NODE ) ) ;
                (*s)-> left = NULL ;
                (*s)-> data = num ;
                (*s)-> right = NULL ;
        }
        else
        {
                /* traverse the linked list till the last node is reached */
                while(q->right != NULL)
                      q = q->right ;

                /* add a new node at the end */
                r = (NODE*) malloc(sizeof(NODE)) ;
                r-> data = num;
                r-> right = NULL;
                r->left = q;
                q->right = r;
        }
}

/* adds a new node at the begining of the linked list */
void insertfirst(NODE **s, int num)
{
        NODE *q ;

        /* create a new node */
        q = (NODE*) malloc(sizeof(NODE)) ;

        /* assign data and pointer to the new node */
        q->left = NULL;
        q->data = num;
        q->right = *s;

        /* make new node the head node */
        if(*s != NULL)
		(*s)->left = q;
        *s = q ;
}

/* adds a new node after the specified number of nodes in loc*/
void insertafter(NODE *q, int loc, int num)
{
	NODE *temp;
	int i;
	/* skip to desired portion */
	for(i=0;i<loc;i++)
	{
		q = q->right;
		/* if end of linked list is encountered */
		if(q == NULL)
		{
			printf ( "\nThere are less than %d elements", loc );
			return;
		}
	}
	/* insert new node */
	q = q->left;
	temp = (NODE*) malloc(sizeof(NODE));
	temp->data = num;
	temp->left = q ;
	temp->right = q -> right ;
	temp->right -> left = temp;
	q->right = temp;
}

/* displays the contents of the linked list */
void view ( NODE *q )
{
	if(q == NULL)
	{
		printf("\nDLL is empty\n");
		return;
	}
	printf("\nDLL ELEMENTS\n");

	/* traverse the entire linked list */
	while(q != NULL)
	{
		printf("%d\t", q->data);
		q = q->right;
	}
	printf("\n\n");
}
/* counts the number of nodes present in the linked list */
int getcount(NODE * q)
{
        int count = 0 ;
        /* traverse the entire linked list */
        while(q != NULL)
        {
                q = q->right ;
                count++ ;
        }
        return count;
}

/* deletes the specified node from the doubly linked list */
void deleteitem(NODE **s, int num)
{
	NODE *q = *s ;
	/* traverse the entire linked list */
        while(q != NULL)
	{
		/* if node to be deleted is found */
        	if(q->data == num)
		{
		/* if node to be deleted is the first node */
			if (q == *s)
			{
				*s = (*s) -> right;
				if(*s != NULL)
					(*s)->left = NULL;
				free(q);
			}
			else
			{
				/* if node to be deleted is the last node */
				if(q->right == NULL)
					q->left->right = NULL;
				else
				/* if node to be deleted is any intermediate node */
				{
					q->left->right = q->right;
					q->right->left = q->left;
				}
				free(q);
			}
			return;/* return back after deletion */
		}
		q = q -> right ; /* go to right node */
	}
        printf ( "\n%d not found in the DLL.\n", num);
}

