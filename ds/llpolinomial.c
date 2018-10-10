#include<stdio.h>
typedef struct node
{
	int x;
	int y;
	int z;
	int ct;
	struct node* ptr;
}trm;
 
trm* last=NULL;

void disp(trm*);

trm* alloc()
{
	trm* p;
	p=(trm*) malloc(sizeof(trm));
	if(p == NULL) 
	{
	        printf("no free space\n");
	        exit(0);
	}
	return p;
}

trm* polylast(int nx,int ny,int nz,int c,trm* poly)
{
	trm* new,*j;
	new = alloc();
	new->x=nx;
	new->y=ny;
	new->z=nz;
	new->ct=c;
	printf("Here \n");
	
	if(last==NULL)
        {
		new->ptr=NULL;
		last = new;
		return new;
	}
	last->ptr=new;
	last = new;
	return poly;
}
trm* polycopy(trm* poly)
{
	trm* beg, *sv ,*new, *prd;
	if(poly == NULL)
	{
		return(NULL);
	}
	new = alloc();
	beg = new;
	
	new->x  = poly->x;
        new->y  = poly->y;
        new->z  = poly->z;
        new->ct = poly->ct;

	sv = poly;
        while(sv->ptr != NULL)
        {
		prd = new;
        	sv=sv->ptr;
        	new = alloc();
		new->x  = sv->x;
		new->y  = sv->y;
		new->z  = sv->z;
		new->ct = sv->ct;
		prd->ptr= new;
	}
	new->ptr = NULL;
	return beg;
}
trm* pinsert(int nx, int ny, int nz, int ct, trm* poly)
{
	int a, b, c;
	trm *new, *sv;
	new = alloc();
	new->x=nx;
	new->y=nz;
        new->z=ny;
	new->ct=ct;
	if(poly == NULL)
	{
		new->ptr = NULL;
		return new;
	}
	a = poly->x;
	b = poly->y;
	c = poly->z;
	                                                                               
	if(nx > a||nx == a && ny>b || nx == a && ny == b && nz>c )
	{
		new->ptr = poly;
		printf("Success\n");
		return(new);
	}  
	sv=poly;
	while(sv->ptr!=NULL)
	{
		a = (sv->ptr)->x;
		b = (sv->ptr)->y;
		c = (sv->ptr)->z;
		if(nx<a||(nx==a&&ny<b)||( nx==a && ny==b && nz<c))
			sv=sv->ptr;
		else	
			break;
	}
	new->ptr=sv->ptr;
	sv->ptr=new;
	return(poly);
}

trm* polyadd(trm* p,trm* q)
{
       int a1,a2,b1,b2,c1,c2,d1,d2;
       trm* psv,*qsv,*r;
       r=NULL;
       psv=p;
       qsv=q;
       while(p!=NULL && q!=NULL)
       {
	a1=p->x;
	a2=q->x;
	b1=p->y;
	b2=q->y;
	c1=p->z;
	c2=q->z;
	d1=p->ct;
	d2=q->ct;
	if((a1==a2)&&(b1==b2)&&(c1==c2))
	{
		if(d1+d2 != 0 )
        		r = polylast(a1, a2, b2, d1+d2, r);
		q = q->ptr;
		p = p->ptr;
	}
       else if(a1>a2 || a1==a2 && b1>b2||a1==a2 && b1==b2 && c1>c2)
       {
              r = polylast(a1, b1, c1, d1, r);
              p = p->ptr;
	}
	else
        {
              r = polylast(a2, b2, c2, d2, r);
              q = q->ptr;
        }
       }//while ends
	if(p != NULL)
      		last->ptr = polycopy(p);
	else if(q != NULL)
		last->ptr=polycopy(q);
	printf("sum of polinomials\n");
	disp(psv);
	printf("\nAND\n");
	disp(qsv);
	printf("is\n");
	return(r);
}   
void polynomial()
{
	int a,b,c,d;
	trm* poly1,*poly2,*poly3;
        poly1 = NULL;
        poly2 = NULL;
	printf("Enter Powers of X,Y,Z of each term of 1st poly. followed by COEFFS:\n");
	scanf("%d%d%d%d", &a, &b, &c, &d);
	
	while(d != 0)
	{
		poly1 = pinsert(a, b, c, d, poly1);
		scanf("%d%d%d%d", &a, &b, &c, &d);
	}
	printf("enter terms of 2nd polynomial as above\n");
	scanf("%d%d%d%d",&a,&b,&c,&d);
	while(d!=0)
	{
		poly2 = pinsert(a, b, c, d, poly2);
		scanf("%d%d%d%d", &a, &b, &c, &d);
	}
	printf("Inserted both\n");
	disp(poly1);
	disp(poly2);
	poly3=polyadd(poly1,poly2);
	disp(poly3);
}

void disp(trm* j)
{
	trm* sv;
        sv=j;
        printf("%dx%dy%dz%d",sv->ct,sv->x,sv->y,sv->z);
        sv=sv->ptr;
	while(sv!=NULL)
        {
        	printf(" +%dx%dy%dz%d ",sv->ct,sv->x,sv->y,sv->z);
                sv=sv->ptr;
	}
	printf("=0\n");
}

main()
{
	printf("here you can add two polynomials and get out put\n");
	polynomial();  
}













