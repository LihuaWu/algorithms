//Tag: FloodFill Search

#include <stdio.h>

#include <iostream>

using namespace std;

#define N 19

int b[N][N];

int d[4][2] = {{-1, 1}, {0, 1}, {1, 1}, {1, 0},};

int t;

bool ok(int x, int y) {
    int c = b[x][y];
    for (int i = 0; i < 4; i++) {
        bool isok = true;
        int newx = x, newy = y;
        for (int j = 0; j < 4; j++) {
            newx += d[i][0], newy += d[i][1];
            if (newx < 0 || newx >= 19 || newy < 0 || newy >= 19) {
                isok = false;
                break;
            }
            if (b[newx][newy] != c) {
                isok = false;
                break;
            }
        }
        if (!isok) continue;
        if (b[x-d[i][0]][y-d[i][1]] == c || b[newx+d[i][0]][newy+d[i][1]] == c) continue;
        printf("%d\n%d %d\n", c, x+1, y+1);
        return true;
    }
    return false;
}

int main () {
    cin >> t;
    for (; t > 0; --t) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> b[i][j];
            }
        }
        bool isok = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(b[i][j] == 0) continue;
                if (ok(i, j)) {
                    isok = true;
                    break;
                }
            }
        }
        if (!isok) {
            cout << "0\n";
        }
    }
    return 0;
}
