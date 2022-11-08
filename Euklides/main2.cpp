#include <iostream>
#include <stdio.h>
using namespace std;

//Wersja iteracyjna

int NWD(int a, int b) {
    int tmp;

    while(b > 0) {
        tmp = b;
        b = a%b;
        a = tmp;
    }

    return a;
}

int main() {
    int a,b;
    int nwd=0;

    scanf("%d %d", &a, &b);
    nwd = NWD(a,b);
    printf("NWD(%d, %d): %d\n", a,b, nwd);
}
