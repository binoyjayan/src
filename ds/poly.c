
/*
poly.c:
Program to create polynomial using linked list.
*/

#include<stdio.h>

typedef struct tagNODE
{
	int px, py, pz, c;
	struct tagNODE *ptr;
}NODE;

NODE *LAST = NULL;

NODE * allocate()
{
	NODE *p;
	p = (NODE*) malloc(sizeof(NODE));
	if(p == NULL)
	{
		printf("PANIC : Memory unavailable\n");
		exit(1);
	}
	return p;
}

NODE* polyfront(int nx, int ny, int nz, int coeff, NODE *poly)
{
	NODE *t;
	t = allocate();	
	t->px = nx;
	t->py = ny;
	t->pz = nz;
	t->c  = coeff;
	t->ptr = poly;

	if(LAST == NULL)
		LAST = t;
		
	return t;
}

NODE* polylast(int nx, int ny, int nz, int coeff, NODE *poly)
{
        NODE *t;
	t = allocate();
	t->px = nx;
	t->py = ny;
	t->pz = nz;
	t->c  = coeff;
	t->ptr = NULL;
	
	if(poly == NULL)
	{
		LAST = t;
		return t;
	}
	LAST->ptr = t;
	LAST = t;
	return poly;
}

void view(NODE *poly)
{
	NODE *curr;
	if(poly == NULL)
	{
		printf("POLYNOMIAL IS NULL\n");
		return;
	}
	printf("\nPOLYNOMIAL\n");
	curr = poly;
	while(curr != NULL)
	{
		printf("%+dx^%dy^%dz^%d  ", curr->c, curr->px, curr->py, curr->pz);
		curr = curr->ptr;
	}
	printf("\n");

}
void reset(NODE *poly)
{
	NODE *t;
	
	while(poly != NULL)
	{
		t = poly;
		poly = poly->ptr;
		free(t);
	}
	LAST = NULL;
	
}
main()
{
	int ch, n;
	NODE *poly = NULL;
	while(1)
	{
		printf("\nOPTIONS\n");
		printf("[1] POLYFRONT\n");
		printf("[2] POLYLAST\n");
		printf("[3] VIEW\n");
		printf("[4] RESET QUEUE\n");
		printf("[5] EXIT\n");
		printf("Enter choice:");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
			printf("Enter c :");
			scanf("%d", &n);
			poly = polyfront(n, n, n, n, poly);
			view(poly);
			break;
		case 2:
			printf("Enter c :");
			scanf("%d", &n);
			poly = polylast(n, n, n, n, poly);
                        view(poly);
                        break;
		case 3:
			view(poly);
			break;
		case 4:
			reset(poly);
			poly = NULL;
			break;
		case 5:
			reset(poly);
			exit(0);
		default:
			printf("Invalid Choice! Try again\n");
		
		}
	}
}

