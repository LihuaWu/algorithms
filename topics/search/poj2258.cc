#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

#define N 30

int edge[N][N]; //edges 
int vis[N][N]; // check if an edge is visited.

int n, m, ans, res;

void dfs(int x) {
    for (int i = 0; i < n; i++) {
        if (!edge[x][i] || vis[x][i]) continue;
        vis[x][i] = vis[i][x] = 1;
        res++;
        ans = max(ans, res);
        dfs(i);
        res--;
        vis[x][i] = vis[i][x] = 0;
    }
}


void solve() {
    ans = 0;
    for (int i = 0; i < n; i++) {
        res = 0;
        ::memset(vis, 0, sizeof(vis));
        dfs(i);
    }
}

int main () {
    while(true) {
        ::memset(edge, 0, sizeof(edge));
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            edge[u][v] = edge[v][u] = 1;
        }

        solve();
        printf("%d\n", ans);
    }
    return 0;
}
