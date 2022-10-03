int** sum(int** b,int **a,int *n,int *m)
{
    int max_m=(m[0]>m[1])?0:1;
    int max_n=(n[0]>n[1])?0:1;
    int **sum=new int*[n[max_n]];
    for(int i=0;i<n[max_n];i++)
    {
        sum[i]=new int[m[max_m]]; 
        for(int j=0;j<m[max_m];j++)
        {
            sum[i][j]=0;
        }
    }
    for(int i=0;i<n[0];i++)
    {
        for(int j=0;j<m[0];j++)
        {
            sum[i][j]+=a[i][j];
        }
    }
    for(int i=0;i<n[1];i++)
    {
        for(int j=0;j<m[1];j++)
        {
            sum[i][j]+=b[i][j];
        }
    }
    return sum;
}
int** difference(int **b,int **a,int *n,int *m)
{
    int max_m=(m[0]>m[1])?0:1;
    int max_n=(n[0]>n[1])?0:1;
    int **diff=new int*[n[max_n]];
    for(int i=0;i<n[max_n];i++)
    {
        diff[i]=new int[m[max_m]]; 
        for(int j=0;j<m[max_m];j++)
        {
            diff[i][j]=0;
        }
    }
    for(int i=0;i<n[0];i++)
    {
        for(int j=0;j<m[0];j++)
        {
            diff[i][j]+=a[i][j];
        }
    }
    for(int i=0;i<n[1];i++)
    {
        for(int j=0;j<m[1];j++)
        {
            diff[i][j]-=b[i][j];
        }
    }
    return diff;
}
int** multiply(int **a,int **b,int *n,int *m)
{
    int **resultant=0;
    resultant=new int*[n[0]];
    int sum,counti=0,countj=0;
    for(int i=0;i<n[0];i++)
    {
        resultant[i]=new int[m[1]];
	    for(int j=0;j<m[1];j++)
	    {
		    sum=0;
		    for(int k=0;k<m[0];k++)
		    {
			    sum+=a[i][k]*b[k][j];
		    }
		    resultant[counti][countj]=sum;
	        countj++;
	        if(countj>=m[1])
            {   
    	        countj=0;
	            counti++;
            }
	    }  
    }
    return resultant;
}
int** transpose(int **a,int n,int m)
{
    int **new_array=0;
    new_array=new int*[m];
    for(int i=0;i<m;i++)
    {
        new_array[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            new_array[i][j]=a[j][i];
        }
    }
    return new_array;
}
int** minimize_mat(int **a,int n,int i,int m)
{
    int **b=0;
    b=new int*[n-1];
    int x=0,y=0;
    for(int k=0;k<n;k++)
    {
        b[k]=new int[n-1];
        for(int j=0;j<n;j++)
        {
            if(j!=i && k!=m)
            {
                b[x][y++]=a[k][j];
                if(y>=(n-1))
                {
                    x++;
                    y=0;
                }
            }
        }
    }
    return b;
}
int determinent(int **a,int n)
{
    int det=0;
    int sign=1;
    //if(n%2==0) sign=1;
    //else sign=-1;
    if(n==1)
        return a[0][0];
    else
    {   
        for(int i=n-1;i>=0;i--)
        {    
            int **b=0;
            b=minimize_mat(a,n,i,(n-1));
            det+=a[n-1][i]*determinent(b,n-1)*sign;
            sign*=(-1);
        }
        return det;
    }
}
int **cofactor(int **a,int n)
{
    int **b=0;
    b=new int*[n];
    int sign=-1;
    for(int i=0;i<n;i++)
    {
        b[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            int **c=0;
            c=minimize_mat(a,n,j,i);
            sign=-1;
            for(int k=0;k<=i+j;k++) sign*=(-1);
            b[i][j]=determinent(c,n-1)*sign;
            for(int k=0;k<n;k++)
                delete []c[k];
            delete []c;
        }
    }
    return b;
}
int **adjoint(int **a,int n) 
{
    int **b=0;
    b=cofactor(a,n);
    b=transpose(b,n,n);
    return b;
}
float** inverse(int **a,int n,int det,char ch)
{
    int **b=0;
    b=adjoint(a,n);
    float **inv=0;
    inv=new float*[n];
    for(int i=0;i<n;i++)
    {
        inv[i]=new float[n];
        for(int j=0;j<n;j++)
        {
            inv[i][j]=float(b[i][j])/det;
        }
    }
    for(int i=0;i<n;i++)
    {
        delete []b[i];
    }
    delete []b;
    return inv;
}