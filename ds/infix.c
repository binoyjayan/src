#include<stdio.h>
#include<stdlib.h>

int top=-1;
int f(char),g(char),r(char);
void push(char);
char pop();
char infix[50], pol[50], s[50];
void view();

main()
{
	int ra=0,i=0,j=0;
	char temp;
//	printf("Input\tStack\n");
	system("clear");
	push('(');
	printf("Enter the infix expression:");
//	gets(infix);
	for(i=0;(infix[i] = getchar())!='\n';i++);
	infix[i] = 0;
	i = 0;
	while(infix[i] != 0)
	{
		if(top<0)
		{
			printf("Invalid! stack error\n");
			return 1;
		}
		while(f(infix[i]) < g(s[top]))
		{
			temp = pop();
			pol[j++]=temp;
			ra = ra + r(temp);
			if(ra < 1)
			{
				printf("Invalid rank\n");
				exit(0);
			}
		}
		if(f(infix[i])!=g(s[top]))
			push(infix[i]);
		else
			pop();
		i++;
	}
	while(top >= 0 )
	{
		temp = pop();
		if(temp=='(')
			break;
		pol[j++] = temp;
		ra += r(temp);
		if(ra<1)
		{
			printf("\nInvalid expr\n");
			return 2;
		}
		
	}
	if(ra == 1)
		printf("\nSuccess\n");
	else
		printf("Error in input expression\n");
	pol[i] = 0 ;
	printf("\nThe postfix expression is:");
	puts(pol); 
}
 
int f(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
			return 1;
		case '*':
                case '/':
                        return 3;
		case '^':
			return 6;
                case '(':
                        return 9;
		case ')':
			return 0;
		default:
			if(ch>='a' && ch<='z')
				return 7;
			else
				return -1;
	}
}
int g(char ch)
{
        switch(ch)
        {
                case '+':
                case '-':
                        return 2;
                case '*':
                case '/':
                        return 4;
                case '^':
                        return 5;
                case '(':
                        return 0;
                case ')':
                        return 0;
                default:
                        if(ch>='a' && ch<='z')
                                return 8;
                        else
                                return -1;
        }
}
int r(char ch)
{
        switch(ch)
        {
                case '+':
                case '-':
                case '*':
                case '/':
		case '^':
                        return -1;
                case '(':
                        return 0;
                case ')':
                        return 0;
                default:
			//printf("got 1\n");
                        if(ch >='a' && ch <= 'z')
                                return 1;
                        else
                                return -1;
        }
}

void push(char m)
{
	top++;
	s[top] = m;
//	view();
}

char pop()
{
	top=top-1;
//	view();
	return s[top+1];
}
/*void view()
{
	int i;
	for(i=0;i<=top;i++)
	{
		printf("\t");
		putchar(s[i]);
		printf("\n");
	}
}
*/
