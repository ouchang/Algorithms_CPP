#include <iostream>
#include <stdio.h>
using namespace std;

//Wersja rekurencyjna

int NWD(int a, int b) {
    if(b == 0)  
        return a;
    return NWD(b, a%b);
}

int main() {
    int a,b;
    int nwd=0;

    scanf("%d %d", &a, &b);
    nwd = NWD(a,b);
    printf("NWD(%d, %d): %d\n", a,b, nwd);
}
