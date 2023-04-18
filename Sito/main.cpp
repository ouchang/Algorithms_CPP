#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

bool P[1001];

void makeSito() {
    P[0] = false;
    P[1] = false;
    for(int i=2; i*i<100; i++) {
        if(P[i]) {
            for(int j=i*i; j<1001; j+=i) {
                P[j] = false;
            }
        }
    }
}

int main() {
    int x;

    fill(P+0, P+100, true);
    makeSito();

    scanf("%d", &x);
    if(P[x])
        printf("%d jest liczbą pierwszą!", x);
    else
        printf("%d nie jest liczbą pierwszą!", x);
}
