/*
Program to insert an element at a given location in an array.
Author : Binoy Jayan
*/

#include<stdio.h>
int main()
{
	int a[50],i,j,n,num,loc;
	printf("Enter the number of elements in the array:");
	scanf("%d",&n);
	printf("\nEnter the elements:\n");
	/*Get the elements*/
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEnter the element to be inserted:");
	scanf("%d", &num);
	printf("Enter the location(\'1\' based index) to insert it:");
	scanf("%d", &loc);

	if(loc < 1)
	{
		printf("\nThe given location is less than lower bound! Going to exit...\n");
		return 1;
	}
	if(loc > n)
	{
		printf("\nThe location is above upper bound !\nDefaulting to upper bound\n");
		loc = n+1;
	}
	/*Converting '1' based index to a '0' based one*/
	loc--;

	/*Moving elements to make space for the new element*/
	for(i = n; i>loc ;i--)
		a[i] = a[i-1];

	/*Placing element*/
	a[loc] = num;
	n++;

	/*Displaying the element*/
	printf("\nArray after insertion :\n");
	for(i=0;i <n ;i++)
		printf("%d\n",a[i]);
}
