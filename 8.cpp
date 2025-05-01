#include <stdio.h>
#include <math.h>

// Ham kiem tra so nguyen to
int laSoNguyenTo(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Ham kiem tra so chinh phuong
int laSoChinhPhuong(int n) {
    int canBacHai = sqrt(n);
    return canBacHai*canBacHai == n;
}

void kiemTraSoNguyen() {
    int x;
    printf("Nhap vao 1 so nguyen x tu ban phim: ");
    scanf("%d", &x);
    printf("So %d co phai la so nguyen? ", x);
    printf("Co\n");
    printf("So %d co phai la so nguyen to? ", x);
    if (laSoNguyenTo(x)) {
        printf("Co\n");
    } else {
        printf("Khong\n");
    }
    printf("So %d co phai la so chinh phuong? ", x);
    if (laSoChinhPhuong(x)) {
        printf("Co\n");
    } else {
        printf("Khong\n");
    }
}

void timUocSoChungBoiSoChung() {
    // Them ma cua ban vao day
}

void tinhTienKaraoke() {
    int gioBatDau, gioKetThuc;
    printf("Nhap vao gio bat dau: ");
    scanf("%d", &gioBatDau);
    printf("Nhap vao gio ket thuc: ");
    scanf("%d", &gioKetThuc);

    int thoiGian = gioKetThuc - gioBatDau;
    
    double tongTien = 0;
    
    if(thoiGian > 3){
        tongTien += 150000 * 3 + 150000 * (thoiGian - 3) * 0.7;
        
        if(gioBatDau >=14 && gioBatDau <=17){
            tongTien *= 0.9;
        }
        
        printf("Gia tien can thanh toan: %.2f\n", tongTien);
        
        return;
        
     }else{
         tongTien += 150000 * thoiGian;
         
         if(gioBatDau >=14 && gioBatDau <=17){
            tongTien *= 0.9;
         }
         
         printf("Gia tien can thanh toan: %.2f\n", tongTien);
         
         return;
     }
}

void tinhTienDien() {
   int kwh;
   printf("Nhap vao so (kwh) dien su dung: ");
   scanf("%d", &kwh);

   double tongTien = 0;

   if(kwh <=50){
       tongTien += kwh * 1678;
   }else if(kwh <=100){
       tongTien += kwh * 1734;
   }else if(kwh <=200){
       tongTien += kwh * 2014;
   }else if(kwh <=300){
       tongTien += kwh * 2536;
   }else if(kwh <=400){
       tongTien += kwh * 2834;
   }else{
       tongTien += kwh * 2927;
   }

   printf("So tien can phai tra: %.2f\n", tongTien);
}

void doiTien() {
   int soTienCanDoi;
   printf("Nhap vao so tien can doi: ");
   scanf("%d", &soTienCanDoi);

   int menhGia[] = {500,200,100,50,20,10,5,2,1};
   
   for(int i=0; i<9; i++){
       int soTo = soTienCanDoi / menhGia[i];
       soTienCanDoi %= menhGia[i];
       
       if(soTo >0){
           printf("%d to %d\n", soTo, menhGia[i]);
       }
   }
}

int main() {
    int luaChon;
    do {
        printf("\n===== Menu =====\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim uoc so chung va boi so chung\n");
        printf("3. Tinh tien karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Doi tien\n");
        printf("0. Thoat\n");
        printf("================\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                kiemTraSoNguyen();
                break;
            case 2:
                timUocSoChungBoiSoChung();
                break;
            case 3:
                tinhTienKaraoke();
                break;
            case 4:
                tinhTienDien();
                break;
            case 5:
                doiTien();
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (luaChon != 0);

    return 0;
}
