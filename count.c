#include<stdio.h>
#include<stdbool.h>
#include <math.h>

void nhapMang(int a[],int n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}

int demSolanXuatHien(int a[], int n, int x)
{
    int dem = 0;
    for(int i=0; i<n; i++)
        if(a[i]==x)
        dem++;
    return dem;
}

int main()
{
    int n, a[1000];
    scanf("%d", &n);//nhap so luong phan tu
    nhapMang(a, n);
    int x;
    printf("Nhap phan tu can dem: ");
    scanf("%d", &x);
    printf("So %d xuat hien %d lan",x, demSolanXuatHien(a,n,x));

}
