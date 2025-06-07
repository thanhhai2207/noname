#include <stdio.h>

int main() {
    printf("Nhap ho va ten: ");
    char hoVaTen[50];
    gets(hoVaTen);
    printf("Ho ten: %s\n", hoVaTen);

    printf("Nhap dia chi: ");
    char diaChi[50];
    gets(diaChi);
    printf("Dia chi: %s\n", diaChi);

    printf("nhap tuoi: ");
    int tuoi;
    scanf("%d", &tuoi);
    printf("Tuoi: %d\n, tuoi");

    // fflush(stdin);
    int c; 
    while (c = getchar() != '\n' && c != EOF) {}
    
    
    }
    

    printf("Nhap so thich:");
    char soThich[50]; 
    gets(soThich);
    printf("So thich; %s\n", soThich);




}