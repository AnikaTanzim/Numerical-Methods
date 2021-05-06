//#include <bits/stdc++.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    freopen("straightLine input.txt", "r", stdin);

    int n;
    cin >> n;
    double x, y, sumXSqre=0, sumXMulY=0, sumX=0, sumY=0, a, b;
    for(int i=0; i<n; i++){

        cin >> x >> y;

        sumXMulY+=(x*y);
        sumX+=x;
        sumY+=y;
        sumXSqre+=(x*x);
    }

    b=((n*sumXMulY)-(sumX*sumY))/((n*sumXSqre)-(sumX*sumX));

    a=(sumY/n)-b*(sumX/n);

    cout <<"The co-efficients are: "<< endl;
    cout << "A: " << a <<endl;
    cout << "B: " << b <<endl;
    //cout << a << " " << b;
    return 0;
}
