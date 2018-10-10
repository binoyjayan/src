#include<iostream.h>
#include<conio.h>
class runge
{
   int i;
   float x,x0,y0,h,n,dy,t1,t2,t3,t21;
   float gety();
 public:
   void reed();
   void print();
   friend float f(float,float);
};
void runge::reed()
{
  cout<<"dy/dx = 1-2xy";
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
     t2=h*f((x0+h/2),(y0+t1/2));
     t21=h*f(x0+h,y0+t1);
     t3=h*f(x0+h,y0+t21);
     dy=(t1+4*t2+t3)/6;
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
  return (1-2*x*y);
}
void main()
{
  clrscr();
  runge kutta;
  kutta.reed();
  kutta.print();
}