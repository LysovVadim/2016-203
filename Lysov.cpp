#include "Lysov.h"

/**
 * Метод Гаусса
 */
void Lysov::lab1()
{
  int i,j,k;
  double y;
for (k=0;k<N;k++)
    {
        for(i=k+1;i<N;i++)
        {
            y=A[i][k]/A[k][k];
            b[i]-=b[k]*y;
            for(j=0;j<N;j++)
            {
                A[i][j]-=A[k][j]*y;
            }
        }
    }

        for(i=N-1;i>=0;i--)
        {

            x[i]=b[i]/A[i][i];
            for(j=i+1;j<N;j++)
            {
                x[i]+=-A[i][j]*x[j]/A[i][i];
            }
        }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void Lysov::lab2()
{  
int i,j,k,l;
double y;
double  m=A[0][0];
int index=0;
 for (k=0;k<N;k++)
    {
        for (l=k;l<N;l++)
        {
        if (abs(A[l][k])>m)
            {
            index=l;
            m=abs(A[l][k]);
            }
        }
        for (j=0;j<N;j++)
        {
            swap(A[k][j],A[index][j]);
        }
        swap(b[k],b[index]);
    m=0;
    }
for (k=0;k<N;k++)
    {
        for(i=k+1;i<N;i++)
        {
            y=A[i][k]/A[k][k];
            b[i]-=b[k]*y;
            for(j=0;j<N;j++)
            {
                A[i][j]-=A[k][j]*y;
            }
        }
    }

        for(i=N-1;i>=0;i--)
        {

            x[i]=b[i]/A[i][i];
            for(j=i+1;j<N;j++)
            {
                x[i]+=-A[i][j]*x[j]/A[i][i];
            }
        }
}




/**
 * Метод квадратного корня (метод Холецкого)
 */
void Lysov::lab3()
{   
  int i,j,k;
  double L[N][N],summ,summ2, y[N],s;
  for (int i=0; i<N; i++)
    for (int j=0; j<N; j++)
     {L[i][j]=0;}
//1
L[0][0]=sqrt(A[0][0]);
//2
for(j=1;j<N;j++)
    {
    L[j][0]=A[j][0]/L[0][0];
    }
//3
for (i=1;i<N;i++)
    {
      for (k=0;k<=i-1;k++)
      {
        summ=summ+L[i][k]*L[i][k];
      }
      L[i][i]=sqrt(A[i][i]-summ);
      summ=0;
//4
      if(i!=N-1)
      {
        for(j=i+1;j<=N;j++)
        {
          for (k=0;k<=j-1;k++)
          {
            summ2=summ2+L[i][k]*L[j][k];
          }
        L[j][i]=(A[j][i]-summ2)/(L[i][i]);
        summ2=0;
        }
      } 
    }
  y[0]=b[0]/L[0][0];
  for (i=1;i<N;i++)
  {  
    for (k=0;k<=i-1;k++)
      {
         s=s+L[i][k]*y[k];
      }
    y[i]=(b[i]-s)/L[i][i];
  s=0;
  }

  x[N-1]=y[N-1]/L[N-1][N-1];
  for (i=N-1;i>=0;i--)
  {
    for (k=i+1;k<N;k++)
      {
          s=s+L[k][i]*x[k];
      }
    x[i]=(y[i]-s)/L[i][i];
    s=0;
  }
}



/**
 * Метод прогонки
 */
void Lysov::lab4()
{
      int i,j;
    double c[N],z[N];
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
}



/**
 * Метод Якоби
 */
void Lysov::lab5()
{

}



/**
 * Метод Зейделя
 */
void Lysov::lab6()
{

}



/**
 * Один из градиентных методов
 */
void Lysov::lab7()
{

}
