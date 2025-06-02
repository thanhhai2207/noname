#include <stdio.h>

int main() {
    int n, i, tong = 0;

    printf("Nhap so nguyen n: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        tong += i;
    }

    printf("Tong S = 1 + 2 + 3 + ... + %d la: %d\n", n, tong);

    return 0;
}
