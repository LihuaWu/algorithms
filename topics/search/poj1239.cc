#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define N 100
#define MAX 99999999

string s;
int check[N], res[N];
int ans;

void dfs(int x, int prev, int p, int pidx) {
    int cur = prev*10+(s[x]-'0');
    if (x == s.size()-1) {
        if (cur < p) return;
        if (ans > cur) {
            ans = cur;
            for (int i = 0; i < s.size()-1; i++) {
                res[i] = check[i];
            }
        } else if (ans == cur) {
            bool flag = false;
            for (int i = 0; i < s.size()-1; i++) {
                if (res[i] > check[i]) {
                    flag = true;
                    break;
                }
            }
            for (int i = 0; i < s.size()-1; i++) {
                res[i] = check[i];
            }
        }
        return;
    }
    if (cur > p) {
        check[x] = 1;
        dfs(x+1, 0, cur, x);
    }
    check[x] = 0;
    dfs(x+1, cur, p, pidx);
}

void solve() {
    dfs(0, 0, 0, -1);
    for (int i = 0; i < s.size(); i++) {
        printf("%c", s[i]);
        if (i != s.size()-1 && res[i]) printf(",");
    }
    printf("\n");
}

int main () {
    while(true) {
        cin >> s;
        ::memset(check, 0, sizeof(check));
        ::memset(res, 0, sizeof(res));
        ans = MAX;
        if (s.size() == 1 && s[0] == '0') break;
        solve();
    }
    return 0;
}
