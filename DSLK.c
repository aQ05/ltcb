#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct
{
    char id[10];
    char hoTen[20];
    char chucVu[20];
    char sdt[15];
} NhanVien;

typedef struct node
{
    NhanVien data;
    struct node* next;
} Node;

typedef struct
{
    Node* first;
} TList;

Node* capPhatNode ()
{
    return (Node*)malloc(sizeof(Node));
}

TList* taoDanhSach()
{
    TList* list = (TList*)malloc(sizeof(TList));
    list->first = NULL;
    return list;
}

NhanVien nhapThongTin()
{
    NhanVien nv;
    printf("\tMa nhan vien: ");
    fflush(stdin);
    gets(nv.id);

    printf("\tHo ten: ");
    fflush(stdin);
    gets(nv.hoTen);

    printf("\tChuc vu: ");
    fflush(stdin);
    gets(nv.chucVu);

    printf("\tSo dien thoai: ");
    fflush(stdin);
    gets(nv.sdt);

    return nv;
}

Node* taoNode(NhanVien nv)
{
    Node* pNode = capPhatNode();
    pNode->data = nv;
    pNode->next = NULL;
    return pNode;
}

void hienThiNhanVien (NhanVien nv)
{
    printf("%10s%20s%20s%13s\n",nv.id,nv.hoTen,nv.chucVu,nv.sdt);
}

void hienThiDanhSach (TList* list)
{
    printf("\t\tDANH SACH NHAN VIEN\n");
    printf("\t%5s%10s%20s%20s%13s\n","STT", "MA NV", "HO TEN", "CHUC VU", "SDT");

    int stt = 1;
    for (Node* i = list->first; i!=NULL; i=i->next)
    {
        printf("\t%5d",stt++);
        hienThiNhanVien(i->data);
    }
}

Node* timNodeCuoi(TList* list)
{
    if (list->first == NULL)
        return NULL;
    Node* lastNode = list->first;
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    return lastNode;
}

void themNodeVaoCuoi (TList* list, Node* pNode)
{
    //Nếu danh sách chưa có phần tử
    if (list->first == NULL)
    {
        list->first = pNode;
        pNode->next = NULL;
    }
    else
    {
        Node* lastNode = timNodeCuoi(list);
        lastNode->next = pNode;
        pNode->next = NULL;
    }
}

Node* timNode (TList* list, char* maNV)
{
    for (Node* i = list->first; i!= NULL; i=i->next)
    {
        if (strcmp(i->data.id,maNV)==0)
            return i;
    }
    return NULL;
}

Node* timPreNode (TList* list, Node* pNode)
{
    if (list->first==NULL)
        return NULL;
    if (list->first == pNode)
        return NULL;
    Node* preNode = list->first;
    while (preNode->next != pNode)
        preNode = preNode->next;
    return preNode;
}

void xoaNode (TList* list, Node* pNode)
{
    if (list->first == NULL)
        return;
    if (list->first == pNode)
    {
        list->first = pNode->next;
        free(pNode);
    }
    else
    {
        Node* preNode = timPreNode(list,pNode);
        preNode->next = pNode->next;
        free(pNode);
    }
}

void inMenu()
{
    printf("\t\tMENU\n");
    printf("\t1. Nhap danh sach\n");
    printf("\t2. Hien thi danh sach\n");
    printf("\t3. Xoa nhan vien\n");
    printf("\t0. Thoat chuong trinh\n");
    printf("\t\tVui long chon: ");
}

int main()
{
    TList* list = taoDanhSach();
    int n;

    while (true)
    {
        inMenu();

        int chon;
        scanf("%d",&chon);

        switch (chon)
        {
            case 1:
            {
                printf("\tNhap so luong nhan vien: ");
                scanf("%d",&n);
                for (int i=1; i<=n; i++)
                {
                    printf("\tNhap nhan vien thu %d:\n",i);
                    themNodeVaoCuoi(list,taoNode(nhapThongTin()));
                }
                break;
            }
            case 2:
            {
                hienThiDanhSach(list);
                break;
            }
            case 3:
            {
                char maNV[10];
                printf("\tNhap ma nhan vien can xoa: ");
                fflush(stdin);
                gets(maNV);
                if (timNode(list,maNV)==NULL)
                    printf("\tKhong tim duoc ma nhan vien %s\n",maNV);
                else
                {
                    xoaNode(list,timNode(list,maNV));
                }
                hienThiDanhSach(list);
                break;
            }
            case 0:
                return 0;
            default:
                printf("\tChi nhap tu 0-3\n");
        }
    }
}
