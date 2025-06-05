#include<stdio.h>
int main() {
    int n, i, tong = 0, soluong = 0;
    float trungBinhCong;
    do {
        printf("Nhap so nguyen n lon hon 10:");
        scanf("%d", &n);
    }while(n <= 10);
    for(i = 1; i <= n; i++) {
        if(i % 2 != 0) {
            tong += i;
            soluong++;

        }
    }
    trungBinhCong = tong / soluong;
    printf("tong cac so tu 1 den %d la %d\n", n, tong);
    printf("trung binh cong cac so le tu 1 den %d la: %.2f\n", n, trungBinhCong);
    return 0;
    
}