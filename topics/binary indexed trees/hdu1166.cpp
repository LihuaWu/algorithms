/*
 * Title: 
 * Link: http://acm.hdu.edu.cn/showproblem.php?pid=1166
 * Tag: 
 * */

#include <stdio.h>
#include <string.h>

#include <iostream>

using namespace std;

#define INF 0x3f3f3f3f

#define N 50010

int T, n, a[N], c[N];


int lowbit(int x) {
    return x & -x;
}

int add(int x, int v) {
    while(x <= n) {
        c[x] += v;
        x += lowbit(x);
    }
    return 0;
}

int sum(int x) {
    int res = 0;
    while(x > 0) {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(c, 0, sizeof(c));
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            add(i, a[i]);
        }
        string op; 
            printf("Case %d:\n", t);
        while(op != "End") {
            cin >> op;
            if (op == "End") {
                break;
            }
            int x, v;
            cin >> x >> v;
            if (op == "Add") add(x, v);
            else if (op == "Sub") add(x, -v);
            else if (op == "Query") printf("%d\n", (sum(v) - sum(x-1)));
        }

    }
    return 0;
}
