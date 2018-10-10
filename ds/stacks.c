
#include<stdio.h>

#define STACK_SIZE 6

int s[STACK_SIZE];
int top1 = -1, top2 = STACK_SIZE;
int _StackErrorCode = 1;

int GetLastError()
{
	return _StackErrorCode;
}

void push(int n, int st, int value)
{
	_StackErrorCode = 1;
//printf("\npush:n=%d, st=%d,value=%d, top1 = %d top2 = %d\n", n, st, value, top1, top2);
	if(top1 + 1 == top2)
	{
		_StackErrorCode = 0;
		return;
	}	
	switch(st)
	{
	case 1:
		top1++;
		s[top1] = value;
		break;
	case 2:
		top2--;
		s[top2] = value;
		break;
	default:
		printf("Invalid Stack\n");
	}
	return;
}
int pop(int n, int st)
{
	int x;
	_StackErrorCode = 1;
//printf("\npush:n=%d, st=%d, top1 = %d top2 = %d\n", n, st, top1, top2);
	if(st == 1)
	{
		if(top1 == -1)
		{
			_StackErrorCode = 0;
			return -1;
		}
		x = s[top1];
		s[top1] = 0;
		top1--;
		return x;
	}
	else if(st == 2)
	{
		if(top2 >= n)
		{
			_StackErrorCode = 0;
			return -1;
		}
		x = s[top2];
		s[top2] = 0;
		top2++;
		return x;
	}
	else
	{
		printf("Invalid stack\n");
	}
}
void view(int n)
{
	int i;
	printf("Stack elements (top1 = %d top2 = %d )\n", top1, top2);
        for(i=0;i<n;i++)
		printf("%d\t", s[i]);
	printf("\n");
}
void init()
{
	memset(s, 0, STACK_SIZE * sizeof(int));
}
main()
{
	int n, ch;
	init();
	while(1)
	{
		system("clear");
		printf("\n     OPTIONS");
		printf("\n     -------\n");
		printf("[1] Push to stack no 1\n");
		printf("[2] Pop from stack no 1\n");
		printf("[3] Push to stack no 2\n");
                printf("[4] Pop from stack no 2\n");
		printf("[5] View stack 1 elements\n");
		
		printf("[0] Exit\n");
		printf("Choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
			printf("Enter no :");
			scanf("%d", &n);
			push(STACK_SIZE, 1, n);
			if(GetLastError() == 0)
				printf("\nStack overflow!\n");
			view(STACK_SIZE);
			break;
		case 2:
			n = pop(STACK_SIZE, 1);
			if(GetLastError() == 0)
				printf("\nStack underflow!\n");
			else
				printf("\nElement popped = %d\n", n);
			view(STACK_SIZE);
			break;

		case 3:
			printf("Enter no :");
			scanf("%d", &n);
			push(STACK_SIZE, 2, n);
			if(GetLastError()==0)
				printf("\nStack overflow!\n");
			view(STACK_SIZE);
			break;
		case 4:
			n = pop(STACK_SIZE, 2);
			if(GetLastError() == 0)
				printf("\nStack underflow!\n");
			else
				printf("\nElement popped = %d\n", n);
                                                                                                 
			view(STACK_SIZE);
			break;	
		case 5:
			view(STACK_SIZE);
			break;
		case 0:
			exit(0);
		default:
			printf("\nInvalid choice! try again\n");
		}
		getchar();
		getchar();
	}
}
