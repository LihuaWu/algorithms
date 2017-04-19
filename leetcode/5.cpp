/*
 * 5. Longest Palindromic Substring Add to List
 * DescriptionHintsSubmissionsSolutions
 * Total Accepted: 191410
 * Total Submissions: 764371
 * Difficulty: Medium
 * Contributor: LeetCode
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 * Example:
 *
 * Input: "babad"
 *
 * Output: "bab"
 *
 * Note: "aba" is also a valid answer.
 * Example:
 *
 * Input: "cbbd"
 *
 * Output: "bb"
 * */

#include "common.h"

vector<char> A;
vector<int >p;
int n;
int idx;
int maxlen = 1;

string Manachar() {
    int left_bound = 1, right_bound = 1;
    int idx = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = max(1, min(p[2*left_bound-i], right_bound-i));
//        if (i == 8) printf("left_bound=%d 2*p[left_bound]-i=%d, right_bound-i=%d p[%d]=%d\n", left_bound, 2*p[left_bound]-i, right_bound-i, i, p[i]);
        while(i+p[i] <= n && i-p[i] >= 1 && A[i+p[i]] == A[i-p[i]]) p[i]++;
        if (i+p[i]-1 > right_bound) {
            right_bound = i+p[i]-1;
            left_bound = i;
        }
        if (2 * p[i] -1 > maxlen) {
            maxlen = 2*p[i]-1;
            idx = i;
        }
    }

    for (int i = 1; i <= n; i++) {
//        printf("p[%d]=%d\n", i, p[i]);
    }
 //   printf("maxlen=%d\n", maxlen);
    ostringstream oss;
    int start = idx-p[idx]+1;
    for (int i = 0; i < maxlen; i++) {
        if (A[start+i] != '#') {
            oss << A[start+i];
        }
    }
    return oss.str();
}

int main() {
    string s;
    cin >> s;
    A.resize(s.size()*2+10);
    p.resize(s.size()*2+10);
    for (int i = 0; i < s.size(); i++) {
        A[++n] = s[i];
        A[++n] = '#';
    }
    --n;
    cout << Manachar();


    return 0;
}
