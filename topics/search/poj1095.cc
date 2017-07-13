//Tag: dfs catalan

#include <stdio.h>
#include <stdint.h>

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define N 300

const int64_t INF =33500000100;

int64_t k[N];
int n, size;

void dfs(int n, int idx) {
//    printf("%d node of %dth order\n", n, idx);
    int64_t p = 0;
    int left = 0;
    for (int i = 0; i < n; i++) {
        p += k[i] * k[n-1-i];
        if (p > idx) {
            left = i;
            break;
        }
    }
    int right = n-1-left;
    int newpos = idx-(p-k[left]*k[n-1-left]);
    if (left > 0) {
        printf("(");
        dfs(left, newpos/k[right]);
        printf(")");
    }
    printf("X");
    if (right>0) {
        printf("(");
        dfs(right, newpos%k[right]);
        printf(")");
    }
}

int main() {
    k[0] = 1;
    size = 1;
    for (int i = 0; i < N ; i++, size++) {
        k[i+1]= 2*(2*i+1)*k[i]/(i+2);
        if(k[i+1] > INF || k[i+1] < 0) { break; }
//        printf("%ld\n", k[i+1]);
    }

    while(true) {
        cin >> n;
        if (n == 0) break;
        int idx = 0;
        int64_t p = 0;
        for (int i = 0; i < size; i++) {
            p+= k[i];
            if (p > n) {
                idx = i;
                break;
            }
        }
//        printf("idx=%d size=%d\n", idx, size);
        dfs(idx, n-p+k[idx]);
        printf("\n");
    }
    return 0;
}
