#include<stdio.h>
#include<math.h>
int main() {
    float dai, rong, chuVi, dienTich;
    printf("Nhap chieu dai:");
    scanf("%f", &dai);
    printf("Nhap chieu rong:");
    scanf("%f", &rong);
    chuVi = (dai + rong) * 2;
    dienTich = dai * rong;
    printf("Chu vi la: %.2f\n", chuVi);
    printf("Dien tich la: %.2f\n", dienTich);
    return 0;

}