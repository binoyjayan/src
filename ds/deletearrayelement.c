/*
Program to delete a given element in an array.
Author : Binoy Jayan
*/

#include<stdio.h>
int main()
{
	int a[50],i,j,n,num;
	printf("Enter the number of elements in the array:");
	scanf("%d",&n);
	printf("\nEnter the elements:\n");
	/*Get the elements*/
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEnter the element to be deleted:");
	scanf("%d", &num);

	/*Searching*/
	for(i=0; i<n ; i++)
	{
		if(a[i] == num)
			break;
	}
	/*displaying*/
	if(i == n)
	{
		printf("\nElement %d not found\n", num);
		return 1;
	}
	printf("\nThe element %d found at location %d\n", num, i+1);
	printf("Going to delete !\n");
	
	for(; i<n-1 ;i++)
		a[i] = a[i+1];
		
	printf("\nArray after deletion :\n");
	for(i=0;i <n-1 ;i++)
		printf("%d\n",a[i]);
}
