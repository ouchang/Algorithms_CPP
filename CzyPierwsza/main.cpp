#include <iostream>
#include <stdio.h>
using namespace std;

bool CzyPierwsza(int x) {
    for(int i=2; i*i<=x; i++) {
        if(x%i==0)
            return false;
    }
    return true;
}

int main() {
    int x;

    scanf("%d", &x);

    if(CzyPierwsza(x))
        printf("%d jest liczbą pierwszą!\n", x);
    else
        printf("%d nie jest liczbą pierwszą!\n", x);
}
