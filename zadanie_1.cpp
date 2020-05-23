#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<locale.h>
double func(double,double);
double func(double x,double E)
{
    double z,sum=0;
    for(int i=0;i<E;i++)
    {
        z=cos((2*i+1)*x)/pow(2*i+1,2);
        sum+=z;
        printf("№%d итерации, сумма %lf\n",i,sum);
    }
    return sum;
}
int main()
{
	setlocale(LC_ALL,"Rus");
    double  E, x,k=0;
    printf("x= ");
    scanf("%lf",&x);
    while(abs(x)>=1)
    {
        printf("не корректное значение, введите снова x=");
        scanf("%lf",&x);
    }
    printf("введите E(точность)= ");
    scanf("%lf",&E);
    k=pow(M_PI,2)/8-M_PI/4*fabs(x);
    printf("sum=%lf   k=%lf",func(x,E),k);
    return 0;
}
