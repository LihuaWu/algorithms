/*
 * Title: Cube
 * Link: http://acm.hdu.edu.cn/showproblem.php?pid=3584
 * */

#include <stdio.h>
#include <string.h>

#include <iostream>

using namespace std;

#define N  50010

int n, m, c[N],data[N], i, vis[N];

int lowbit(int x) {
    return x & -x;
}

int sum(int x) {
    int res = 0;
    while (x > 0) {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}

int add(int x, int v) {
    while(x <= n) {
        c[x] += v;
        x += lowbit(x);
    }
    return 0;
}

int bsearch(int val) {
    int l = 1, r = n+1;
    while(l < r) {
        int mid = (l+r)/2;
        if (sum(mid) >= val) {
            r = mid;
        } else {
            l = mid+1;
        }
    } 
    return r;
}

int main() {
    while(cin >> n >> m) {
        string op;
        int val;
        memset(c, 0, sizeof(c));
        memset(data, 0, sizeof(data));
        memset(vis, 0, sizeof(vis));
        i = 0;
        while(m--) {
            cin >> op;
            if (op == "D") {
                cin >> val;
                data[++i] = val;
                vis[val] = 1;
                add(val, 1);
            } else if (op == "Q") {
                for (int i = 1; i <= n; i++) {
                    printf("sum(%d)=%d\n", i, sum(i));
                }
                cin >> val;
                if (vis[val] == 1) {
                    printf("%d\n", 0);
                } else {
                    int cnt = sum(val);
                    printf("%d\n", bsearch(cnt+1)-bsearch(cnt)-1);
                }
            } else if (op == "R") {
                val = data[i--];
                vis[val] = 0;
                add(val, -1);
            }
        }

    }
    return 0;
}
