//Tag search
//链接: http://poj.org/problem?id=1103
//题意:
//找出由"/"符号和"\"符号构成的图中闭环的个数及最大的环所占面积
//思路: 构图 + FloodFill
//本题较难，也比较有意思
// 构图时 使用 3 x 3的矩阵代表符号 "/" "\"和"X", 
// (注意: 在构图时要包括图的四周)
// 构图完成后，先对边缘进行一次dfs后，只剩下环的边缘尚未被访问 
// 针对环的边缘做dfs, 即可得到环的长度。
// 通过在初始时对每个点设置初始value值这样的小技巧，将环的边缘长度转化为环所覆盖的面积

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define N 300

int A[N][N],  vis[N][N];
double value[N][N];

int w, h, total, cnt;
double ml, res;

char c;

int L[][3] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
};

int R[][3] = {
    {0, 0, 1},
    {0, 1, 0},
    {1, 0, 0},
};

int X[][3] = {
    {1, 0, 1},
    {0, 1, 0},
    {1, 0, 1},
};

int d[][2] = {
    {0,  1},
    {0, -1},
    {1,  0},
    {-1, 0},
};


void show() {
    printf("this is delim\n");
    for (int i = 0; i <= 3*h+1; i++) {
        for (int j = 0; j<= 3*w+1; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

void showvis() {
    printf("this is delim for vis\n");
    for (int i = 0; i <= 3*h+1; i++) {
        for (int j = 0; j <= 3*w+1; j++) {
            printf("%d ", vis[i][j]);
        }
        printf("\n");
    }
}

void showvalue() {
    printf("this is delim for value\n");
    for (int i = 0; i <= 3*h+1; i++) {
        for (int j = 0; j <= 3*w+1; j++) {
            printf("%.1f ", value[i][j]);
        }
        printf("\n");
    }
}

void paint(int x, int y, char c) {
    int (*p)[3];   
    if (c == '\\') { p = L;}
    else if (c == '/') { p = R;}
    else if (c == 'x') { p = X; }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A[3*x+i+1][3*y+j+1] = *(*(p+i)+j);
        };
    }
}

void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int newx = x + d[i][0];
        int newy = y + d[i][1];
        if (newx < 0 || newx > 3*h+1 || newy < 0 || newy > 3*w+1) continue;
        if(vis[newx][newy]) continue;
        if (A[newx][newy] == 1) continue;
        vis[newx][newy] = 1;
        res += value[newx][newy];
        dfs(newx, newy);
    }
}

void solve() {
    ::memset(vis, 0, sizeof(vis));
    vis[0][0] = 1;
//    show();
 //   showvis();
    dfs(0, 0);
  //  showvis();
    total = ml = res = 0;
    for (int i = 0; i < 3*h; i++) {
        for (int j = 0; j < 3*w; j++) {
            if (vis[i][j] == 0 && A[i][j] == 0) {
                res = value[i][j];
                //show();
                //showvis();
                //showvalue();
                vis[i][j] = 1;
                total++;
                dfs(i, j);
                //showvis();
                ml=max(ml, res);
            }
        }
    }
}

int main () {
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 80; j++) {
            paint(i, j, 'x');
        }
    }
    //show();

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (A[i][j] == 0) {
                value[i][j] = 0.5;
            }
        }
    }
    while(true) {
        ::memset(A, 0, sizeof(A));
        cin >> w >> h;
        if (h == 0 && w == 0)
            break;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> c;
                paint(i, j, c);
            }
        }
        solve();
        printf("Maze #%d:\n", ++cnt);
        if (total > 0) {
            printf("%d Cycles; the longest has length %.0f.\n", total, ml);
        } else {
            printf("There are no cycles.\n");
        }
        printf("\n");
    }
    return 0;
}
