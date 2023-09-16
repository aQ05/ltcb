#include<stdio.h>
#include <stdbool.h>
typedef struct
{
    char maSV[10];
    char hoTen[20];
    int namSinh;
} sinhVien;

sinhVien nhapThongTin()
{
    sinhVien sv;
    printf("\tMa SV: ");
    fflush(stdin);
    gets(&sv.maSV);
    printf("\tHo ten: ");
    fflush(stdin);
    gets(&sv.hoTen);

    printf("\tNam sinh: ");
    scanf("%d", &sv.namSinh);

    return sv;
}
void nhapDanhSachSinhVien(sinhVien sv[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\t\tNhap thong tin sinh vien thu %d\n", i+1);
        sv[i] = nhapThongTin();
    }
}
void luuDanhSachSinhVien(sinhVien sv[], int n, char *filePath)
{
    FILE *f = fopen(filePath, "w");
    for(int i = 0; i<n;i++)
    {
        fprintf(f, "\t%s, %s, %d\n", sv[i].maSV, sv[i].hoTen, sv[i].namSinh);
    }
    fclose(f);
}
void docDuLieuTuFile(sinhVien sv[], char *filePath)
{
    FILE *f = fopen(filePath, "r");
    char tmp[100];
    while(fgets(tmp, 100,f))
    {
        puts(tmp);
        char *maSV = strtok(tmp, ",");
        printf("\tMa SV: %s\n", maSV);
        char *hoTen = strtok( NULL, ",");
        printf("\tHo ten: %s\n", hoTen );
        char *namSinh = strtok( NULL, ",");
        printf("\tNam Sinh: %s\n", namSinh );
    }
    fclose(f);
}
int main()
{
    int n;
    sinhVien sv[1000];
    printf("\tNhap sp luong sinh vien: ");
    scanf("%d", &n);
    nhapDanhSachSinhVien(sv, n);
    luuDanhSachSinhVien(sv, n, "DS_SV.txt");
    docDuLieuTuFile(sv, "DS_SV.txt");
}
