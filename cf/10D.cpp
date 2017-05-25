/*
 * D. LCIS
 * time limit per test1 second
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
 * This problem differs from one which was on the online contest.
 *
 * The sequence a1, a2, ..., an is called increasing, if ai < ai + 1 for i < n.
 *
 * The sequence s1, s2, ..., sk is called the subsequence of the sequence a1, a2, ..., an, if there exist such a set of indexes 1 ≤ i1 < i2 < ... < ik ≤ n that aij = sj. In other words, the sequence s can be derived from the sequence a by crossing out some elements.
 *
 * You are given two sequences of integer numbers. You are to find their longest common increasing subsequence, i.e. an increasing sequence of maximum length that is the subsequence of both sequences.
 *
 * Input
 * The first line contains an integer n (1 ≤ n ≤ 500) — the length of the first sequence. The second line contains n space-separated integers from the range [0, 109] — elements of the first sequence. The third line contains an integer m (1 ≤ m ≤ 500) — the length of the second sequence. The fourth line contains m space-separated integers from the range [0, 109] — elements of the second sequence.
 *
 * Output
 * In the first line output k — the length of the longest common increasing subsequence. In the second line output the subsequence itself. Separate the elements with a space. If there are several solutions, output any.
 *
 * Examples
 * input
 * 7
 * 2 3 1 6 5 4 6
 * 4
 * 1 3 5 6
 * output
 * 3
 * 3 5 6 
 * input
 * 5
 * 1 2 0 2 1
 * 3
 * 1 0 1
 * output
 * 2
 * 0 1 
 * */

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m, k;

int s[510], t[510], par[510], dp[510];


void print(int k) {
    if (!k) return;
    print(par[k]);
    cout << t[k] << " ";
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    cin >> m;
    for (int j = 1; j <= m; j++) {
        cin >> t[j];
    }

    for (int i = 1; i <= n; i++, k = 0) {
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) {
                dp[j] = dp[k] + 1;
                par[j]= k;
            } else if (s[i] > t[j] && dp[j] > dp[k]) {
                k = j;
            }
        }
    }

    k = 0;
    int max = 0;
    for (int i = 1; i <= m; i++) {
        if (dp[i] > max) {
            max = dp[i], k = i;
        }

    }
    cout << max << "\n";
    print(k);
    return 0;
}
