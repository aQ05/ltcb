#include<stdio.h>
#include<stdbool.h>
#include <math.h>

typedef struct
{
    float x;
    float y;
} toaDo;

float khoangcach(toaDo a, toaDo b)
{
    return (sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2)));
}
void nhaptoado(toaDo a)
{
    printf("Nhap hoanh do x: ");
    scanf("%f",&a.x);
    printf("Nhap tung do y: ");
    scanf("%f",&a.y);
    printf("\n\n");

}
int main()
{
    toaDo a,b,c;
    printf("Nhap toa do diem thu nhat:\n");
    nhaptoado(a);
    printf("Nhap toa do diem thu hai:\n");
    nhaptoado(b);
    printf("Nhap toa do diem thu ba:\n");
    nhaptoado(c);
    if (((khoangcach(a,b)+khoangcach(a,c))>(khoangcach(b,c)))&&
            ((khoangcach(a,c)+khoangcach(b,c))>(khoangcach(b,a)))&&
            ((khoangcach(c,b)+khoangcach(a,b))>(khoangcach(a,c))))
    {
        printf("3 diem la ba canh tam giac");
        float chuVi = khoangcach(a,b)+khoangcach(b,c)+khoangcach(a,c);
        printf("chu vi la %f", chuVi);
        float p = chuVi/2.0;
        float s = p*(p-khoangcach(a,b)*(p-khoangcach(b,c)*(p-khoangcach(a,c))));
        printf("dien tich la: %f", s);
        

    }
    else
        printf("3 diem khong la ba canh tam giac");
}
