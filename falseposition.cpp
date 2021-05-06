//#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>

using namespace std;

double a,b,c,err = 0.001;

double func(double x)
{
    return (x*x)-(4*x)-10;
}

double falseposition(double x1,double x2)
{
    double x0;
    int i=0;

    while(1)
    {

        printf("\nIteration:%d\n",++i);

        printf("\nx1:%lf\n",x1);
        printf("\nx2:%lf\n",x2);

        x0= x1-(func(x1)*(x2-x1))/(func(x2)-func(x1));
        printf("\nx0:%lf\n",x0);

        double f1 = func(x1);
        printf("\nf1:%lf\n",f1);

        double f2 = func(x2);
        printf("\nf2:%lf\n",f2);

        double f0 = func(x0);
        printf("\nf0:%lf\n",f0);

        double error = fabs((x2-x1)/x2);
        printf("\nError:%lf\n",error);


        if(fabs(func(x0))>err)
        {
            if(func(x1)*func(x0)<0)
                x2=x0;
            else
                x1=x0;
        }
        else
            return x0;
    }
}

int main()
{
    double ans,x1,x2;

    while(1)
    {
        printf("\n\nGuess x1 and x2 : ");

        scanf("%lf %lf",&x1,&x2);
        if(func(x1)*func(x2)>0)
            printf("\nYour guesses do not bracket the root. Guess again.");
        else
            break;
    }

    ans = falseposition(x1,x2);
    printf("\n\nThe root is : %lf\n",ans);

    return 0;
}
