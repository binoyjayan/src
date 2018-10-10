
/*
polyadd.c:
Program to create and add polynomials using linked list.
*/

#include<stdio.h>

typedef struct tagNODE
{
	int px, py, pz, c;
	struct tagNODE *ptr;
}NODE;

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

NODE* polyfront(int nx, int ny, int nz, int coeff, NODE *poly, NODE **last)
{
	NODE *t;
	t = allocate();	
	t->px = nx;
	t->py = ny;
	t->pz = nz;
	t->c  = coeff;
	t->ptr = poly;

	if(*last == NULL)
		*last = t;
		
	return t;
}

NODE* polylast(int nx, int ny, int nz, int coeff, NODE *poly, NODE **last)
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
		*last = t;
		return t;
	}
	(*last)->ptr = t;
	*last = t;
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
}
NODE *copy(NODE *first)
{
	NODE *t, *begin, *curr, *prev;
	if(first == NULL)
		return NULL;
	t = allocate();
	
	t->px = first->px;
	t->py = first->py;
	t->pz = first->pz;
	t->c  = first->c;

	begin = t;
	curr = first;
	while(curr->ptr != NULL)
	{
		prev = t;
		curr = curr->ptr;
		t = allocate();
		t->px = curr->px;
		t->py = curr->py;
		t->pz = curr->pz;
		t->c  = curr->c;
		prev->ptr = t;
	}
	t->ptr = NULL;
	return begin;
	
}

NODE* add(NODE *p, NODE *q, NODE **rlast)
{
	NODE *r;
//	int a1, a2, b1, b2, c1, c2, d1, d2;
	r = NULL;
	while(p != NULL && q != NULL)
	{
	 if( (p->px == q->px) && (p->py == q->py) && (p->pz == q->pz))
	 {
	  if(p->c + q->c != 0)
	   r = polylast(p->px, p->py, p->pz, p->c + q->c, r, rlast);
	  p = p->ptr;
	  q = q->ptr;
	 }
	 else
	 {
	  if((p->px > q->px) || (p->px == q->px && p->py > q->py) || (p->px == q->px && p->py==q->py && p->pz > q->pz))
	  {
	  	r = polylast(p->px, p->py, p->pz, p->c, r, rlast);
		p = p->ptr;
	  }
	  else
	  {
	  	r = polylast(q->px, q->py, q->pz, q->c, r, rlast);
		q = q->ptr;
	  }
	 }
	}
	if(p != NULL)
		(*rlast)->ptr = copy(p);
	else if(q != NULL)
		(*rlast)->ptr = copy(q);
	return r;
}

main()
{
	int ch, m;
	int nx, ny, nz, coeff;
	NODE *p, *q, *r, *plast, *qlast, *rlast;
	p = q = r = plast = qlast = rlast = NULL;
	while(1)
	{
		printf("\nOPTIONS\n");
		printf("[1] INSERT AT FRONT\n");
		printf("[2] INSERT AT LAST\n");
		printf("[3] VIEW POLYNOMIAL\n");
		printf("[4] EMPTY POLYNOMIAL\n");
		printf("[5] EXIT\n");
		printf("Enter choice:");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
			printf("Enter coefficient:");
			scanf("%d", &coeff);
			printf("Power of x:");
			scanf("%d", &nx);
			printf("Power of y:");
			scanf("%d", &ny);
			printf("Power of z:");
			scanf("%d", &nz);	
			printf("Which polynomial ? (1/2):");
			scanf("%d", &m);
			if(m == 1)
			{
				p = polyfront(nx, ny, nz, coeff, p, &plast);
				view(p);
			}
			else if(m == 2)
			{
				q = polyfront(nx, ny, nz, coeff, q, &qlast);
				view(q);
			}
			else
				printf("Invalid polynomial!\n");
			break;
		case 2:
			printf("Enter coefficient:");
			scanf("%d", &coeff);
			printf("Power of x:");
			scanf("%d", &nx);
			printf("Power of y:");
			scanf("%d", &ny);
			printf("Power of z:");
			scanf("%d", &nz);
			printf("Which polynomial ? (1/2):");
			scanf("%d", &m);
			if(m == 1)
			{
				p = polylast(nx, ny, nz, coeff, p, &plast);
	                        view(p);
			}
			if(m == 2)
			{
				q = polylast(nx, ny, nz, coeff, q, &qlast);
	                        view(q);
			}
			break;
		case 3:
			printf("Which polynomial ? (1/2/3):");
			scanf("%d", &m);
			if(m == 1)
				view(p);
			else if(m == 2)
				view(q);
			else if(m == 3)
			{
				reset(r);
				r = rlast = NULL;
				r = add(p, q, &rlast);
				view(r);
			}
			else
				printf("Invalid polynomial!\n");
			break;
		case 4:
		
			printf("Which polynomial ? (1/2):");
			scanf("%d", &m);
			if(m == 1)
			{
				reset(p);
				p = plast = NULL;
			}
			else if(m == 2)
			{
				reset(q);
				q = qlast = NULL;			
			}
			else
				printf("Invalid polynomial!\n");
			break;
		case 5:
			reset(p);
			reset(q);
			reset(r);
			exit(0);
		default:
			printf("Invalid Choice! Try again\n");
		
		}
	}
}

