#include <stdio.h>
#include <math.h>
#include<locale.h> 
#define EPS 0.0001
double MethodDelenia(double, double,int ,double ,double );
double choice(int,double,double,double);
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
double MethodDelenia(double a, double b,int n,double c,double d)
{
    int i=0;
    double q;
    while(fabs(b-a)>EPS)
    {
    q=(a+b)/2;
    i++;
    printf("№%d итерации, корень =%lf\n",i,q);
    if(choice(n,q,c,d) == 0)
    return q;
    if(choice(n,q,c,d)<0)
    {
    a=q;
    }
    else 
    {
    b=q;
    }
    }
    return q;
}
int main()
{
setlocale(LC_ALL,"Rus"); 
double a,b,c,d;
int n;
do
{
printf("введите уравнение 1-6 n= ");
scanf("%d",&n);
}
while(n<1 || n>6);
printf("Введите константы c и d\n");
scanf("%lf %lf",&c,&d);
printf("a= ");scanf("%lf",&a);
printf("b= ");scanf("%lf",&b);
if(choice(n,a,c,d)*choice(n,b,c,d)<0)
{
printf("Ответ %lf\n",MethodDelenia(a,b,n,c,d));
}
else
{
printf("функция прерывна на отрезке[a,b]");
}
return 0;
}
