/*Example:1
    3x+2y+z = 10
    2x+3y+2z = 14
    x+2y+3z = 14
    answer : x = 1,y = 2 z = 3
    or x1 = 1 ,x2 = 2 , x3 = 3
example :2
    2y+z = 10
    2x+3y+2z = 14
    x+2y+3z = 14
    answer : x =-1.142857,y = 3.714286 z = 2.571429
    or X1 = -1.142857,X2 = 3.714286,X3 = 2.571429
    */
//#include <bits/stdc++.h>
#include<stdio.h>
#include<algorithm>

using namespace std;
double matrix[100][100];
void swap_element(int row,int n);
int main()
{
    int n,z = 0;
    double x,sum = 0.0;
    double coef[10];

    printf("Enter the order of matrix: ");
    scanf("%d",&n);
    printf("Enter the elements of augmented matrix row-wise:\n\n");
    for(int i = 1 ; i <=n ; i++)
    {
        for(int j = 1 ; j <= n+1 ; j++)
        {
            printf("Matrix[%d][%d] = ",i,j);
            scanf("%lf",&matrix[i][j]);
        }
    }
    if(matrix[1][1] == 0)
    {
        for(int i = 2 ; i <= n ; i++)
        {
            if(matrix[i][1]!= 0)
            {
                swap_element(i,n);
                break;
            }
        }
    }
    for(int j = 1 ; j <= n; j++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            if(i != j)
            {
                x = matrix[i][j]/matrix[j][j];
                for(int k = 1 ; k <= n+1 ; k++)
                {
                    matrix[i][k] = matrix[i][k]-(x*matrix[j][k]);
                }
            }
        }
        printf("\n\nStep :%d : \n\n",++z);
        for(int a= 1 ; a <= n ; a++)
        {
            for(int b = 1 ; b <= n+1 ; b++)
            {
                printf("%f  ",matrix[a][b]);
            }
            printf("\n");
        }
    }
    printf("\n\nThe Solution is \n\n");
    for(int i = 1 ; i <= n ; i ++)
    {
        coef[i] = matrix[i][n+1]/matrix[i][i];
        printf("X%d = %lf\n",i,coef[i]);
    }
    return 0;
}
void swap_element(int row,int n)
{
    for(int j = 1 ; j <= n+1 ; j++)
    {
        swap(matrix[1][j],matrix[row][j]);
    }
}
