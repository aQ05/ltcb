#include<stdio.h>
#include <stdbool.h>

typedef struct
{
    char tenHang[20];
    int donGia;
    int soluong;
    int thanhTien;

} matHang;

matHang nhapthongtin()
{
    matHang mh;
    printf("\tTen hang: ");
    fflush(stdin);
    gets(mh.tenHang);

    printf("\tDon gia: ");
    scanf("%d",&mh.donGia);

    printf("\tSo luong: ");
    scanf("%d", &mh.soluong);

    mh.thanhTien = mh.donGia * mh.soluong;

    return mh;
}
void nhapDanhSachMatHang(char *filePath)
{
    FILE *f = fopen(filePath,"wb");
    while(true)
    {
        matHang mh = nhapthongtin();
        fwrite(&mh, sizeof(matHang),1,f);
        printf("\tBam yes de nhap tien: ");
        char chon;
        fflush(stdin);
        scanf("%c",&chon);
        if(chon !=  'yes' && chon != 'YES')
            break;
    }
    fclose(f);
}
void boSungMatHang(char *filePath, matHang mh)
{
    FILE *f= fopen(filePath, "ab");
    fwrite(&mh, sizeof(matHang),1,f);
    fclose(f);

}

void hienThiMatHang (matHang mh)
{
    printf("%20s%10d%10d%10d\n",mh.tenHang,mh.donGia,mh.soluong,mh.thanhTien);
}
void docNoiDungTep(char *filePath)
{
    FILE *f =fopen(filePath, "rb");
    printf("\t\t SO LIEU BAN HNAG\n");
    printf("\t%5s%20s%10s%10s%10s\n", "STT", "TEN HANG", "DON GIA", "SO LUONG", "THANH TIEN");
    int stt=1;
    int tongTien=0;
    while(!feof(f))
    {
        matHang mh;
        if(fread(&mh, sizeof(matHang),1,f)>0)
        {
            printf("\t%5d", stt++);
            hienThiMatHang(mh);
            tongTien +=mh.thanhTien;
        }

    }
    printf("\t%35s%10s%10d\n", "", "Tong tien", tongTien);
    fclose(f);
}
int main()
{
    nhapDanhSachMatHang("SO_LIEU.C");
    printf("\tBo sung cac mat hang\n");
    boSungMatHang("SO_LIEU.C", nhapthongtin());
    printf("\t\tMat hang thu hai\n");
    boSungMatHang("SO_LIEU.C", nhapthongtin());
    docNoiDungTep("SO_LIEU.C");
}
