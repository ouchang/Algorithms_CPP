#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//Program wyszukuje drogi o najmniejszym koszcie z wierzchołka startowego (1) do pozostałych
//Pracuje on na grafie skierowanym!
//UWAGA: Wierzchołki numerowane są od 1!

const int INF = 2147483617;

struct Edge {
    int x=0;
    int y=0;
    int w=0;
};

int D[100];
bool VIST[100];
vector <Edge> G[100];

struct Compare {
    bool operator() (const int &lhs, const int &rhs) {
        return D[lhs] > D[rhs];
    }
};

priority_queue<int, vector<int>, Compare> Q;

void Dijkstra() {
    int curr;
    Edge t_edge;

    while(!Q.empty()) {
        curr = Q.top();
        Q.pop();
        if(!VIST[curr]) {
            VIST[curr] = true;
            for(int i=0; i<G[curr].size(); i++) {
                t_edge = G[curr][i];
                if(D[t_edge.y] > D[curr] + t_edge.w) {
                    D[t_edge.y] = D[curr] + t_edge.w;
                    Q.push(t_edge.y);
                }
            }
        }
    }
}

int main() {
    int m; //liczba krawędzi w grafie
    int n; // liczba wierzchołków
    int x,y,w;
    Edge tmp;

    scanf("%d %d", &n, &m);

    fill(D+0, D+n+1, INF);
    fill(VIST+0, VIST+n+1, false);

    for(int i=0; i<m; i++) {
        scanf("%d %d %d", &x, &y, &w);
        tmp.x = x;
        tmp.y = y;
        tmp.w = w;
        G[tmp.x].push_back(tmp);
    }

    D[1] = 0;
    Q.push(1); 
    Dijkstra();


    printf("   ");
    for(int i=1; i<=n; i++) {
        printf("%d|", i);
    }

    printf("\nD: ");
    for(int i=1; i<=n; i++) {
        printf("%d|", D[i]);
    }
    printf("\n");
}
