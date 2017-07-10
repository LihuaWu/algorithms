//Tag: search half_search dfs

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define N 160
#define INF 99999999

int k[N], p[N], num[INF];

int n, M, cnt;
int64_t total;

int power(int x, int p) {
    int s = 1;
    while(p) {
        if (p & 0x1) s *= x;
        p >>= 1;
        if (p) x *= x;
    }
    return s;
}

void dfs(int s, int e, int sum) {
    if (s == e) {
        num[cnt++] = sum;
        return;
    }
    for (int x = 1; x <= M; x++) {
        dfs(s+1, e,  sum+k[s]*power(x, p[s]));
    }
}

int Find(int x) {
    int L = 0, R = cnt;
    int l, r;
    while (L < R) {
        int mid = L + ((R-L)>>1);
        if (x <= num[mid]) R = mid; else L = mid+1;
    }
    l = L;
    L = 0; R = cnt;
    while (L < R) {
        int mid = L + ((R-L)>>1);
        if (x >= num[mid]) L = mid+1; else R = mid;
    }
    r = R;
    return r-l;
}

void dfs2(int s, int e, int sum) {
    if (s == e) {
        int m = Find(-sum);
//        printf("-sum=%d m=%d\n", -sum, m);
        total += m; 
        return;
    }
    for (int x = 1; x <= M; x++) {
        dfs2(s+1, e, sum+k[s]*power(x, p[s]));
    }
}



int main () {
    total = 0;
    cin >> n >> M;

    for (int i = 0; i < n; i++) {
        cin >> k[i] >> p[i];
    }
    dfs(0, n/2,  0);
    sort(num, num+cnt);
    dfs2(n/2, n, 0);
    printf("%lld\n", total);
    return 0;
}
