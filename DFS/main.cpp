#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> G[100];
bool VIST[100];


void DFS(int x) { 
    int y;

    printf("Wierzchołek: %d\n", x);

    VIST[x] = true;
    for(int i=0; i<G[x].size(); i++) {
        y = G[x][i];
        if(!VIST[y]) {
            DFS(y);
        }
    }
}

int main() {
    int n,m;
    int x,y;

    scanf("%d %d", &n, &m);

    fill(VIST+0, VIST+n+1, false);

    for(int i=0; i<m; i++) {
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
    }

    DFS(0);
}
