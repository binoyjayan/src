#include<iostream.h>
#include<conio.h>
class newint
{
   float y[50],y0[50],temp[50],x[50],xp,u,u1,sum;
   int i,j,n,h,fact;
   void process();
   float solution();
public:
   void read();
   void print();
};
void newint::read()
{
  cout<<"ENTER THE NO: OF VALUES:";
  cin>>n;
  cout<<"\nENTER INITIAL VALUE OF x:";
	cin>>x[0];
  cout<<"\nENTER THE VALUE OF h:";
	cin>>h;
  for(i=1;i<n;i++)
       x[i]=x[i-1]+h;
  cout<<"\nENTER THE "<<n<<" y VALUES:\n";
  for(i=0;i<n;i++)
       cin>>y[i];
  cout<<"FIND VALUE OF f(???....):";
  cin>>xp;
}
void newint::process()
{
     for(i=n;i>1;i--)
     {
	  y0[n-i]=y[0];
	  for(j=0;j<i;j++)
	    temp[j]=y[j+1]-y[j];
	  for(j=0;j<i-1;j++)
	       y[j]=temp[j];
     }
     y0[n-1]=y[0];
}
float newint::solution()
{
  process();
  sum=y0[0];
  fact=1;
  u1=1;
  u=(xp-x[0])/h;
  for(i=1;i<n;i++)
  {
	fact*=i;
	u1*=u;
	sum+=u1*y0[i]/fact;
	u--;
  }
  return sum;
}
void newint::print()
{
	cout<<"\n SOLUTION : "<<solution();
	getch();
}
void main()
{
  clrscr();
  newint n;
  n.read();
  n.print();
}