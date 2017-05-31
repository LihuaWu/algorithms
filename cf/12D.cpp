/*
 * D. Ball
 * time limit per test2 seconds
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
 * N ladies attend the ball in the King's palace. Every lady can be described with three values: beauty, intellect and richness. King's Master of Ceremonies knows that ladies are very special creatures. If some lady understands that there is other lady at the ball which is more beautiful, smarter and more rich, she can jump out of the window. He knows values of all ladies and wants to find out how many probable self-murderers will be on the ball. Lets denote beauty of the i-th lady by Bi, her intellect by Ii and her richness by Ri. Then i-th lady is a probable self-murderer if there is some j-th lady that Bi < Bj, Ii < Ij, Ri < Rj. Find the number of probable self-murderers.
 *
 * Input
 * The first line contains one integer N (1 ≤ N ≤ 500000). The second line contains N integer numbers Bi, separated by single spaces. The third and the fourth lines contain sequences Ii and Ri in the same format. It is guaranteed that 0 ≤ Bi, Ii, Ri ≤ 109.
 *
 * Output
 * Output the answer to the problem.
 *
 * Examples
 * input
 * 3
 * 1 4 2
 * 4 3 2
 * 2 5 3
 * output
 * 1
 * */

#include <stdio.h>

#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

#define N 500000


int n, ret;

typedef  pair<int, pair<int, int> > P;

P rec[N];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) { cin >> rec[i].first; }
    for (int i = 0; i < n; i++) { cin >> rec[i].second.first; }
    for (int i = 0; i < n; i++) { cin >> rec[i].second.second; }

    sort(rec, rec+n); 

    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (rec[i].first < rec[j].first &&
                    rec[i].second.first < rec[j].second.first &&
                    rec[i].second.second < rec[j].second.second) {
                ++ret;
//                printf("i=%d\t", i);
                break;
            }
        }
    }
    cout << ret;
    return 0;
}

