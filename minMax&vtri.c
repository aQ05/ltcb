#include<stdio.h>
#include<stdbool.h>
#include <math.h>

void nhap(int a[],int n)
{
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
}

void timMax(int a[], int n)
{
    int max = a[0];
    int vtMax = 0;
    for(int i=1; i<n;i++)
        if(a[i]>max)
    {
        max = a[i];
        vtMax = i+1;
    }
    printf("Max = %d o vi tri thu %d", max, vtMax);
}

void timMin(int a[], int n)
{
    int min = a[0];
    int vtMin = 0;
    for(int i=1; i<n; i++)
        if(a[i]<min)
    {
        a[i]=min;
        vtMin = i+1;
    }
    printf("Min = %d o vi tri thu %d", min, vtMin);
}
int main()
{
    int a[100], n;
    scanf("%d", &n);
    nhap(a,n);
    timMax(a,n);
    printf("\n");
    timMin(a,n);
}
