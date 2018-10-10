

//Stack Implementation using templates and class

#include<iostream>
#include<stdio.h>

using namespace std;

#define STACK_SUCCESS			0
#define STACK_OVERFLOW			1
#define STACK_UNDERFLOW			2


template <class T>
class Stack
{
private:
	T *a, top, s;
	int stacksize;
public:
	Stack()
	{
		a = new T[100];
		top = -1;
		s = STACK_SUCCESS;
		stacksize = 100;
	}
	Stack(const int nItems)
	{
		a = new T[nItems];
		stacksize = nItems;
		top = -1;
		s = STACK_SUCCESS;
	}
	~Stack()
	{
		//delete a;
	}
	int IsStackFull()
	{
		return top >= stacksize-1?1:0;
	}
	int IsStackEmpty()
	{
		return top==-1?1:0;
	}
	int GetLastError()
	{
		return s;
	}
	void push(const T m)
	{
		if(top >= stacksize-1)
		{
			s = STACK_OVERFLOW;
		}
		else
		{
			s = STACK_SUCCESS;
			top++;
			a[top] = m;
		}
	}
	T pop()
	{
		if(top == -1)
		{
			s = STACK_UNDERFLOW;	/* Underflow */
			return 0;
		}		
		top--;
		s = STACK_SUCCESS;
		return a[top + 1];
	}

	T peep(int index)
	{
		if(top-index < 0)
		{
			s = STACK_UNDERFLOW;
			return 0;
		}
		s= STACK_SUCCESS;
		return a[top - index];
	}
	void change(T index, T value)
	{
		if(top-index < 0)
		{
			s = STACK_UNDERFLOW;
			return;
		}
		s = STACK_SUCCESS;
		a[top-index] = value;
	}
};

int main()
{
	int ch,n,t,i;
	Stack<int> st;

	while(1)
	{
		cout<<"\nMAIN MENU\n";
		cout<<"---------\n\n";
		cout<<"[0] Exit\n";
		cout<<"[1] Push\n";
		cout<<"[2] Pop\n";		
		cout<<"[3] Peep\n";
		cout<<"[4] Change\n";		
		cout<<"\nEnter the choice:";
		cin>>ch;

		switch(ch)
		{
		case 0:
			return 0;
		case 1:
			cout<<"Enter the number to be push:";
			cin>>n;
			st.push(n);
			if(st.GetLastError() == STACK_OVERFLOW)
			{
				cout<<"STACK Overflow.....!\n";
			}
			getchar();
			break;
		case 2:
			t = st.pop();
			if(st.GetLastError() == STACK_UNDERFLOW)
				printf("The poped element is:%d",t);
			else
			{
				cout<<"\nStack underflow\n";
			}			
			getchar();
			break;
		case 3:
			printf("Enter the index : ");
			cin>>i;
			t = st.peep(i);
			if(st.GetLastError())
				cout<<"Pepped element is "<<t;
			else
			{
				cout<<"Invalid index\n";
			}
			break;
		case 4:
			cout<<"Enter the index :";
			cin>>i;
			cout<<"Enter new element:";
			cin>>n;
			st.change(i, n);
			if(st.GetLastError() == 0)
			{
				cout<<"Invalid index\n";
			}
			getchar();
			break;
		default:
			cout<<"Wrong choice\n";
			getchar();
		}
	}
	return 0;
}

