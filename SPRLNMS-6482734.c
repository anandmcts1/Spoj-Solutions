#include<stdio.h> 
int main()
      {
int x;
int i=1;
int a;
int n;
scanf("%d",&n);
 int k[n];
for(i=0;i<n;i++)
{
scanf("%d",&x);
a=(4*x*x)-(3*x);
k[i]=a;
}
i=0;
for(i=0;i<n;i++)
{
printf("%d\n",k[i]);
}         
 
return 0;
      }
           
