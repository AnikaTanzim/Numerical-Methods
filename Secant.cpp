
#include<stdio.h>
#include<math.h>

using namespace std;

double err = 0.001;
int max_power = 0;
int co_eff[10] = {};

double f(double x0)
{
    double result = 0;
    int i;

    for(i = max_power; i >= 0 ; --i)
        result = result * x0 + co_eff[i];

    return result;
}


int main()
{
    int i,k = 0;
    double x1,x2,x3,f1,f2,error;

    printf("\nEnter the maximum power of function: \n");
    scanf("%d",&max_power);

    for(i = 0; i <= max_power; i++)
    {
        printf("\nCo-efficient of %d th term of x:\n",i);
        scanf("%d",&co_eff[i]);
    }

    printf("Guess the value of x1 and x2: ");
    scanf("%lf",&x1);
    scanf("%lf",&x2);
    printf("Iteration:\t x0:\t\t x1:\t\t f0:\t\t f1:\t\t Error:\n");
    do
    {
        k++;
        printf("%d\t\t",k);
        printf("%lf\t",x1);

        f1=f(x1);
        f2=f(x2);

        x3 = x2-((f(x2)*(x2-x1))/(f(x2)- f(x1)));

        printf("%lf\t",x3);
        printf("%lf\t",f1);
        printf("%lf\t",f2);

        if(fabs((x3-x2)/x3)<= err)
            break;
        else
        {
            x1 = x2;
            x2 = x3;
        }
        error = fabs((x3-x2)/x3);
        printf("%lf\t\n",error);

    }while(1);

    printf("\nTHE ROOT OF EQUATION IS = %lf",x3);


    return 0;

}
