#include <stdio.h>
#include <fstream>
#include <iostream>
int main ()
{
    int N=100,i,j;
    double A[N][N],b[N],x[N], c[N],z[N];
FILE *f;
FILE *p;
f=fopen("input.txt","r");
p=fopen("output.txt","w");
fscanf(f,"%d/n",&N);
   for(i=0;i<N;i++)
    {
     for(j=0;j<N;j++)
      {
       fscanf(f,"%lf",&A[i][j]);
      }
    }

    for(i=0;i<N;i++)
        {
 fscanf(f,"%lf",&b[i]);
    }

c[1]=-A[0][1]/A[0][0];
z[1]=b[0]/A[0][0];
 for (i=1;i<N-1;i++)
    {
    	c[i+1]=-A[i][i+1]/(A[i][i-1]*c[i]+A[i][i]);
    	z[i+1]=(b[i]-A[i][i-1]*z[i])/(A[i][i-1]*c[i]+A[i][i]);
    }
	x[N-1]=(b[N-1]-A[N-1][N-2]*z[N-1])/(A[N-1][N-1]+A[N-1][N-2]*c[N-1]);
		for(i=N-2;i>=0;i--)
        {
        	x[i]=c[i+1]*x[i+1]+z[i+1];
        }

    for(i=0;i<N;i++)
    {
     for(j=0;j<N;j++)
      {
       fprintf(p,"%lf ",A[i][j]);
      }
    fprintf(p,"\n");
    }

for(i=0;i<N;i++)
    {
    fprintf(p,"%lf ",b[i]);
    }
fprintf(p,"\n");

for(i=0;i<N;i++)
    {
    fprintf(p,"%lf ",x[i]);
    }

fclose(f);
fclose(p);
}

