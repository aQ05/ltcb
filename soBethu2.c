#include<stdio.h>
#include<stdbool.h>
#include <math.h>

void nhap(int a[],int n)
{
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
}
void in(int a[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\n");
}
int timSoBethu2(int a[], int n)
{
    int min1, min2;
    if(a[0]<a[1])
    {
        min1 = a[0];
        min2 = a[1];
    }
    else
    {
        min2 = a[0];
        min1 = a[1];
    }
    for(int i=2; i<n; i++)
    {
        if(a[i]<min1)
        {
            min2 = min1;
            min1 = a[i];
        }
        else if(a[i]<min2)
            min2 = a[i];
    }
    return min2;

}
int main()
{
    int n, a[1000];
    scanf("%d", &n);
    nhap(a,n);
    in(a,n);
    printf("so nho thu 2 la: %d", timSoBethu2(a,n));
}
