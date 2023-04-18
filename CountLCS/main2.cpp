#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

//Program wyznacza długość LCS'a oraz liczbę możliwych różnych LCS'ów 

int T[100][100];
int D[100][100];

int main() {
    string a,b;
    int len_a, len_b;

    cin >> a >> b;

    len_a = a.length();
    len_b = b.length();

    for(int i=0; i<=len_a; i++) {
        for(int j=0; j<=len_b; j++) {
            if(i == 0 || j == 0) {
                T[i][j] = 0;
            } else {
                if(a[i-1] == b[j-1]) {
                    T[i][j] = T[i-1][j-1] + 1;
                } else {
                    T[i][j] = max(T[i-1][j], T[i][j-1]);
                }
            }
        }
    }

    for(int i=0; i<=len_a; i++) {
        for(int j=0; j<=len_b; j++) {
            if(i == 0 || j == 0) {
                D[i][j] = 1;
            } else {
                D[i][j] = 0;
                if(a[i-1] == b[j-1]) {
                    D[i][j] = T[i-1][j-1];
                } else {
                    if(T[i][j] == T[i-1][j]) {
                        D[i][j] += D[i-1][j];
                    }
                    if(T[i][j] == T[i][j-1]) {
                        D[i][j] += D[i][j-1];
                    }
                    if(T[i][j] == T[i-1][j-1]) {
                        D[i][j] -= D[i-1][j-1];
                    }
                }
            }
        }
    }

    printf("Dlugosc LCS'a: %d\nLiczba LCS o podanej dlugosci: %d\n", T[len_a][len_b], D[len_a][len_b]);
}
