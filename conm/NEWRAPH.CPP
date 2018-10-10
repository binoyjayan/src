#include<iostream.h>
#include<conio.h>
#include<process.h>
class newton
{
    int i,j;
    float n,coeff[10],a1,b1;
    float f(float);
    float der(float);
    float solution();
    void findlimits();
 public:
    void read();
    void print();
};
void newton::read()
{
   cout<<"ENTER THE DEGREE OF EQUATION : ";
   cin>>n;
   cout<<"\nENTER THE COEFFIECIENTS OF:\n";
   for(i=n;i>=0;i--)
   {
      cout<<"X RAISED TO "<<i<<":";
      cin>>coeff[i];
   }
}
float newton::f(float x)
{
    float ret=0,p=1;
    for(i=n;i>=0;i--)
    {
       p=coeff[i];
       for(j=i;j>0;j--)
	 p*=x;
       ret+=p;
     }
     return ret;
}
float newton::der(float x)
{
    float ret,deri[10],p;

    ///////////////FORMING DERIVED EQ.//////////////////
    for(i=n;i>0;i--)
       deri[i-1]=coeff[i]*i;
    ///////////////FINDING DERIVATIVE///////////////////
    ret=0;
    for(i=n-1;i>=0;i--)
    {
       p=deri[i];
       for(j=i;j>0;j--)
	  p*=x;
       ret+=p;
    }
    return ret;
}
void newton::findlimits()
{
	int flag,iterations;
	float f1,f2,prev,x;
	flag=x=0;
	while(flag==0)
	{
		f1=f(x);
		if(f1==0)
		{
			cout<<"\nTHE SOLUTION IS "<<x;
			getch();
			exit(0);
		}
		if(f1<0)
		{
			prev=x;x++;
			f2=f(x);
			if(f2>0)
			{
				a1=prev;b1=x;
				flag=1;
			}
		}
		if(f1>0)
		{
			prev=x;x--;
			f2=f(x);
			if(f2<0)
			{
				a1=x;b1=prev;
				flag=1;
			}
		}
		iterations++;
		if(iterations>100)
		{
			cout<<"\nCOMPLEX ROOTS";
			exit(0);
		}
	}
}
float newton::solution()
{
     findlimits();

     /////////////Now the root lies between a1 & b1/////////
     float diff,x0,x;
     x0=b1;
     diff=1;
     while(diff>0.00001)
    {
       x=x0-(f(x0)/der(x0));
       diff=x0-x;
       x0=x;
    }
    return x;
}
void newton::print()
{
    cout<<"\nTHE ROOT IS :"<<solution();
    getch();
}
void main()
{
    clrscr();
    newton a;
    a.read();
    a.print();
}