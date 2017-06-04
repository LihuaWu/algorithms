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
    int l = 0, r = n+1;
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
                if (vis[val] == 1) continue;
                data[++i] = val;
                vis[val] = 1;
                add(val, 1);
            } else if (op == "Q") {
                cin >> val;
                if (vis[val] == 1) {
                    printf("%d\n", 0);
                } else {
                    int cnt = sum(val);
                    int right = bsearch(cnt+1);
                    int left = bsearch(cnt);
                    printf("%d\n", right-left-1);
                   // printf("left=%d right=%d result=%d\n", left, right, right-left-1);
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
