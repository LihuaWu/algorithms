/*
 * E. Greedy Change
 * time limit per test2 seconds
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
 * Billy investigates the question of applying greedy algorithm to different spheres of life. At the moment he is studying the application of greedy algorithm to the problem about change. There is an amount of n coins of different face values, and the coins of each value are not limited in number. The task is to collect the sum x with the minimum amount of coins. Greedy algorithm with each its step takes the coin of the highest face value, not exceeding x. Obviously, if among the coins' face values exists the face value 1, any sum x can be collected with the help of greedy algorithm. However, greedy algorithm does not always give the optimal representation of the sum, i.e. the representation with the minimum amount of coins. For example, if there are face values {1, 3, 4} and it is asked to collect the sum 6, greedy algorithm will represent the sum as 4 + 1 + 1, while the optimal representation is 3 + 3, containing one coin less. By the given set of face values find out if there exist such a sum x that greedy algorithm will collect in a non-optimal way. If such a sum exists, find out the smallest of these sums.
 *
 * Input
 * The first line contains an integer n (1 ≤ n ≤ 400) — the amount of the coins' face values. The second line contains n integers ai (1 ≤ ai ≤ 109), describing the face values. It is guaranteed that a1 > a2 > ... > an and an = 1.
 *
 * Output
 * If greedy algorithm collects any sum in an optimal way, output -1. Otherwise output the smallest sum that greedy algorithm collects in a non-optimal way.
 *
 * Examples
 * input
 * 5
 * 25 10 5 2 1
 * output
 * -1
 *  input
 *  3
 *  4 3 1
 *  output
 *  6
 * */

#include <iostream>

using namespace std;

int n;

int w[410];
int ret = -1;

int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int p = w[i]-1, c = 1, t = w[j];
            for (int k = i+1; k <= j; k++) {
                c += p/w[k];
                t += p/w[k]*w[k];
                p %= w[k];
            }
            p = t;
            for (int k = 1; k <= n; k++) {
                c -= p/w[k];
                p %= w[k];
            }

            if (c < 0 && (ret < 0 ||ret > t)) {
                ret = t;
            }
        }
    }
    cout << ret;
    return 0;
}

