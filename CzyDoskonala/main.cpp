#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int a;
    int sumaDzielnikow = 1;

    scanf("%d", &a);

    for(int i=2; i*i<a; i++) {
        if(a % i == 0) {
            sumaDzielnikow += i;
            sumaDzielnikow += a/i;
        }
    }

    if(sumaDzielnikow == a)
        printf("To jest liczba doskonała!\n");
    else 
        printf("To nie jest liczba doskonała!\n");
}
