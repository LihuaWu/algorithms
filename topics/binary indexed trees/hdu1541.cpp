/*
 * Title: Stars
 * Link: http://acm.hdu.edu.cn/showproblem.php?pid=1541
 * */

#include <stdio.h>
#include <string.h>

#include <iostream>

using namespace std;

#define N 32010

int n, c[N], level[N];


int lowbit(int x) {
    return  x & -x;
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
    while (x < N) {
        c[x] += v;
        x += lowbit(x);
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    while(cin>>n) {
        int x, y;
        memset(c, 0, sizeof(c));
        memset(level, 0, sizeof(level));
        for (int i = 1; i <= n; i++) {
            cin >> x >> y;
            x++;
            add(x, 1);
            level[sum(x)]++;
//            printf("sum(x)=%d\n", sum(x));
        }
        for (int i = 1; i <= n; i++) {
            printf("%d\n", level[i]);
        }
    }
    return 0;
}
