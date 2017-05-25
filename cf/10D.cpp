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

using namespace std;

int n, m;

int dp[510][510];

int s[510], t[510]; 


int dodp(int i, int j) {
    if (i == 0 || j == 0) {
        dp[i][j] = 0;
        return dp[i][j];
    }

    if (dp[i][j] != -1) return dp[i][j]; 
    else {
        if (s[i] == t[j]) {
            int p = i, q = j;
            for (; p > 0; p--) {
                if (s[p] < s[i]) break; 
            }
            for (; q > 0; q--) {
                if (t[q] < t[j]) break;
            }
            dp[i][j] = max(dodp(p,q)+1, max(dodp(i-1,j), dodp(i, j-1)));

        } else {
            dp[i][j] = max(dodp(i-1,j), dodp(i, j-1));
        }
        return dp[i][j];
    }
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

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = -1;
        }
    }
    cout << dodp(n, m);
    return 0;
}
