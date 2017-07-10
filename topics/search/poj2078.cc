//Tag: search

#include <stdio.h>

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define N 7

#define INF 9999999

int n;
int a[N][N];
int c[N];
int b[N];
int minV;



void dfs(int r) {
    if (r == n) {
        int maxelem = *max_element(c, c+n);
        if (minV > maxelem) {
            minV = maxelem;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int newidx = j+i;
            if (newidx >= n) newidx -= n;
            c[newidx] = c[newidx] - a[r][newidx] + a[r][j];
        }
        rotate(a[r],a[r]+n-i, a[r]+n);
        dfs(r+1);
        for (int j = 0; j < n; j++) {
            int newidx = (j-i+n);
            if (newidx >= n) newidx -= n;
            c[newidx] = c[newidx] - a[r][newidx] + a[r][j];
        }
        rotate(a[r], a[r]+i, a[r]+n);
    }
}


int main () {
    while(1) {
        cin >> n;
        minV = INF;
        if (n == -1) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            c[i] = 0;
            for (int j = 0; j < n; j++) {
                c[i] += a[j][i];
            }
        }
        dfs(1);
        printf("%d\n", minV);
    }
    return 0;
}
