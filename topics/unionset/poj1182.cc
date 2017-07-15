#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define N 100100

int n, k, ans;

int fa[N], rank[N];

void init() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}

int find(int v) {
    if (fa[v] == v) return v;
    else {
        int temp = fa[v];
        fa[v] = find(fa[v]);
        rank[v] = (rank[v] + rank[temp])%3; 
    }
    return fa[v];
}

bool check(int x, int y, int d) {
    if (x > n || y > n) return false; //rule no.2
    if (d == 1 && x == y) return false; //rule no.3 , already minus by 1

    int fx = find(x);
    int fy = find(y);

    if (fx == fy) {
        int rxy = ((rank[x]-rank[y])%3+3)%3;
        return rxy == d;
    }
    return true;
}

void merge(int x, int y, int d) {
    int fx = find(x);
    int fy = find(y);

    if (fx != fy) {
        fa[fx] = fy;
        rank[fx] = (d + rank[y]-rank[x]+3)%3;
    }
}

int main () {
    cin >> n >> k;
    ans = 0;
    ::memset(fa, 0, sizeof(fa));
    ::memset(rank, 0, sizeof(rank));
    init();
    int d, x, y;
    for (int i = 0; i < k; i++) {
        cin >> d >> x >> y;
        if (!check(x, y, d-1)) {
            ans++;
        } else {
            merge(x, y, d-1);
        }
    }
    printf("%d\n", ans);
    return 0;
}
