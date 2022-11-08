#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

//char A[50];
//char B[50];
int T[100][100];

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

    printf("Długosc LCS'a: %d\n", T[len_a][len_b]);
}
