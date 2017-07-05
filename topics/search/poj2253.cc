#include <math.h>
#include <stdio.h>

#include <iostream>

using namespace std;


#define N 210

int n;
int a[N][2];
double dis[N][N];
double res[N];
bool v[N];

int main() {
    int cnt = 1;
    while (1) {
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            cin >> a[i][0] >> a[i][1];
        }

        for (int i = 0; i < n; i++) {
            dis[i][i] = 0;
            for (int j = i+1; j < n; j++) {
                int diff_x = a[i][0] - a[j][0];
                int diff_y = a[i][1] - a[j][1];
                dis[i][j] = dis[j][i] = sqrt(diff_x * diff_x + diff_y * diff_y);
            }
        }


        for (int i = 0; i < n; i++) {
            res[i] = dis[0][i];
            v[i] = false;
        }

        v[0] = true;
        for (int i = 0; i < n-1; i++) {
            double minV = 99999999.0;
            int p = 0;

            for (int j = 0; j < n; j++) {
                if (!v[j] && res[j] < minV) {
                    minV = res[j];
                    p = j;
                }
            }
            v[p] = true;

            for (int k = 0; k < n; k++) {
                if (!v[k]) {
                    double maxV = max(res[p], dis[p][k]);
                    res[k] = min(res[k], maxV);
                }
            }
        }
        printf("Scenario #%d\nFrog Distance = %.3f\n\n", cnt++, res[1]);
    }
    return 0;
}
