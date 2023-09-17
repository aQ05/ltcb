#include<stdio.h>
#include<stdbool.h>
#include <math.h>
  
int isPrimeNumber(int n) {
    // so nguyen n < 2 khong phai la so nguyen to
    if (n < 2) {
        return 0;
    }
    // check so nguyen to khi n >= 2
    int i;
    int squareRoot = (int) sqrt(n);
    for (i = 2; i <= squareRoot; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}
 
int main() {
 int n;
    printf("Nhap n = ");
    scanf("%d", &n);
    printf("Tat ca cac so nguyen to nho hon %d la: \n", n);
  
    for (int i = 0; i < n; i+=2) {
        if (isPrimeNumber(i) == 1) {
            printf("%d ", i);
        }
    }
}
