#include<iostream>
#include<cstdio>
using namespace std;

int main() {
    int sum = 0;
    int i = 1;
    while(i <= 5) {
        sum += i;
        i++;
    }
    printf("Tổng các số từ 1 đến 5 là: %d\n", sum);
    return 0;
}
