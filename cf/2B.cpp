/*
 * B. The least round way
 * time limit per test2 seconds
 * memory limit per test64 megabytes
 * inputstandard input
 * outputstandard output
 * There is a square matrix n × n, consisting of non-negative integer numbers. You should find such a way on it that
 *
 * starts in the upper left cell of the matrix;
 * each following cell is to the right or down from the current cell;
 * the way ends in the bottom right cell.
 * Moreover, if we multiply together all the numbers along the way, the result should be the least "round". In other words, it should end in the least possible number of zeros.
 *
 * Input
 * The first line contains an integer number n (2 ≤ n ≤ 1000), n is the size of the matrix. Then follow n lines containing the matrix elements (non-negative integer numbers not exceeding 109).
 *
 * Output
 * In the first line print the least number of trailing zeros. In the second line print the correspondent way itself.
 *
 * Examples
 * input
 * 3
 * 1 2 3
 * 4 5 6
 * 7 8 9
 * output
 * 0
 * DDRR
 * */

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int f[1001][1001][2]; //calculate mid result
bool g[1001][1001][2]; // store path 

int n, i, j, k;

int x = 0;

void print(int x, int y) {
    if (x == 1 && y == 1) return;
    if (g[x][y][k]) {
        print(x-1, y); 
        putchar('D');
    } else {
        print(x, y-1);
        putchar('R');
    }
}

int main() {
    scanf("%d", &n);

    for (i = 2; i <= n; i++) {
        f[0][i][0] = 9999;
        f[0][i][1] = 9999;
        f[i][0][0] = 9999;
        f[i][0][1] = 9999;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &k);
            if (k == 0) { x = i; }
            else {
                for (; (k&1) == 0; k >>= 1) {
                    f[i][j][0]++;
                }
                for (; (k%5) == 0; k /= 5) {
                    f[i][j][1]++;
                }
            }
            for (k = 0; k < 2; k++) {
                g[i][j][k] = (f[i-1][j][k] < f[i][j-1][k]);
                f[i][j][k] += (g[i][j][k] ? f[i-1][j][k] : f[i][j-1][k]);
            }
        }
    }

    k = (f[n][n][1] < f[n][n][0]);
    if (x > 0 && f[n][n][k] > 1) {
        puts("1");
        for (i = 2; i <= x; i++) putchar('D');
        for (i = 2; i <= n; i++) putchar('R');
        for (i = x + 1; i <= n; i++) putchar('D');
    } else {
        printf("%d\n", f[n][n][k]);
        print(n, n);
    }
    return 0;
}
