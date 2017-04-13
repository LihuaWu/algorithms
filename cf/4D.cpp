/*
 * D. Mysterious Present
 * time limit per test1 second
 * memory limit per test64 megabytes
 * inputstandard input
 * outputstandard output
 * Peter decided to wish happy birthday to his friend from Australia and send him a card. To make his present more mysterious, he decided to make a chain. Chain here is such a sequence of envelopes A = {a1,  a2,  ...,  an}, where the width and the height of the i-th envelope is strictly higher than the width and the height of the (i  -  1)-th envelope respectively. Chain size is the number of envelopes in the chain.
 *
 * Peter wants to make the chain of the maximum size from the envelopes he has, the chain should be such, that he'll be able to put a card into it. The card fits into the chain if its width and height is lower than the width and the height of the smallest envelope in the chain respectively. It's forbidden to turn the card and the envelopes.
 *
 * Peter has very many envelopes and very little time, this hard task is entrusted to you.
 *
 * Input
 * The first line contains integers n, w, h (1  ≤ n ≤ 5000, 1 ≤ w,  h  ≤ 106) — amount of envelopes Peter has, the card width and height respectively. Then there follow n lines, each of them contains two integer numbers wi and hi — width and height of the i-th envelope (1 ≤ wi,  hi ≤ 106).
 *
 * Output
 * In the first line print the maximum chain size. In the second line print the numbers of the envelopes (separated by space), forming the required chain, starting with the number of the smallest envelope. Remember, please, that the card should fit into the smallest envelope. If the chain of maximum size is not unique, print any of the answers.
 *
 * If the card does not fit into any of the envelopes, print number 0 in the single line.
 *
 * Examples
 * input
 * 2 1 1
 * 2 2
 * 2 2
 * output
 * 1
 * 1 
 * input
 * 3 3 3
 * 5 4
 * 12 11
 * 9 8
 * output
 * 3
 * 1 3 2 
 * */

#include <iostream>

using namespace std;

int n;
int h[5001], w[5001], d[5001], to[5001];

int dp(int v) {
    if (d[v]) return d[v];
    d[v] = 1;
    for (int i = 0; i <= n; i++) {
        if (w[i] > w[v] && h[i] > h[v]) {
            if (dp(i)+1 > d[v]) {
                to[v] = i;
                d[v] = d[i]+1;
            }
        }
    }
    return d[v];
}

int main() {
    cin >> n;
    for (int i = 0; i <= n; i++) {
        to[i] = -1;
        cin >> w[i] >> h[i];
    }
    dp(0);
    cout << --d[0] << "\n";
    for (int i = 0; to[i] != -1; i = to[i]) {
        cout << to[i] << " ";
    }
    return 0;
}
