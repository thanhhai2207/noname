#include <stdio.h>

// Tinh va in ra tong 2 so nhap tu ban phim
// B1: khai bao ham 
void tinhVaInTong2So() {
    int a, b, tong;
    //nhap 2 so
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    // tinh tong
    tong = a +b;
    // in ra man hinh
    printf("Tong = %d", tong);

} 

int main() {

    // goi ham va chay
    tinhVaInTong2So();



}