#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
const double Threshold=1E-6;
double number[4] = { 0,0,0,0 };
int PointsGame(int n)
{
    if(n==1)
    {
        if(fabs(number[0]-24)<Threshold)
            return 1;
        else
            return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            double a,b;

            a=number[i];
            b=number[j];
            number[j]=number[n-1];


            number[i]=a+b;
            if(PointsGame(n-1))
              return 1;


            number[i]=a-b;
            if(PointsGame(n-1))
              return 1;


            number[i]=b-a;
            if(PointsGame(n-1))
              return 1;

            number[i]=a*b;
            if(PointsGame(n-1))
              return 1;

            if(b!=0)
            {

             number[i]=a/b;
             if(PointsGame(n-1))
               return 1;
            }
            if(a!=0)
            {
              number[i]=b/a;
              if(PointsGame(n-1))
               return 1;
            }

            number[i]=a;
            number[j]=b;
        }
    }
    return 0;
}

int main()
{
   while (scanf("%lf %lf %lf %lf",&number[0] ,& number[1] ,& number[2] ,& number[3]) !=EOF)
    {
       if (PointsGame(4)==1)
           printf("true\n");
       else
           printf("false\n");
   }
    return 0;
}