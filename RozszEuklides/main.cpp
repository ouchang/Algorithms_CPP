#include <iostream>
#include <stdio.h>
using namespace std;

//Program rozwiązuje równanie diofantyczne x*a + y*b = c, dla zadanych a i b
//Zatem program zwraca wartości x,y,c

int RozszEuklides(int a, int b, int &x, int &y) {
    if(a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int nwd, tx, ty;
    
    nwd = RozszEuklides(b%a, a, tx, ty);
    x = ty - (b/a)*tx;
    y = tx;
    return nwd;
}

int main() {
    int x,y;
    int a,b,c;

    scanf("%d %d", &a, &b);

    c = RozszEuklides(a,b,x,y);
    printf("Rownianie diofantycze %d * %d + %d * %d = %d\n", x, a, y, b, c);
}
