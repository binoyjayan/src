/*
Program to merge two arrays to a different array.
Author : Binoy Jayan
*/
#include<stdio.h>
int main()
{
	int a[50],b[50],c[100],i,j, m, n, p;
	/*Get the elements of I array*/
	printf("Enter the number of elements in I array:");
	scanf("%d",&m);
	printf("\nEnter the elements:\n");
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	
	/*Get the elements of II array*/
	printf("Enter the number of elements in II array:");
	scanf("%d",&n);
	printf("\nEnter the elements:\n");
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);

	/*Merging*/
	for(i=0; i<m ; i++)
		c[i] = a[i];
	for(j=0; j<n ; j++,i++)/*i is already equal to m*/
		c[i] = b[j];
	p = m + n;
	
	/*Display array after merging*/
	printf("\nResultant array :\n");
	for(i=0; i<p ; i++)
		printf("%d\n",c[i]);
}
