//Tag: search disjoint set with weight
//tips: 
//1. 带权并查集
//2. 当输入数据规模较大时，可以进行离散化，选用新的下标代替原先的数据段
//3. 当算法正确，但是TLE时，可查看输入数据规模限制是否为百万级别以上，如是的话，使用scanf取代cin,可以解决问题。



#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define N 20010

int n, m, ans, cnt;

int s[N], e[N], c[N], fa[N], rank[N], x[N];

int find(int v) {
    if (fa[v] == v) return v;
    else {
        int temp = fa[v];
        fa[v] = find(fa[v]);
        rank[v] = rank[v] ^ rank[temp];
        return fa[v];
    }
}

bool check(int u, int v, int r) {
    int fu = find(u);
    int fv = find(v);
   // printf("u=%d fu=%d v=%d fv=%d\n", u, fu, v, fv);
    for (int i = 1; i <= cnt; i++) {
    //    printf("fa[%d]=%d rank[%d]=%d\n",i, fa[i], i, rank[i]);
    }

    if (fu == fv) {
        return (rank[u]^rank[v]) == r;
    }
    return true; 
}

void merge(int u, int v, int r) {
    int fu = find(u);
    int fv = find(v);
    if (fu > fv) {
        fa[fu] = fv;
        rank[fu] = rank[u]^rank[v]^r;
    } else {
        fa[fv] = fu;
        rank[fv] = rank[u]^rank[v]^r;
    }
}

int bs(int start, int end, int item) {
    int l = start;
    int r = end;
    while(l < r) {
        int mid = (l+r) >> 1;
        if (x[mid] == item) return mid;
        else if (x[mid] < item) l = mid+1;
        else r = mid;
    }
    return -1;
}


int main () {
    cin >> n >> m;
    string op;
    cnt = 0;
    ans = 0;
    ::memset(c, 0, sizeof(c));
    ::memset(x, 0, sizeof(x));

    for (int i = 0; i < m; i++) {
        cin >> s[i] >> e[i] >> op;
        x[cnt++] = s[i];
        x[cnt++] = e[i]+1;
        if (op[0] == 'o') c[i] = 1;
    }

    sort(x, x+cnt);
    cnt = unique(x, x+cnt)-x;

    for (int i = 0; i < N; i++) {
        fa[i] = i;
        rank[i] = 0;
    }
 //   for (int i = 0; i < cnt; i++) {
 //       printf("%d ", x[i]);
 //   }
 //   printf("\n");

    for (int i = 0; i < m; i++) {
        int u = bs(0, cnt, s[i]) + 1;
        int v = bs(0, cnt, e[i]+1) + 1;

//        printf("s=%d e=%d u=%d v=%d rel=%d\n",s[i], e[i]+1,  u, v, c[i]);
        if (!check(u, v, c[i])) {
            break; 
        } 
        merge(u, v, c[i]);
        ans++; 
    }
    printf("%d\n", ans);
    return 0;
}
