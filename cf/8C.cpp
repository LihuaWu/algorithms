/*
 * C. Looking for Order
 * time limit per test4 seconds
 * memory limit per test512 megabytes
 * inputstandard input
 * outputstandard output
 * Girl Lena likes it when everything is in order, and looks for order everywhere. Once she was getting ready for the University and noticed that the room was in a mess — all the objects from her handbag were thrown about the room. Of course, she wanted to put them back into her handbag. The problem is that the girl cannot carry more than two objects at a time, and cannot move the handbag. Also, if he has taken an object, she cannot put it anywhere except her handbag — her inherent sense of order does not let her do so.
 *
 * You are given the coordinates of the handbag and the coordinates of the objects in some Сartesian coordinate system. It is known that the girl covers the distance between any two objects in the time equal to the squared length of the segment between the points of the objects. It is also known that initially the coordinates of the girl and the handbag are the same. You are asked to find such an order of actions, that the girl can put all the objects back into her handbag in a minimum time period.
 *
 * Input
 * The first line of the input file contains the handbag's coordinates xs, ys. The second line contains number n (1 ≤ n ≤ 24) — the amount of objects the girl has. The following n lines contain the objects' coordinates. All the coordinates do not exceed 100 in absolute value. All the given positions are different. All the numbers are integer.
 *
 * Output
 * In the first line output the only number — the minimum time the girl needs to put the objects into her handbag.
 *
 * In the second line output the possible optimum way for Lena. Each object in the input is described by its index number (from 1 to n), the handbag's point is described by number 0. The path should start and end in the handbag's point. If there are several optimal paths, print any of them.
 *
 * Examples
 * input
 * 0 0
 * 2
 * 1 1
 * -1 1
 *  output
 *  8
 *  0 1 2 0 
 *  input
 *  1 1
 *  3
 *  4 3
 *  3 4
 *  0 0
 *  output
 *  32
 *  0 1 2 0 3 0 
 * */

#include <math.h>
#include <string.h>
#include <stdio.h>

#include <iostream>
#include <limits>

using namespace std;

int n;

int x[25], y[25], dis[25][25], path[(1<<24)-1], dp[1<<24];

int dist(int x, int y) {
    return x * x + y * y;
}


int main() {
    cin >> x[0] >> y[0] >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dis[i][j] = dist(x[j]-x[i], y[j]-y[i]);
//            printf("dis[%d][%d]=%d\n", i, j, dis[i][j]);
        }
    }


    dp[0] = 0;

    int t = numeric_limits<int>::max();
    for (int i = 1; i < (1<<24)-1; i++) {
        dp[i] = t/2;
    }
    for (int i = 0; i < (1<<n)-1; i++) {
        if (dp[i] < t) {
            for (int j = 0; j < n; j++) {
                if (!(i>>j&1)) {
                   for (int k = j; k < n; k++) {
                       if (!(i>>k&1)) {
                           int p = i | 1<< j | 1 << k;
                           int v = dp[i] + dis[0][j+1] + dis[j+1][k+1] + dis[k+1][0];
                           if (dp[p] > v) {
                               dp[p] = v;
                               path[p] = i;
                           }
                       }
                   } 
//                   break;
                }
            }
        }
    }
    cout << dp[(1<<n)-1] << "\n";
    cout << 0 << " ";

    for (int i = (1<<n)-1; i; i = path[i]) {
        for (int j = i^path[i]; j; j -=j&(-j)) {
            cout << int(log(j&(-j))/log(2)+1) << " ";
        }
        cout << 0 << " ";
    }
    return 0;
}
