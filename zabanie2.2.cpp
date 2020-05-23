#include <stdio.h>
#include <math.h>
#include<locale.h>
#define EPS 0.0001
double MethodSecant(double,double,int,double,double);
double choice(int,double,double,double);
double MethodSecant(double a,double b,int n,double c,double d)
{
    double xN;
    int i=0;
    do{
      i++;
      xN=b-((b-a)/(choice(n,b,c,d)-choice(n,a,c,d)))*choice(n,b,c,d);
      a=b;
      b=xN;
      printf ("є %d итерации корень=%lf\n",i,xN);
   }while (fabs(a-b)>=EPS);
   printf ("ќтвет:%lf был найден",xN);
   return 0;
}
double choice(int n,double x,double c,double d)
{
    double fx;
    switch(n)
    {
        case 1:
        fx=pow(x, 3) + c * pow(x, 2) + d;
        break;
        case 2:
        fx=sin(c * x) - d;
        break;
        case 3:
        fx=pow(x, 4) + c * pow(x, 3) - d * x;
        break;
        case 4:
        fx=cos(c * x) - d;
        break;
        case 5:
        fx=tan(c * x) - d;
        break;
        case 6:
        fx=pow(x, 6) + c * x + d;
        break;
    }
    return fx;
    
}
int main()
{
	setlocale(LC_ALL,"Rus"); 
   double a,b,c,d;
   int n=0;
   do
    {
        printf("введите уравнение 1-6 n= ");
        scanf("%d",&n);
    }
    while(n<1 || n>6);
    printf("¬ведите константы c и d\n");
    scanf("%lf %lf",&c,&d);
    printf ("¬ведите промежуток a b\n");
    scanf("%lf %lf",&a,&b);
    MethodSecant(a,d,n,c,d);
   return 0;
 }
