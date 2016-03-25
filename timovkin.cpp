#include "timovkin.h"

/**
 * ����� ������
 */
void timovkin::lab1()
{
for (int i = 0; i<N; i++)
 for (int k=i+1;k<N;k++)
 {
   c=A[k][i]/A[i][i];
   b[k]=b[k]-b[i]*c;
   for (int j=0;j<N;j++)
     A[k][j]=A[k][j]-A[i][j]*c;
 }

 for (int i = N-1; i>=0; i--)
 for (int k=i-1;k>=0;k--)
 {
     c=A[k][i]/A[i][i];
   b[k]=b[k]-b[i]*c;
   for (int j=N-1;j>=0;j--)
     A[k][j]=A[k][j]-A[i][j]*c;

}
    for (int j=0; j<N; j++)
    {    x[j]=b[j]/A[j][j];}
}


/**
 * ����� ������ � ������� �������� ��������
 */
void timovkin::lab2()
{
  for (int i = 0; i<N; i++)
 for (int k=i+1;k<N;k++)
 {
   c=A[k][i]/A[i][i];
   b[k]=b[k]-b[i]*c;
   for (int j=0;j<N;j++)
     A[k][j]=A[k][j]-A[i][j]*c;
 }
 for(int i=N;i>=0;i--)
     {
      s=0;
      for(int j=i+1;j<N;j++)
        s=s+A[i][j]*x[j];
      x[i]=(b[i]-s)/A[i][i];
    }

}



/**
 * ����� ����������� ����� (����� ���������)
 */
void ivanovii::lab3()
{

}



/**
 * ����� ��������
 */
void ivanovii::lab4()
{

}



/**
 * ����� �����
 */
void ivanovii::lab5()
{

}



/**
 * ����� �������
 */
void ivanovii::lab6()
{

}



/**
 * ���� �� ����������� �������
 */
void ivanovii::lab7()
{

}
