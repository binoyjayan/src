/*
Program to search an element in an array.
Author : Binoy Jayan
*/

#include<stdio.h>
int main()
{
	int a[50],i,j,n,num;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("\nEnter the elements:\n");
	/*Get the elements*/
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEnter the element to be searched:");
	scanf("%d", &num);

	/*Searching*/
	for(i=0; i<n ; i++)
	{
		if(a[i] == num)
			break;
	}
	/*displaying*/
	if(i == n)
		printf("\nElement %d not found\n", num);
	else
		printf("\nThe element %d found at location %d\n", num, i+1);
}
