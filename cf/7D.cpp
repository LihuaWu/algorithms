/*
 * D. Palindrome Degree
 * time limit per test1 second
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
 * String s of length n is called k-palindrome, if it is a palindrome itself, and its prefix and suffix of length  are (k - 1)-palindromes. By definition, any string (even empty) is 0-palindrome.
 *
 * Let's call the palindrome degree of string s such a maximum number k, for which s is k-palindrome. For example, "abaaba" has degree equals to 3.
 *
 * You are given a string. Your task is to find the sum of the palindrome degrees of all its prefixes.
 *
 * Input
 * The first line of the input data contains a non-empty string, consisting of Latin letters and digits. The length of the string does not exceed 5·106. The string is case-sensitive.
 *
 * Output
 * Output the only number — the sum of the polindrome degrees of all the string's prefixes.
 *
 * Examples
 * input
 * a2A
 * output
 * 1
 * input
 * abacaba
 * output
 * 6
 * */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define N 10000000
char A[N];
int n;

int p[N], Res[N];
int ans, right_bound, left_bound;

void Manachar() {
    right_bound = 1, left_bound = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = max(1, min(p[2*left_bound-i], right_bound-i));
        while (i - p[i] >= 1 && i + p[i] <= n && A[i+p[i]] == A[i-p[i]]) p[i]++;
        if (i+p[i]-1 > right_bound) { 
            right_bound = i+p[i]-1;
            left_bound = i;
        }
        if (i-p[i]+1 == 1) {
            if (i%2 == 0) {
                Res[i+p[i]] = Res[i]+1;
            } else {
                Res[i+p[i]] = Res[i-1]+1;
            }
            ans += Res[i+p[i]];
        }
    }
}

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        A[++n] = s[i];
        A[++n] = '#';
    }
    n--;
    Manachar();
    printf("%d", ans);

    return 0;
}
