//Tag search cycle detection

#include <stdio.h>

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define N  11

char b[N][N];
bool vis[N][N];
int r, c, s, steps, cycle_steps, is_cycle;

int move[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, };

void onestep(int x, int y, int& newx, int& newy) {
    char c = b[x][y];
    if (c == 'N') {
        newx = x + move[0][0];
        newy = y + move[0][1];
    } else if (c == 'S') {
        newx = x + move[1][0];
        newy = y + move[1][1];
    } else if (c == 'W') {
        newx = x + move[2][0];
        newy = y + move[2][1];
    } else if (c == 'E') {
        newx = x + move[3][0];
        newy = y + move[3][1];
    } else {
        printf("invalid move!\n");
    }
}


bool is_ok(int x, int y) {
    return (x >= 1 && x <= r && y >=1 && y <= c);
}


void traverse(int x, int y) {
    while(is_ok(x, y)) {
        if (vis[x][y]) is_cycle = true;
        if (is_cycle && !cycle_steps) {
            int curx = x, cury = y;
            int nextx, nexty;
            onestep(curx, cury, nextx, nexty);
            cycle_steps++;
            while(nextx != x || nexty != y) {
                cycle_steps++;
                curx = nextx; cury = nexty;
                onestep(curx, cury, nextx, nexty);
            }
            break;
        }
        vis[x][y] = true;
        steps++;
        int p,q;
        onestep(x, y, p, q);
        x = p;
        y = q;
    }
}


int main () {
    while(1) {
        cin >> r >> c >> s;
        if (!r && !c && !s) break;
        steps = cycle_steps = 0;
        is_cycle = false;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> b[i][j];
                vis[i][j] = false;
            }
        }

        traverse(1, s);
        if (!is_cycle) {
            printf("%d step(s) to exit\n", steps);
        } else {
            printf("%d step(s) before a loop of %d step(s)\n", steps-cycle_steps, cycle_steps);
        }
    }
    return 0;
}
