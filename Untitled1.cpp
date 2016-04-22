#include <stdio.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <locale>
#include <stdlib.h>
using namespace  std;
int main ()
{
    int n=100,i,j,k,l,z,t, index;
    double a[n][n],b[n],x[n],L[n][n],summ,summ2;
    using std::swap;
FILE *f;
FILE *p;
f=fopen("input.txt","r");
p=fopen("output.txt","w");
fscanf(f,"%d/n",&n);
   for(i=1;i<=n;i++)
    {
     for(j=1;j<=n;j++)
      {
       fscanf(f,"%lf",&a[i][j]);
      }
    }

    for(i=1;i<=n;i++)
        {
 fscanf(f,"%lf",&b[i]);
    }

//
L[1][1]=sqrt(a[1][1]);
for(j=2;j<=n;j++)
    {
    L[j][1]=a[j][1]/L[1][1];
    }
 for (i=2;i<=n;i++)
    {

        for (k=1;k<=i-1;k++)
        {
           summ=summ+L[i][k]*L[i][k];
        }
        L[i][i]=sqrt(a[i][i]-summ);
       for(j=i+1;j<=n;j++)
        {

            for (k=1;k<=j-1;k++)
            {
                summ2=summ2+L[i][k]*L[j][k];
            }
            L[j][i]=(a[j][i]-summ2)/(L[i][i]);
        }

         for(z=1;z<=n;z++)
            {
                for(t=1;t<=n;t++)
                {
                    fprintf(p,"%lf ",L[z][t]);
                }
                fprintf(p,"\n");
            }
            fprintf(p,"\n");


    }





 /*for (k=0;k<n;k++)
    {
        for(i=k+1;i<n;i++)
        {
            y=a[i][k]/a[k][k];
            b[i]-=b[k]*y;
            for(j=0;j<n;j++)
            {
                a[i][j]-=a[k][j]*y;
            }
              for(z=0;z<n;z++)
            {
                for(t=0;t<n;t++)
                {
                    fprintf(p,"%lf ",a[z][t]);
                }
                fprintf(p,"\n");
            }
            fprintf(p,"\n");

        }


    }*/

//Нахождение корней

        for( i=n-1;i>=0;i--)
        {

            x[i]=b[i]/a[i][i];
            for(j=i+1;j<n;j++)
            {
                x[i]+=-a[i][j]*x[j]/a[i][i];
            }
        }

//Вывод матрицы в файл
  /*  for(i=0;i<n;i++)
    {
     for(j=0;j<n;j++)
      {
       fprintf(p,"%lf ",a[i][j]);
      }
    fprintf(p,"\n");
    }

for(i=0;i<n;i++)
    {
    fprintf(p,"%lf ",b[i]);
    }
fprintf(p,"\n");

for(i=0;i<n;i++)
    {
    fprintf(p,"%lf ",x[i]);
    }
*/
fclose(f);
fclose(p);
}
