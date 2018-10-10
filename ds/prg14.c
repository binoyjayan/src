#include<stdio.h>
#define size 10

int q[size],f1=-1,f2=size,r1=-1,r2=size,ch;

void qins(int x)
{
	if(r2 == r1 + 1)
	{
		printf("Overflow\n");
		return;
	}

	printf("\n\tEnter the choice of queue (1 / 2):");
	scanf("%d",&ch);
	if(ch==1)
	{
		r1++;
		q[r1]=x;

		if(f1 == -1)
		 	f1=0;
	}
	if(ch==2)
	{
		r2--;
		q[r2]=x;
		if(f2==size)
			f2=size-1;		
	}
}

int qdel()
{
	int y;
	printf("\n\tEnter the choice of queue (1 / 2):");
	scanf("%d", &ch);
	if(ch==1)
	{
		if(f1 == -1)
		{
			printf("\n\tQueue Underflow!");
			return(0);
		}
		else
		{		
			y = q[f1];
			q[f1] = 0;
			if(f1 == r1)
				f1 = r1 = -1;
			else
				f1++;
		}
		return(y);			
	}		
	if(ch==2)
	{	
		if(f2==size)
		{
			printf("\n\tQueue underflow!");
			return(0);
		}
		else
		{
			y=q[f2];
			q[f2] = 0;
			if(f2 == r2)			
				f2 = r2 = size;
			else
				f2--;
		}
		return(y);
	}

}
void qdisp()
{
	int i,j;

	printf("\n\tThe queue is:\n");
	
	for(i=0;i<size;i++)
		printf("%d ",q[i]);
	printf("\n");
}
main()
{

	int cho,elt1,elt2;

	do

		{

		printf("\n\t________________________________________");
		printf("\n\t1.	INSERTION\n\t2.	DELETION\n\t3.	EXIT");
		printf("\n\t________________________________________");
		printf("\n\n\tEnter the choice");
		scanf("%d", &cho);

		switch(cho)

			{

			case 1:
		
			printf("\n\tEnter the element to be inserted");
			scanf("%d",&elt1);
			qins(elt1);
			qdisp();
		
			break;

			case 2:
			
			elt2=qdel();
			printf("\n\tThe deleted element is:");
			printf("\n\t%d",elt2);
			qdisp();

			break;

			case 3:

			exit(0);

			break;

			default:
			printf("\n\tInvalid choice");

			}

	}

	while(1);

}
