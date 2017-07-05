#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define N 10100

int par[N];

int n;
int l, r;
vector<int> lv, rv;


int main () {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        ::memset(par, 0, sizeof par);
        lv.clear();
        rv.clear();
        cin >> n;
        int p, c;
        for (int j = 0; j < n-1; j++) {
            cin >> p >> c;
            par[c] = p;
        }
        cin >> l >> r;
        int li = l, ri = r;
        while(li != 0) {
            lv.push_back(li);
            li = par[li];
        }
        while(ri != 0) {
            rv.push_back(ri);
            ri = par[ri];
        }

        reverse(lv.begin(), lv.end());
        reverse(rv.begin(), rv.end());
        int prefix = 0;
        for (size_t i = 0; i < lv.size() && i < rv.size(); i++) {
            if (lv[i] == rv[i]) {
                prefix = i;
            } else {
                break;
            }
        }
        printf("%d\n", lv[prefix]);
    } 
    return 0;
}
