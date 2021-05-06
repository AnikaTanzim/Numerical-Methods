#include<bits/stdc++.h>
using namespace std;
float q1[1000], d[1000];
int n;
float rt[1000];
float f(float arr[], float x)
{
    float p=arr[0];
    for(int i=1; i<=n; i++)
        p=p*x+arr[i];
    return p;
}
float fd(float arr[], float x)
{
    float d=0;
    for(int i=0; i<n; i++)
        d+=(n-i)*arr[i]*pow(x,(n-i-1));
    return d;
}
int main()
{
    float x1, x0, f1, fd1, e=0.001;
    int k=0;
    cout<<"Enter order:";
    cin>>n;
    cout<<"Enter coefficients:";
    for(int i=0; i<=n; i++)
        cin>>q1[i];
    cout<<"Enter x0:";
    cin>>x0;
    do
    {
        f1=f(q1,x0);
        fd1=fd(q1,x0);
        x1=x0-(f1/fd1);
        while(fabs((x1-x0)/x1)>e)
        {
            x0=x1;
            f1=f(q1,x0);
            fd1=fd(q1,x0);
            x1=x0-(f1/fd1);
        }
        rt[k]=x1;
        k++;
        d[n]=0;
        int ct=0;
        for(int i=n-1,j=0; i>=0; j++, i--)
        {
            d[i]=q1[j]+(d[i+1]*x1);
            ct++;
        }

        for(int i=ct-1,j=0;i>=0;j++,i--)
            q1[j]=d[i];
        n--;
        x0=x1;
    }while(n>=1);
    for(int i=0; i<k; i++)
        cout<<"root"<<i+1<<":"<<rt[i]<<endl;
}
