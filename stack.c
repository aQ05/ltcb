#include <stdio.h>
#include <bits.h>
#define true 1
#define false 0
#define MAX 100

int top=-1; //mang rong
int aStack[MAX];
int isEmpty() //ham ktra mang rong khong
{
    return top == -1;
}
int isFull() //ham kiem tra mang day khong
{
    return top==MAX-1;
}
int peek()//lay phan tu
{
    if(!isEmpty())
        return aStack[top];
    return -1;
}
int pop()//xoa phan tu
{
    if(!isEmpty())
    {
        top--;
        return aStack[top+1];
    }
    return -1;
}
void push (int value)//them phan tu
{
    if(!isFull())
    {
        top++;
        aStack[top] =value;
    }
}
void destroy()
{
    top = -1;
}

void chuyenCoso(int n, int coSo)
{
    destroy();
    while (n !=0)
    {
        push(n%coSo);
        n/=coSo;
    }
    while(!isEmpty())
    {
        int tmp = pop();
        if(tmp <10)
            printf("%d",tmp);
        else
        {
            tmp -=10;
            tmp +='A';
            printf("%c", tmp);
        }
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int tmp, coSo;
        printf("\tNhap so : ");
        scanf("%d",&tmp );
         printf("\tNhap co so can chuyen: ");
         scanf("\t%d", &coSo);
         chuyenCoso(tmp, coSo);
         printf("\n");
    }
}
