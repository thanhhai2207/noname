#include<stdio.h>
struct ThongtinSV{
    char tenSv[50];
    int tuoi;
    char email[50];
    int soDT;
    char diachi[100];
};
int main() {
    struct ThongtinSV tt;
    printf("Nhap ten SV:");
    fgets (tt.tenSv, sizeof(tt.tenSv), stdin);
    
    printf("Nhap tuoi:");
    scanf("%d", &tt.tuoi);
    while(getchar() != '\n');

    printf("Nhap email:");
    fgets(tt.email, sizeof(tt.email), stdin);
    
    printf("Nhap sdt:");
    scanf("%d", &tt.soDT);
    while(getchar() != '\n');

    printf("Nhap dia chi:");
    fgets(tt.diachi, sizeof(tt.diachi), stdin);
    
    printf("Ten SV:%s", tt.tenSv);
    printf("Tuoi:%d\n", tt.tuoi);
    printf("email:%s",tt.email);
    printf("sdt:%d\n", tt.soDT);
    printf("dia chi:%s", tt.diachi);
    return 0;




}
