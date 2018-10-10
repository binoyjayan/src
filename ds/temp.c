                                                                            
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
	return a[top - in];
}

char infix_expression[100];
char postfix_expression[100];

char *s, *post;
int expr_index = 0;
int postfix_index = 0;
int prev = '(';

int precedence(char oper)
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
	default:
		return 0;
	}
}

void initialize()
{
	s = infix_expression;
	post = postfix_expression;
	expr_index = 0;
	postfix_index = 0;
	prev = '(';	
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
	char t;
	while(1)
	{
	
		t = lex(); 	//get next symbol
		if(t == END)
			break;
		switch(t)
		{
		case TOKENERROR:
			return TOKENERROR;	
		case DOUBLESYMBOLERROR:
			return DOUBLESYMBOLERROR;
			break;
		case LEFT_PARENTHESIS:
			push(LEFT_PARENTHESIS);
			break;
		case RIGHT_PARENTHESIS:
			while(peep(0) != LEFT_PARENTHESIS)
			{
				if(IsStackEmpty())	//if empty
				{
					return UNBALANCED_PARENTHESIS;
				}
				post[postfix_index] = pop(0);
				postfix_index++;
			}
			if(IsStackEmpty() == 0 && peep(0) == LEFT_PARENTHESIS)
			{
				pop();		//clear stack
			}
			break;

		default:  
			// if operand
			if((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z'))
			{
				/* if operand */
				post[postfix_index] = t;
				postfix_index++;
				break;
			}
			//some operators
			if(IsStackEmpty() || precedence(t) > precedence(peep(0)))
			{
				push(t);
			}
			else
			{
			 while(IsStackEmpty() == 0 && precedence(t) <= precedence( peep(0)))
			 {
				post[postfix_index] = pop();
				postfix_index++;
			 }
			 push(t);
			}
			break;
		}
	}
	while(IsStackEmpty() == 0)
	{
		post[postfix_index] = pop();
		postfix_index++;
	}
	post[postfix_index] = 0;//terminate
	return PARSE_SUCCESS;
}

int main()
{
	char c;
	int err;
	printf("Enter infix expression:\n");
	initialize();
	gets(infix_expression);
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
		case PARSE_SUCCESS:
			printf("Suffix = %s\n\n", postfix_expression);
	}	
}

