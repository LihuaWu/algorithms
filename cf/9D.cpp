/*
 * D. How many trees?
 * time limit per test1 second
 * memory limit per test64 megabytes
 * inputstandard input
 * outputstandard output
 * In one very old text file there was written Great Wisdom. This Wisdom was so Great that nobody could decipher it, even Phong — the oldest among the inhabitants of Mainframe. But still he managed to get some information from there. For example, he managed to learn that User launches games for pleasure — and then terrible Game Cubes fall down on the city, bringing death to those modules, who cannot win the game...
 *
 * For sure, as guard Bob appeared in Mainframe many modules stopped fearing Game Cubes. Because Bob (as he is alive yet) has never been defeated by User, and he always meddles with Game Cubes, because he is programmed to this.
 *
 * However, unpleasant situations can happen, when a Game Cube falls down on Lost Angles. Because there lives a nasty virus — Hexadecimal, who is... mmm... very strange. And she likes to play very much. So, willy-nilly, Bob has to play with her first, and then with User.
 *
 * This time Hexadecimal invented the following entertainment: Bob has to leap over binary search trees with n nodes. We should remind you that a binary search tree is a binary tree, each node has a distinct key, for each node the following is true: the left sub-tree of a node contains only nodes with keys less than the node's key, the right sub-tree of a node contains only nodes with keys greater than the node's key. All the keys are different positive integer numbers from 1 to n. Each node of such a tree can have up to two children, or have no children at all (in the case when a node is a leaf).
 *
 * In Hexadecimal's game all the trees are different, but the height of each is not lower than h. In this problem «height» stands for the maximum amount of nodes on the way from the root to the remotest leaf, the root node and the leaf itself included. When Bob leaps over a tree, it disappears. Bob gets the access to a Cube, when there are no trees left. He knows how many trees he will have to leap over in the worst case. And you?
 *
 * Input
 * The input data contains two space-separated positive integer numbers n and h (n ≤ 35, h ≤ n).
 *
 * Output
 * Output one number — the answer to the problem. It is guaranteed that it does not exceed 9·1018.
 *
 * Examples
 * input
 * 3 2
 * output
 * 5
 * input
 * 3 3
 * output
 * 4
 * */

#include <stdint.h>

#include <iostream>

using namespace std;

int64_t cart_array[36];

//catalan数
int64_t cart(int n) {
    if (cart_array[n] != 0) return cart_array[n];
    if (n == 0 || n == 1) {
        cart_array[n] = 1;
        return cart_array[n];
    } 
    
    int64_t res = 0;
    for (int i = 0; i < n; i++) {
        res += cart(i)*cart(n-1-i);
    }
    cart_array[n] = res;
    return res;
}


int64_t dp_array[36][36];

int64_t dp(int i, int j) {
    if (dp_array[i][j] != 0) return dp_array[i][j];

    int64_t& res = dp_array[i][j];
    if (i == 0) {
        res = 1;
    } else if (j == 1) {
        res = 0;
    }else if (i < j) {
        res = cart(i);
    } else {
        for (int k = 0; k < i; k++) {
            res += dp(k, j-1) * dp(i-1-k, j-1);
        }
    }
    return res;
}


int main() {
    int n, k;
    cin >> n >> k;
    int64_t a = cart(n);
    int64_t b = dp(n, k);
    cout << (a-b) << "\n";
    return 0;
}
