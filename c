// so hoan hao
#include<stdio.h>
#include<stdbool.h>
#include <math.h>

bool soHoanhao(int n)
{
    if(n<2)
        return false;
    int sum = 1;
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
            sum += i+ (n/i);
    }
    if(sum == n)
        return true;
    return false;
}
void nhapMang(int a[],int n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
void inMang(int a[], int n)
{
    for(int i= 0; i<n; i++)
        printf("%d ", a[i]);
}
int main()
{
    int n, a[1000];
    scanf("%d", &n);
    nhapMang(a,n);

    printf("Mang ban dau la: ");
    inMang(a,n);

    printf("\n");

    printf("so hoan hao la: ");
    for(int i=0; i<n; i++)
        if(soHoanhao(a[i]))
            printf("%d ", a[i]);

}
