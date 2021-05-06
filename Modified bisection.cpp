//#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>


using namespace std;

int coef[100] = {0};
double roots[100];
int max_power;
double error = 0.001;
double delx = 0.5;
int flag = 0, co;
void All_possible_roots(double p,double q,double delx);
double fx(double x0);
double bi_section(double x1, double x2);

int main()
{
    double a,b,ans,delx;
    printf("Enter the maximum power : ");
    scanf("%d",&max_power);
    for(int i = 0 ; i <= max_power ;i++)
    {
        printf("Co-efficient of x%d = ",i);
        scanf("%d",&coef[i]);
    }
    printf("Enter the lower limit : ");
    scanf("%lf",&a);
    printf("Enter the upper limit : ");
    scanf("%lf",&b);

    All_possible_roots(a,b,delx);
    if(flag == 1)
    {
        printf("X1 and X2 do not bracket any root.\n\n");
        //a = x2;
        All_possible_roots(a,b,delx);
    }
    else
    {
        for(int i = 0 ; i < co ; i++)
        {
            printf("%lf ",roots[i]);
        }
    }
}
void All_possible_roots(double a , double b, double delx)
{
    int co = 0;
    double x1 = a;
    double x2 = a+delx;
    while(x2 < b)
    {
        if(fx(x1)*fx(x2) > 0)
        {

            flag = 1;
            return ;


        }
        else if(fx(x1)*fx(x2) < 0)
        {
            roots[co++] = bi_section(x1,x2);
        }
        x1 = x2;
        x2 = x2+delx;
    }
}
double bi_section(double x1, double x2)
{
    double x0;
    do{
    x0 = (x1+x2)/2.0;
    if(fx(x0) == 0)
        return x0;
    if(fx(x0)*fx(x1)< 0)
        x2 = x0;
    else x1 = x0;
    if(fabs((x2-x1)/x2) <= error)
        return x0;

    }while(fabs((x2-x1)/x2) > error);

}



double fx(double x0)
{
    double result = 0;
    int i;

    for(i = max_power; i >= 0 ; --i)
        result = result * x0 + coef[i];

    return result;
}

