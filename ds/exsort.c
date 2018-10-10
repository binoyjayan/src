/*
Program to sort array using exchange sort
Author : Binoy Jayan
*/

#include<stdio.h>
int main()
{
	int a[50],i,j,n,temp;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("\nEnter the elements:\n");
	/*Get the elements*/
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	/*Sorting*/
	for(i=0; i<n-1 ; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	/*displaying*/
	printf("\nSorted array is :\n");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
}
