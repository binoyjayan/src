                                                                            
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define END			0
#define PLUS			'+'
#define MINUS			'-'
#define STAR			'*'
#define DIVISION		'/'
#define POWER			'^'
#define HASH			'#'

#define PARSE_SUCCESS		1
#define TOKENERROR		-1
#define DOUBLESYMBOLERROR	-2
#define PARANTHESIS_UNSUPPORTED	-3
#define EXPRERROR		-4

char a[50];
int top=-1,i,stack_success = 1;

int GetLastError()
{
	return stack_success;
}

int IsStackEmpty()
{
	return top<0?1:0;
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
	return a[top + 1];
}

void view()
{
	int i;
	printf("\nSt(%d) : ", top);
	for(i = 0;i<=top;i++)
		printf("%c ", a[i]);
	printf("\n");
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

int f(char oper)
{
	switch(oper)
	{
	case PLUS:
	case MINUS:
		return 1;
	case STAR:
	case DIVISION:
		return 2;
	case POWER:
		return 3;
	case HASH:
		return 0;
	default:
		return 4;//variables
	}
}

int r(char c)
{
	switch(c)
        {
        case PLUS:
        case MINUS:
       	case STAR:
        case DIVISION:
	case POWER:
                return -1;
        case HASH:
                return 0;
        default:
                return 1;//variables
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
	if(ch == '(' || ch == ')')
	{		
		return PARANTHESIS_UNSUPPORTED;
	}
	ch = s[expr_index];

	if(ch == '\0')
	{
		return END;
	}
	if(ch >= 'a' && ch<='z' || ch >='A' && ch <='Z')
	{
	 if(prev >= 'a' && prev <= 'z' || prev >= 'A' && prev <= 'Z')
	 {
		return DOUBLESYMBOLERROR;
	 }
	}
	else if(ch == PLUS || ch == MINUS || ch == STAR || ch == DIVISION || ch == POWER)
	{
   	 if(prev == PLUS || prev == MINUS || prev == STAR || prev == DIVISION || prev == POWER)
		return DOUBLESYMBOLERROR;
	}
	else 
		return TOKENERROR;

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
	push('#');
	NEXT = lex();

	while(NEXT != '#')
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
		case PARANTHESIS_UNSUPPORTED:
			return PARANTHESIS_UNSUPPORTED;
		default:  
			// Remove symbols with greater or equal precedence from stack
			while(f(NEXT) <= f(peep(0)))
			{
				temp = pop();
				post[postfix_index++] = temp;
				rank += r(temp);
				if(rank < 1)
					return EXPRERROR;
			}
			push(NEXT);
			NEXT = lex();
		}
	}	
	/*Remove remaining elements from stack and add 2 sufffix*/
	while(peep(0) != '#')
	{
		temp = pop();
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
	printf("Enter expr; type exit to quit\n");
	while(1)
	{
		printf(">>");
		initialize();
		for(i=0;(infix_expression[i]=getchar())!= '\n';i++);	
		infix_expression[i] = 0;
		if(strcmp(infix_expression,"exit") == 0 || strcmp(infix_expression,"EXIT") == 0)
			break;
		err = infixtopostfix();
		switch(err)
		{
		case TOKENERROR:
			printf("Invalid symbol!\n");
			break;
		case PARANTHESIS_UNSUPPORTED:
			printf("Parenthesis are not supported!\n");
			break;
		case DOUBLESYMBOLERROR:
			printf("Symbol repetition detected!\n");
			break;
		case EXPRERROR:
			printf("Error in input expression!\n");
			break;
		case PARSE_SUCCESS:
			if(infix_expression[0] !=0)
				printf("Suffix = %s\n", postfix_expression);
		}
	}
}

