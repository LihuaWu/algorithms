/*
 * Title: Minimum Inversion Number
 * Link: http://acm.hdu.edu.cn/showproblem.php?pid=1394
 * Tag: Binary Indexed Tree
 * */

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <algorithm>

using namespace std;

#define N 5010


struct Node {
    int val;
    int pos;
};

Node a[N];
int n, b[N], c[N];

int lowbit(int i) {
    return i & (-i);
}

int add(int i, int v) {
    while(i <= n) {
        c[i] += v;
        i += lowbit(i);
    }
}

int sum(int i) {
    int ret = 0;
    while (i > 0) {
        ret += c[i];
        i -= lowbit(i);
    }
    return ret;
}

bool lessFunc(const Node& lhs, const Node& rhs) {
    return lhs.val < rhs.val;
}

int main() {
    while(cin >> n)  {
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++) {
            cin >> a[i].val;
            a[i].pos = i;
        }
        sort (a+1, a+1+n, lessFunc);
        for (int i = 1; i <= n; i++) {
            b[a[i].pos] = i;
        }

        int ans  = 0;
        for (int i = 1; i <= n; i++) {
            add(b[i], 1);
            ans += i-sum(b[i]);
        }
        int res = ans;
        for (int i = 1; i < n; i++) {
            res += n -  b[i] - b[i] + 1;
            ans = min(res, ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
