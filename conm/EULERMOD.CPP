#include<iostream.h>
#include<conio.h>
#include<math.h>
class euler
{
  float x0,y0,x1,y1,y11,y2,y3,x,h,n;
  float gety();
public:
  friend float f(float,float);
  void reed();
  void print();
};
void euler::reed()
{
  cout<<"GIVEN:\ndy/dx = x+|sqrt(y)|";
  cout<<"\nEnter values for x0,y0,h\n";
  cin>>x0>>y0>>h;
  cout<<"Enter f(???...) : ";
  cin>>x;
}
float f(float x,float y)
{
  // return (x*x+y);
  return (x+sqrt(y));
  //return (log(x+y));
}
float euler::gety()
{
   for(n=(x-x0)/h;n>0;n--)
   {
     x1=x0+h;
     y11=y0+h*f(x0,y0);
     y1=y0+h/2*(f(x0,y0)+f(x1,y11));
     y2=y0+h/2*(f(x0,y0)+f(x1,y1));
     y3=y0+h/2*(f(x0,y0)+f(x1,y2));
     y0=y3;
     x0=x1;
   }
   return y3;
}
void euler::print()
{
  cout<<"f("<<x<<") = "<<gety();
  getch();
}
void main()
{
  clrscr();
  euler method;
  method.reed();
  method.print();
}