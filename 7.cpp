#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Chuc nang so 6
void tinhLaiSuat() {
    int soTienVay;
    printf("Nhap so tien muon vay: ");
    scanf("%d", &soTienVay);

    float laiSuat = 0.05;
    int kyHan = 12;
    int tienGocTraMoiKy = soTienVay / kyHan;
    int tienLaiKyDau = soTienVay * laiSuat;

    printf("Tien vay: %d\n", soTienVay);
    printf("Lai suat hang thang: %.2f%%\n", laiSuat * 100);
    printf("Ky han: %d thang\n", kyHan);

    for (int i = 0; i < kyHan; i++) {
        printf("Ky %d: Tra goc %d, tra lai %d\n", i + 1, tienGocTraMoiKy, tienLaiKyDau);
        tienLaiKyDau = (soTienVay - i*tienGocTraMoiKy) * laiSuat;
    }
}

// Chuc nang so 7
void vayTienMuaXe() {
    int phanTramVayToiDa;
    printf("Nhap vao so phan tram vay toi da: ");
    scanf("%d", &phanTramVayToiDa);

    int tienVay = 500 * phanTramVayToiDa / 100;
    int thoiHanVay = 24;
    float laiSuatNam = 0.072;
    float tienTraLanDau = tienVay * (1 + laiSuatNam);
    float tienTraHangThang = tienTraLanDau / (thoiHanVay * 12);

    printf("So tien phai tra lan dau: %.2f trieu\n", tienTraLanDau);
    printf("So tien phai tra hang thang: %.2f trieu\n", tienTraHangThang);
}


// Chuc nang so 8
typedef struct {
    char hoTen[50];
    float diem;
} SinhVien;

void sapXepSinhVien() {
    SinhVien sv[100];
    int soLuongSV;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &soLuongSV);
    getchar(); 

    for (int i = 0; i < soLuongSV; i++) {
        printf("Nhap ho ten sinh vien thu %d: ", i + 1);
        fgets(sv[i].hoTen, 50, stdin); 
        sv[i].hoTen[strcspn(sv[i].hoTen, "\n")] = 0; 
        printf("Nhap diem sinh vien thu %d: ", i + 1);
        scanf("%f", &sv[i].diem);
        getchar(); 
    }

    // Sap xep sinh vien theo diem giam dan
    for (int i = 0; i < soLuongSV - 1; i++) {
        for (int j = i + 1; j < soLuongSV; j++) {
            if (sv[i].diem < sv[j].diem) {
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }

    // Hien thi thong tin sinh vien
    for (int i = 0; i < soLuongSV; i++) {
        char hocLuc[20];
        if (sv[i].diem >= 9.0) {
            strcpy(hocLuc, "Xuat sac");
        } else if (sv[i].diem >= 8.0) {
            strcpy(hocLuc, "Gioi");
        } else if (sv[i].diem >= 6.5) {
            strcpy(hocLuc, "Kha");
        } else if (sv[i].diem >= 5.0) {
            strcpy(hocLuc, "Trung binh");
        } else {
            strcpy(hocLuc, "Yeu");
        }

        printf("Sinh vien: %s\n", sv[i].hoTen);
        printf("Diem: %.2f\n", sv[i].diem);
        printf("Hoc luc: %s\n", hocLuc);
    }
}


// Chuc nang so 9
void gameFPOLY_LOTT() {
    srand(time(NULL));
    int soMayMan1 = rand() % 15 + 1;
    int soMayMan2 = rand() % 15 + 1;

    int soChon1, soChon2;
    printf("Nhap vao so thu nhat: ");
    scanf("%d", &soChon1);
    printf("Nhap vao so thu hai: ");
    scanf("%d", &soChon2);

    int soTrung = 0;
    if (soChon1 == soMayMan1 || soChon1 == soMayMan2) {
        soTrung++;
    }
    if (soChon2 == soMayMan1 || soChon2 == soMayMan2) {
        soTrung++;
    }

    switch (soTrung) {
        case 0:
            printf("Chuc ban may man lan sau\n");
            break;
        case 1:
            printf("Chuc mung ban da trung giai nhi\n");
            break;
        case 2:
            printf("Chuc mung ban da trung giai nhat\n");
            break;
    }
}


int main() {
    int chucNang;
    printf("Chon chuc nang (6-9): ");
    scanf("%d", &chucNang);

    switch (chucNang) {
        case 6:
            tinhLaiSuat();
            break;
        case 7:
            vayTienMuaXe();
            break;
        case 8:
            sapXepSinhVien();
            break;
        case 9:
            gameFPOLY_LOTT();
            break;
        
        default:
            printf("Chuc nang khong hop le.\n");
            break;
    }

    return 0;
}

