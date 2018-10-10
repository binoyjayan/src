#include<stdio.h>

int gcd(int m,int n)
{

        if(n == 0) return m;
        else if(n>m) return gcd(n,m);
        else return gcd(n, m%n);
}

main()
{
	int a,b;
	printf("Enter two numbers:");
	scanf("%d%d", &a, &b);
	printf("Gcd of the number is:%d\n",gcd(a,b));
}

