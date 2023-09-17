#include<stdio.h>
#include<stdbool.h>
#include <math.h>


int isPrimeNumber(int n)
{
    // so nguyen n < 2 khong phai la so nguyen to
    if (n < 2)
    {
        return 0;
    }
    // check so nguyen to khi n >= 2

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
void LietKeSNT(int a[][100], int m, int n)
{
   for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
         if(isPrimeNumber(a[i][j]))
            printf("%d\t", a[i][j]);
}
void NhapMaTran(int a[][100], int m, int n)
{
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
        {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
}

void XuatMaTran(int a[][100], int m, int n)
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
        printf("\n");
    }
}

int main()
{
    int a[100][100], m, n;
    NhapMaTran(a, m,n);
    XuatMaTran(a,m,n);
    printf("nhap so hang n = ");
    scanf("%d",&n);
    printf("nhap so cot m = ");
    scanf("%d",&m);
    printf("nhap vao ma tran:\n");
    NhapMaTran(a, m, n);
    XuatMaTran(a, m, n);
    printf("cac so nguyen to trong ma tran la: ");
    LietKeSNT(a, m, n);

}
