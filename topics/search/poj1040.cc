#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int capcity, stops, orders, res;

#define N 22

int start[N], end[N], pass[N], earn[N];
int p[8];

void dfs(int x, int sum) {
    if (x == orders) {
        res = ::max(res, sum);
        return;
    }
    bool isok = true;

    for (int i = start[x]+1; i <= end[x]; i++) {
        if (p[i] + pass[x] > capcity) {
            isok = false;
            break;
        }
    }
    if(isok) {
        for (int i = start[x]+1; i <= end[x]; i++) {
            p[i] += pass[x];
        }
        dfs(x+1, sum + earn[x]);
        for (int i = start[x]+1; i <= end[x]; i++) {
            p[i] -= pass[x];
        }
    }
    dfs(x+1, sum);
}



int main () {
    while(1) {
        ::memset(start, 0, sizeof(start));
        ::memset(end, 0, sizeof(end));
        ::memset(pass, 0, sizeof(pass));
        ::memset(p, 0, sizeof(p));
        res = 0;

        cin >> capcity >> stops >> orders;
        if (capcity == 0 && stops == 0 && orders == 0) break;
        for (int i = 0; i < orders; i++) {
            cin >> start[i] >> end[i] >> pass[i];
            earn[i] = (end[i]-start[i]) * pass[i];
        }
        dfs(0, 0);
        printf("%d\n", res);
    }
    return 0;
}
