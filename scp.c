#include<stdio.h>
#include<stdbool.h>
#include <math.h>

int scp(int n)
{
    int sqr = sqrt(n);
    return (sqr *sqr == n);
}
int main()
{
    int a,b;
    printf("nhap [a, b]: ");
    scanf("%d %d", &a, &b);
    if(a>0 && b>0)
    {
        int i;
        for(i=a; i<=b; i++)
            if(scp(i))
            printf("%d   ",i);
    }
    else
        printf("nhap lai  a, b");
}
