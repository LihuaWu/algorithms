#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define N 5000

int T, n, m;
int u, v;
int res, ans;
vector<int> e[N];
vector<int> path;
int color[N], step[N], par[N];

void dfs(int u, int t) {
    color[u] = 1;
    step[u] = t;
    vector<int>& adj = e[u];
    for (size_t i = 0; i < adj.size(); i++) {
        int v = adj[i];
        if (color[v] == 0) {
            dfs(v, t+1);
        } else if (color[v] == 1) { // found a cycle
            res = step[u]-step[v] + 1;
            ans = ::max(res, ans);
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            dfs(i, 1);
        }
    }
}

int main () {
    cin >> T;
    for (int i = 0; i < T; i++) {
        ::memset(color, 0, sizeof(color));
        ::memset(step, 0, sizeof(step));
        res = 0;
        ans = 0;
        cin >> n >> m;
        for (int i = 0; i <= n; i++) { e[i].clear(); }

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        solve();
        if (ans >= 3) printf("%d\n", ans);
        else printf("0\n");
//        printf("path as follows:");
//        for (int i = 0; i < path.size(); i++) {
//            printf("%d ", path[i]);
//        }
//        printf("\n");
    }
    return 0;
}
