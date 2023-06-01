#include<stdio.h>

int main()
{int n;
scanf("%d",&n);
int a[n];
for(int i=n-1;i>=0;i--)
scanf("%d",&a[i]);
for(int i=0;i<n-1;i++)
printf("%d ",a[i]);
printf("%d\n",a[n-1]);

}
