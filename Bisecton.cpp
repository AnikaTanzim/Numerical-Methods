//#include <bits/stdc++.h>
#include<stdio.h>
#include <math.h>

using namespace std;

double f( double x);
double E = .001;
double x0,x1, x2;

int main()
{
    double f0,f1 ,f2;
    int i=0;
    while(1)
    {
        //printf("x1 = ");
        scanf("%lf",&x1);
       // printf("x2 = ");
        scanf("%lf",&x2);
        if(f(x1) * f(x2) > 0)
        {
            printf("x1 and x2 do not bracket any root\n");

        }
        else break;
    }


        do
        {
            printf("\nIteration:%d\n",++i);

            printf("\nx1:%lf\n",x1);
            printf("\nx2:%lf\n",x2);

            x0=(x1+x2)/2;
            //x0= x1-(f(x1)*(x2-x1))/(f(x2)-f(x1));

            printf("\nx0 = %lf\n\n",x0);

             f1 = f(x1);
            printf("\nf1:%lf\n",f1);

             f2 = f(x2);
            printf("\nf2:%lf\n",f2);

            f0 = f(x0);
            printf("\nf0:%lf\n",f0);

            double error = fabs((x2-x1)/x2);
            printf("\nError:%lf\n",error);


            if(f0 == 0)
            {
                printf("\nroot = %lf\n\n",x0);
                return 0;
            }
            else
            {
                if(f(x1)*f(x0) < 0)
                {
                    x2 = x0;
                }
                else
                {
                 x1 = x0;
                }
            }
            if(fabs((x2-x1)/x2)< E)
            {
                    printf("\nx0 = %lf\n\n",x0);
            }
        }while(fabs((x2-x1)/x2)> E);


}
double f(double x)
{
    double value = (x*x)-(4*x)-10;
    return value;
}
