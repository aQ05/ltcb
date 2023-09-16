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
}
void count(int a[], int n)
{
    int b[n];
    int x=1;
    b[0]=a[0];

    for(int i=1; i<n; i++)
    {
        int dem=0;
        for(int j=0; j<x; j++)
        {
            if(a[i]==b[j])
                dem++;
        }
        if(dem==0)
        {
            b[x]=a[i];
            x++;
        }
    }
    printf("Co %d phan tu khac nhau \n",x);
    in(b,x);
}
int main()
{
    int a[100], n;
    scanf("%d", &n);
    nhap(a,n);
    count(a,n);

}
