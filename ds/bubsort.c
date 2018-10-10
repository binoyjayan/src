/*
Program to sort array using bubble sort
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

	/*Sorting using bubble sort technique*/
	for(i=0; i<n-1 ; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	/*displaying*/
	printf("\nSorted array is :\n");
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
}
