#include<iostream.h>
#include<conio.h>
class lag
{
   float x[50],y[50],x1,sum,mul;
   int i,j,n;
   float fi();
public:
   void read();
   void print();
};
void lag::read()
{
  cout<<"ENTER THE NO: OF VALUES:";
  cin>>n;
  cout<<"\nENTER THE x VALUES:\n";
  for(i=0;i<n;i++)
     cin>>x[i];
  cout<<"\nENTER THE y VALUES:\n";
  for(i=0;i<n;i++)
       cin>>y[i];
   cout<<"FIND THE VALUE OF f(???):";
   cin>>x1;
}
float lag::fi()
{
     sum=0;
     for(i=0;i<n;i++)
     {
	 mul=1;
	 for(j=0;j<n;j++)
	 {
	     if(i!=j)
	       mul*=(x1-x[j])/(x[i]-x[j]);
	 }
	 mul*=y[i];
	 sum+=mul;
      }
      return sum;
}
void lag::print()
{
  cout<<"SOLUTION : "<<fi();
  getch();
}
void main()
{
  clrscr();
  lag range;
  range.read();
  range.print();
}