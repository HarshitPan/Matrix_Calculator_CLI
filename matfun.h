#include<iostream>
#include "matrix.h"
#include "iooperations.h"
using namespace std;
int n[2],m[2];
int** creation(int pos)
{
    int **a;
    cout<<"Creation of a new matrix-:"<<endl;
    cout<<"Enter no of rows ->";
    cin>>n[pos];
    cout<<"Enter no of column ->";
    cin>>m[pos];
    a=input(n[pos],m[pos]);
    return a;
}
int** start()
{
    cout<<"Welcomce to the world of matrices..."<<endl;
    cout<<"Creating a default matrix for you...\n";
    int **a=creation(0);
    cout<<"Default Matrix Created...\n";
    cout<<"Press Enter to continue...";
    getchar();
    getchar();
    system("clear");
    return a;
}
template <class D> void delete_arr(D **a,int n)
{
    for(int i=0;i<n;i++)
    {
        delete []a[i];
    }
    delete []a;
}
void mainmenu()
{
    cout<<"*************Main-Menu**************"<<endl;
    cout<<"1.Reset Default Matrix."<<endl;
    cout<<"2.Sum"<<endl;
    cout<<"3.Difference"<<endl;
    cout<<"4.Multiply"<<endl;
    cout<<"5.Transpose"<<endl;
    cout<<"6.Co-Factor"<<endl;
    cout<<"7.Determinent"<<endl;
    cout<<"8.Adjoint."<<endl;
    cout<<"9.Inverse"<<endl;
    cout<<"10.Display Default Matrix"<<endl;
    cout<<"0.Exit"<<endl;
}
void goto_sum(int **a)
{
    int **b;
    b=creation(1);
    int **c=sum(b,a,n,m);
    delete_arr(b,n[1]);
    disp_sum(c,n[(n[0]>n[1])?0:1],m[(m[0]>m[1])?0:1]);
    delete_arr(c,(n[0]>n[1])?0:1);
}
void goto_difference(int **a)
{
    int **b;
    b=creation(1);
    int **c=difference(b,a,n,m);
    delete_arr(b,n[1]);
    disp_sum(c,n[(n[0]>n[1])?0:1],m[(m[0]>m[1])?0:1]);
    delete_arr(c,(n[0]>n[1])?0:1);
}
void goto_multiply(int **a)
{
    int **b,**c=0;
    b=creation(1);   
    if(m[0]!=n[1])
    {
        cout<<"Matrix can't be multiplied.";
    }
    else{
        c=multiply(a,b,n,m);
        disp_product(c,n[0],m[1]);
        delete_arr(c,n[0]);
    }
    delete_arr(b,n[1]);
    
}
void goto_transpose(int **a)
{
    int **c=transpose(a,n[0],m[0]);
    disp_transpose(c,m[0],n[0]);
    delete_arr(c,n[0]);
}
void goto_cofactor(int **a)
{
    if(n[0]!=m[0])
    {
        cout<<"Not a square matrix. Can't find Co-Factor...\nChange the default matrix with an square matrix..\n"<<endl;
        return;
    }
    else
    {
        int **b=cofactor(a,n[0]);
        disp_cofactor(b,n[0]);
        delete_arr(b,n[0]);
    }

}
void goto_det(int** a)
{
    int det=0;
    if(n[0]!=m[0])
    {
        cout<<"Not a square matrix. Can't find determinent...\nChange the default matrix with an square matrix..\n"<<endl;
        return;
    }
    else
    {
        det=determinent(a,n[0]);   
        cout<<"Determinent of the given matrix is -> "<<det<<endl;
    }

}
void goto_adj(int **a)
{
    if(n[0]!=m[0])
    {
        cout<<"Not a square matrix. Can't find adjoint...\nChange the default matrix with an square matrix..\n"<<endl;
        return;
    }
    else 
    {
        int **b=0;
        b=adjoint(a,n[0]);
        disp_adj(b,n[0]);
        delete_arr(b,n[0]);
    }
}
void goto_inverse(int **a)
{
    if(n[0]!=m[0])
    {
        cout<<"Not a square matrix. Can't find Inverse...\nChange the default matrix with an square matrix..\n"<<endl;
        return;
    }
    else 
    {
        int det=determinent(a,n[0]);
        if(det==0)
        {
            cout<<"Since Determinent of the given matrix is zero...Inverse can't occur.\n";
            return;
        }
        char ch='n';
        cout<<"Do you want to see the inverse in Fraction(Y/N) -:";
        getchar();
        ch=getchar();
        if(ch!='Y' && ch!='y')
        {
            float **b=0;
            b=inverse(a,n[0],det,ch);
            disp_inverse(b,n[0]);
            delete_arr(b,n[0]);
        }
        else
        {
            int **b=0;
            b=adjoint(a,n[0]);
            disp_inverse_frac(b,det,n[0]);
            delete_arr(b,n[0]);
        }
        
    }
}
void goto_dispmatrix(int **a)
{
    disp_matrix(a,n[0],m[0]);
}
int** reset(int **a)
{   
    delete_arr(a,n[0]);
    int **second=0;
    second=creation(0);
    cout<<"Default matrix updated."<<endl;
    return second;
}
void goto_choice(int **a,int *n, int *m)
{
    while(1)
    {
        mainmenu();
        cout<<"Enter your choice -: ";
        int choice=0;
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
            case 0:
                return;
            case 1:
                a=reset(a);
                break;
            case 2:
                goto_sum(a);
                break;
            case 3:
                goto_difference(a);
                break;
            case 4:
                goto_multiply(a);
                break;
            case 5:
                goto_transpose(a);
                break;
            case 6:
                goto_cofactor(a);
                break;
            case 7:
                goto_det(a);
                break;
            case 8:     
                goto_adj(a);
                break;
            case 9:
                goto_inverse(a);
                break;
            case 10:
                goto_dispmatrix(a);
                break;
            default:
                cout<<"Invalid Choice...Enter choice again.\n";
                
        }
        char choice_2='n';
        if(choice!=1 && (choice>=0 && choice<10))
        {
            cout<<"Want to see the current default matrix? (Y/N)->";
            getchar();
            choice_2=getchar();
            if(choice_2=='Y' || choice_2=='y')  goto_dispmatrix(a);
            
        }
        cout<<"Press Enter to continue...";
        getchar();
        getchar();
        system("clear");
    }
}