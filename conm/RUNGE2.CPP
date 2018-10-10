#include<iostream.h>
#include<conio.h>
class runge
{
   int i;
   float x,x0,y0,h,n,dy,t1,t2;
   float gety();
 public:
   void reed();
   void print();
   friend float f(float,float);
};
void runge::reed()
{
  clrscr();
  cout<<"Given:\ndy/dx = xy";
  cout<<"\nEnter values for x0,y0,h\n";
  cin>>x0>>y0>>h;
  cout<<"Enter f(???.....): ";
  cin>>x;
}
float runge::gety()
{
  n=(x-x0)/h;
  for(i=0;i<n;i++)
  {
     t1=h*f(x0,y0);
     t2=h*f((x0+h),(y0+t1));
     dy=h*(t1+t2)/2;
     y0+=dy;
     x0+=h;
  }
  return y0;
}
void runge::print()
{
  cout<<"y("<<x<<") = "<<gety();
  getch();
}
float f(float x,float y)
{
  return (x*y);
}
void main()
{
  runge kutta;
  kutta.reed();
  kutta.print();
}