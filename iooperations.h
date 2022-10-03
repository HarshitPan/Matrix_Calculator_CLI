#include<iostream>
#include<stdio.h>
using namespace std;
void print_gap(float a)
{
    int max=5;
    int count=0;
    if(a<0)
        count++;
    while(a>10)
    {
        count++;
        a/=10;
    }
    for(int i=0;i<max-count;i++)
    {
        cout<<" ";
    }
}
void print_gap(int a)
{
    int max=5;
    float count=0;
    if(a<=0)
        count++;
    while(a!=0)
    {
        count++;
        a/=10;
    }
    for(int i=0;i<max-count;i++)
    {
        cout<<" ";
    }
}
int **input(int n,int m)
{   
    int **a=new int*[n];
    cout<<"Input Element of the matrix -:"<<endl;
    for(int i=0;i<n;i++)
    {
        a[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            cout<<"a["<<i+1<<"]["<<j+1<<"] ->";
            cin>>a[i][j];
        }
        cout<<endl;
    }
    return a;
}
void disp_cofactor(int **a,int n)
{
    cout<<"Co-Factor of the given matrix is -:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            print_gap(a[i][j]);
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void disp_inverse(float **a,int n)
{
    cout<<"Inverse of the given matrix is -:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            print_gap(a[i][j]);
            printf("%.2f ",a[i][j]);
        }
        cout<<endl;
    }
}
void disp_product(int **a,int n,int m)
{
    cout<<"Product of the given matrix is -:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            print_gap(a[i][j]);
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void disp_sum(int **a,int n,int m)
{
    cout<<"Sum of the given matrix is -:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            print_gap(a[i][j]);
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void disp_difference(int **a,int n,int m)
{
    cout<<"Difference of the given matrix is -:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            print_gap(a[i][j]);
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void disp_transpose(int **a,int n,int m)
{
    cout<<"Transpose of the given matrix is -:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            print_gap(a[i][j]);
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void disp_matrix(int **a,int n,int m)
{
    cout<<"Default Matrix is -:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            print_gap(a[i][j]);
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void disp_adj(int **a,int n)
{
    cout<<"Adjoint of the given matrix is -:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            print_gap(a[i][j]);
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int fraction(int a, int b)
{
    int temp1=a,temp2=b;
    if(temp1<0) {temp1*=(-1); a=(-1);}
    else a=1;
    if (temp2<0) {temp2*=(-1); b=(-1);}
    else b=1;
    int min=(temp1<temp2)?temp1:temp2;
    if(a!=0 && b!=0)
    {
        for(int i=min;i>1;i--)
        {
            if(temp1%i==0 && temp2%i==0)
            {
                temp1/=i;
                temp2/=i;
                break;
            }
        }
    }
    return a*temp1;
}
void disp_inverse_frac(int **a,int det,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int temp_det=det;
            if((det<0 && a[i][j]<0) || det<0)
            {
                temp_det*=(-1);
                a[i][j]*=(-1);
            }
            int x=fraction(a[i][j],temp_det);
            print_gap(x);
            cout<<x;
            int y=fraction(temp_det,a[i][j]);
            if(y!=1)
            {
                cout<<"/"<<y;
            }
            else{
                cout<<"  ";
            }
            print_gap(y);
        }
        cout<<"\n";
    }
}