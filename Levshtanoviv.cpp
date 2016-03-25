#include "Levshtanoviv.h"

/**
 * Метод Гаусса
 */
void Levshtanoviv::lab1()
{
for (int k = 0; k<N; k++)
     for (int i=k+1;i<N;i++)
     {
         float c=A[i][k]/A[k][k];
         b[i]=b[i]-(b[k]*c);
      for (int j=0;j<N;j++)
      {
           A[i][j]=A[i][j]-(A[k][j]*c);

      }
     }

     for (int k = N-1; k>=0; k--)
     for (int i=k-1;i>=0;i--)
      for (int j=N-1;j>=0;j--)
 {
         float c=A[i][k]/A[k][k];
         b[i]=b[i]-(b[k]*c);
      for (int j=0;j<N;j++)
      {
           A[i][j]=A[i][j]-(A[k][j]*c);

      }
     }
}


/**
 * Метод Гаусса с выбором главного элемента
 */
void Levshtanoviv::lab2()
for (int k = 0; k<N; k++)
     for (int i=k+1;i<N;i++)
     {
         float c=A[i][k]/A[k][k];
         b[i]=b[i]-(b[k]*c);
      for (int j=0;j<N;j++)
      {
           A[i][j]=A[i][j]-(A[k][j]*c);

      }
     }


      for(int i=N-1; i>=0; i--)

      {s=0;
          for(int j=i+1; j<=N; j++)
             s=s+A[i][j]*x[j];
         x[i]=(b[i]-s)/(A[i][i]);
      }
}



/**
 * Метод квадратного корня (метод Холецкого)
 */
void Levshtanoviv::lab3()
{

}



/**
 * Метод прогонки
 */
void Levshtanoviv::lab4()
{

}



/**
 * Метод Якоби
 */
void Levshtanoviv::lab5()
{

}



/**
 * Метод Зейделя
 */
void Levshtanoviv::lab6()
{

}



/**
 * Один из градиентных методов
 */
void Levshtanoviv::lab7()
{

}
