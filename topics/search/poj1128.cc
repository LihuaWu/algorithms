#include <stdio.h>

#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define N 30

int h, w, n;

int ax, ay, bx, by;

char a[N][N], edge[N][N];


int degree[N];
char ans[N];


void findV(int x, int y) {
    char ch = a[x][y];
    ax = bx = x;
    ay = by = y;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == ch) {
                if (i < ax) ax = i;
                if (i > bx) bx = i;
                if (j < ay) ay = j;
                if (j > by) by = j;
            }
        }
    }
}


void build() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] != '.' && degree[a[i][j]-'A'] == -1) {
                n++;
                char ch = a[i][j];
                degree[ch -'A'] = 0;
                findV(i, j);
                for (int k = ax; k <= bx; k++) {
                    if (a[k][ay] != ch && a[k][ay] != '.') {
                        edge[ch-'A'][a[k][ay]-'A'] = 1;
                    }
                    if (a[k][by] != ch && a[k][by] != '.') {
                        edge[ch-'A'][a[k][by]-'A'] = 1;
                    }
                }
                for (int k = ay; k <= by; k++) {
                    if (a[ax][k] != ch && a[ax][k] != '.') {
                        edge[ch-'A'][a[ax][k]-'A'] = 1;
                    }
                    if (a[bx][k] != ch && a[bx][k] != '.') {
                        edge[ch-'A'][a[bx][k]-'A'] = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (edge[i][j] == 1) {
                degree[j]++;
            }
        }
    }
}

void dfs(int x) {
    if (x == n) {
        for (int i = 0; i < n; i++) {
            printf("%c", ans[i]);
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (degree[i] == 0) {
            ans[x] = i + 'A';

            degree[i] = -1;
            for (int j = 0; j < 26; j++) {
                if (edge[i][j] == 1) {
                    degree[j]--;
                }
            }

            dfs(x+1);
            degree[i] = 0; 
            for (int j = 0; j < 26; j++) {
                if (edge[i][j] == 1) {
                    degree[j]++;
                }
            }
        }
    }

}



int main () {
    while(cin >> h >> w) {
        n = 0;
        ::memset(degree, -1, sizeof(degree));
        ::memset(ans, -1, sizeof(ans));
        ::memset(edge, 0, sizeof(edge));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> a[i][j];
                edge[i][j] = 0;
            }
        }
        build();
        dfs(0);
    }

    return 0;
}
