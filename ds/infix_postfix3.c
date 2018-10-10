                                                                            
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define END			0
#define PLUS			'+'
#define MINUS			'-'
#define STAR			'*'
#define DIVISION		'/'
#define POWER			'^'

#define LEFT_PARENTHESIS	'('
#define RIGHT_PARENTHESIS	')'

#define PARSE_SUCCESS		1

#define TOKENERROR		-1
#define DOUBLESYMBOLERROR	-2
#define UNBALANCED_PARENTHESIS	-3
#define EXPRERROR		-4

char a[50];
int top=-1,stack_success = 1;

int GetLastError()
{
	return stack_success;
}

int IsStackEmpty()
{
	return top<0?1:0;
}

void view()
{
	int i;
	printf("\nSt(%d) : ", top);
	for(i = 0;i<=top;i++)
		printf("%c  ", a[i]);
	printf("\n");
}

void push(char m)
{
	if(top > 49)
	{
		stack_success = 0;
		return;
	}
	stack_success = 1;
	top++;
	a[top] = m;
//	view();
}

int pop()
{
	if(top < 0)
	{
		stack_success = 0;
		return -1;
	}	
	stack_success = 1;
	top = top-1;
//	view();
	return a[top + 1];
}

int peep(int in)
{
	if(top - in < 0)
	{
		stack_success = 0;
		return 0;
	}
	stack_success = 1;
	return a[top - in];
}

char infix_expression[100];
char postfix_expression[100];

char *s, *post;
int expr_index = 0;
int postfix_index = 0;
int prev = '(';


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
                        if(ch >='a' && ch <= 'z')
                                return 8;
                        else
                                return -1;
        }
}
int r(char ch)
{
        switch(ch)
        {
                case PLUS:
                case MINUS:
                case STAR:
                case DIVISION:
		case POWER:
                        return -1;
                case LEFT_PARENTHESIS:
                        return 0;
                case RIGHT_PARENTHESIS:
                        return 0;
                default:
			//printf("got 1\n");
                        if(ch >='a' && ch <= 'z')
                                return 1;
                        else
                                return -1;
        }
}

void initialize()
{
	s = infix_expression;
	post = postfix_expression;
	expr_index = 0;
	postfix_index = 0;
	prev = '(';
	top = -1;
}

char lex()
{
	char ch;
	//Surpass white spaces including tabs.
		
	while(s[expr_index] == 32 || s[expr_index] == '\t')
		expr_index++;
		
	ch = s[expr_index];
		
	if(ch == '\0')
	{
		return END;
	}
	
	if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
	{
	 if((prev >= 'a' && prev <= 'z') || (prev >= 'A' && prev <= 'Z'))
	 {
		return DOUBLESYMBOLERROR;
	 }
	}
	else if(ch == PLUS || ch == MINUS || ch == STAR || ch == DIVISION || ch == POWER)
	{
   	 if(prev == PLUS || prev == MINUS || prev == STAR || prev == DIVISION || prev == POWER)
		return DOUBLESYMBOLERROR;
	}
	else if(ch != '(' && ch != ')')
	{
		//if not even '(' or ')'
		return TOKENERROR;
	}
	//if OK
	prev = s[expr_index];
	expr_index++;
	return ch;
}

int infixtopostfix()
{
	char NEXT,temp;
	int rank=0;
	/*Initialize stack*/
	push('(');
	
	NEXT = lex();
	
	while(NEXT != 0)
	{	
		if(NEXT == END)	//NULL char
			break;
		switch(NEXT)
		{
		case TOKENERROR:
			return TOKENERROR;	
		case DOUBLESYMBOLERROR:
			return DOUBLESYMBOLERROR;
			break;
		default:  
			// Remove symbols with greater or equal precedence from stack
			while(f(NEXT) < g(peep(0)))
			{
				temp = pop();
				post[postfix_index++] = temp;
				rank += r(temp);
				if(rank < 1)
					return EXPRERROR;
			}
			if(f(NEXT) == g(peep(0)))
				pop();
			else
				push(NEXT);
			NEXT = lex();
		}
	}
	/*Remove remaining elements from stack and add 2 suffix*/
	while(IsStackEmpty()==0)
	{
		temp = pop();
		if(temp == LEFT_PARENTHESIS)
			break;
		post[postfix_index++] = temp;
		rank += r(temp);
		if(rank < 1)
			return EXPRERROR;
	}
	if(rank == 1)
	{
		post[postfix_index] = 0;//terminate
		return PARSE_SUCCESS;
	}
	else
		return EXPRERROR;	
}

int main()
{
	char c;
	int err,i;
	while(1)
	{
		printf(">>");
		initialize();		
		for(i=0;(infix_expression[i]=getchar())!= '\n';i++);
		infix_expression[i] = 0;
		if(strcmp(infix_expression,"exit") == 0 || strcmp(infix_expression,"quit") == 0)
			break;
		if(i==0)
			continue;
		if(strcmp(infix_expression,"cls") == 0 || strcmp(infix_expression,"clear") == 0)
		{
			system("clear");
			continue;
		}
		err = infixtopostfix();
		switch(err)
		{
		case TOKENERROR:
			printf("\nInvalid symbol!\n");
			break;
		case UNBALANCED_PARENTHESIS:
			printf("\nUnbalanced parenthesis specification!");
			break;
		case DOUBLESYMBOLERROR:
			printf("\nSymbol repetition detected!\n");
			break;
		case EXPRERROR:
			printf("\nError in input expression!\n");
			break;
		case PARSE_SUCCESS:
			if(infix_expression[0] !=0)
				printf("Suffix = %s\n", postfix_expression);
		}
	}
}

