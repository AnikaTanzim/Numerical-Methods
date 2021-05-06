//#include <bits/stdc++.h>
#include<stdio.h>
#include<iostream>
#include<math.h>

#define SIZE 100

using namespace std;

int main()
{
    freopen("polynomial input.txt", "r", stdin);
    int j, n;
    cin >> j >> n;

    int x, y;
    double arrX[SIZE][SIZE]= {{0}}, arrY[SIZE]= {0};

    for(int i=0; i<n; i++)
    {
        cin >> x >> y;
        for(int a=0; a<=j; a++)
        {
            for(int b=0; b<=a; b++)
            {
                if(a<j)
                {
                    arrX[b][a-b]+=pow(x, a);
                }
                arrX[j-b][j-(a-b)]+=pow(x, 2*j-a);
            }
            arrY[a]+=y*pow(x, a);
        }
    }

    double temp;
    for(int a=0; a<=j; a++)
    {
        temp=arrX[a][a];
        for(int b=0; b<=j; b++)
        {
            arrX[a][b]/=temp;
        }
        arrY[a]/=temp;

        for(int b=0; b<=j; b++)
        {
            if(a!=b)
            {
                temp=arrX[b][a];
                for(int c=0; c<=j; c++)
                {
                    arrX[b][c]-=(temp*arrX[a][c]);
                }
                arrY[b]-=(temp*arrY[a]);
            }
        }
    }

    for(int a=0; a<=j; a++){
        cout << "a" << a+1 << " = " << arrY[a] << endl;
    }
    return 0;
}
