/*
Program to implement queue using arrays
Author : Binoy Jayan
*/

int _Q_internal_status = 1;
int GetLastError()
{
	return _Q_internal_status;
}
 
void view(int q[], int n, int f, int r)
{

	int i;
	printf("Front = %d, Rear = %d    n=%d \n", f, r,n);

	if(f == -1)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("\nQueue elements \n");
	for(i=f;;i++)
	{		
		if(i == n) i=0;
		printf("%d\t", q[i]);
		if(i == r) break;
	}
	printf("\n");

}
void qinsert(int q[], int n, int *f, int *r, int value)
{
	if(*f == 0 && *r == n-1 || *r + 1 == *f)
	{
		_Q_internal_status = 0;
		return;
	}
	if(*r == (n-1))
		*r = 0;
	else
		(*r)++;
	
	q[*r] = value;
	if(*f == -1)
		*f = 0;
	_Q_internal_status = 1;
}

int qdelete(int q[],int n,int *f,int *r)
{
	int val;
	if(*f == -1)
	{
		_Q_internal_status = 0;
		return -1;
	}
	val = q[*f];
	if(*f == *r)
	{
		*f = *r = -1;
		_Q_internal_status = 1;
		return val;
	}
	if(*f == n-1)
		*f = 0;
	else
		(*f)++;
	_Q_internal_status = 1;
	return val;
}

#define Q_SIZE 100

int main()
{
	int q[Q_SIZE], r = -1, f = -1;
	int ch, v;
	while(1)
	{
		printf("\n\n\t\tOPTIONS\n");
		printf("\n\t[1] INSERT INTO QUEUE");
		printf("\n\t[2] DELETE FROM QUEUE");
		printf("\n\t[3] VIEW ELEMENTS");
		printf("\n\t[4] Clear screen");
		printf("\n\t[5] QUIT");
		printf("\n\n\tChoice : ");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
			printf("Enter the element : ");
			scanf("%d", &v);
			qinsert(q, Q_SIZE, &f, &r, v);
			if(GetLastError())
				printf("Inserted into queue\n");
			else
				printf("Overflow\n");
			break;
		case 2:
			v = qdelete(q,Q_SIZE, &f, &r);
			if(GetLastError())
				printf("Deleted element is %d", v);
			else
				printf("Underflow !\n");
			break;
		case 3:	
			view(q, Q_SIZE, f, r);		
			break;
		case 4:
			system("clear");
			break;
		case 5:
			exit(0);
		}
	}
	return 0;
}
