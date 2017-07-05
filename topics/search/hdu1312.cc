// Tag: FloodFill

#include <stdio.h>

#include <iostream>
#include <algorithm>

using namespace std;

int w,h;


int d[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0},};

#define N 25
char rec[N][N];
bool vis[N][N];
int ret;

void dfs(int x, int y) {
    if (x < 0 || x >= h || y < 0 || y >= w) { return ; }
    if (rec[x][y] == '#') { return ;}
    ret++;
    for (int i = 0; i < 4; i++) {
        int newx = x+d[i][0];
        int newy = y+d[i][1];
        if (vis[newx][newy]) continue;
        vis[newx][newy] = true;
        dfs(newx, newy);
    }
}

int main() {
    while(true) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;
//        printf("w=%d h=%d\n", w, h);
        int x = -1, y = -1;
        ret = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> rec[i][j];
                vis[i][j] = false; // initialization
                if (rec[i][j] == '@') {
                    x = i;
                    y = j;
                }
            }
        }
        vis[x][y] = true;
        dfs(x, y); 
        cout << ret << "\n";
    }
    return 0;
}
