//Tag: search

#include <stdio.h>
#include <stdint.h>

#include <iostream>

using namespace std;


#define N  17

int n;

char op[N]={'0',};

int total;

void dfs(int64_t sum, int cur, int64_t prev) {
    if (cur == n+1) { 
        if (sum != 0) return; 
        ++total;
        if (total > 20) return;
        printf("1 ");
        for (int i = 2; i <= n; i++) {
            printf("%c %d ", op[i], i);
        }
        printf("\n");
        return;
    }
    op[cur] = '+';
    dfs(sum+cur, cur+1, cur);
    op[cur] = '-';
    dfs(sum-cur, cur+1, -cur);
    op[cur] = '.';
    int digit = 10;
    if(cur >= 10) {
        digit = 100;
    }
    int64_t newdigit = 0;
    if(prev < 0) {
        newdigit = prev*digit-cur;
    } else {
        newdigit = prev*digit+cur;
    }
    dfs(sum-prev+newdigit, cur+1, newdigit);
}


int main () {
    cin >> n;
    dfs(1, 2, 1);
    printf("%d\n", total);

    return 0;
}
