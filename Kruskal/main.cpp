#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

//Algorytm wyznacza minimalne drzewo rozpinające dla spójnego grafu nieskierowanego
//UWAGA: wierzchołki numerowane są od 1!

struct Edge {
    int x=0;
    int y=0;
    int w=0;
    int nr=0;
};

struct Compare {
    bool operator() (const Edge &lhs, const Edge &rhs) {
        return lhs.w > rhs.w;
    }
};

priority_queue<Edge, vector<Edge>, Compare> Q;
int KAP[100];

int FindKap(int a) {
    if(a == KAP[a]) {
        return a;
    }
    
    int ka;
    ka = FindKap(KAP[a]);
    KAP[a] = ka;
    return ka;
}

void Union(int a, int b) {
    int ka, kb;

    ka = FindKap(a);
    kb = FindKap(b);

    if(ka == kb)
        return;
    
    KAP[ka] = kb;
}

void Kruskal() {
    Edge t_edge;
    int kx, ky;

    while(!Q.empty()) {
        t_edge = Q.top();
        Q.pop();

        kx = FindKap(t_edge.x);
        ky = FindKap(t_edge.y);

        if(kx != ky) {
            Union(t_edge.x, t_edge.y);
            printf("%d\n", t_edge.nr);
        }
    }
}

int main() {
    int n,m;
    int x,y,w;
    Edge tmp;

    scanf("%d %d", &n, &m);
    for(int i=1; i<=m; i++) {
        scanf("%d %d %d", &x, &y, &w);
        tmp.x = x;
        tmp.y = y;
        tmp.w = w;
        tmp.nr = i;
        Q.push(tmp);
    }

    for(int i=1; i<=n; i++) {
        KAP[i] = i;
    }

    Kruskal();
}
