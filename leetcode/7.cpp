/*
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * click to show spoilers.
 *
 * Have you thought about this?
 * Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
 *
 * If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 *
 * Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
 *
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 *
 * Note:
 * The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
 * int reverse(int x)
 * */

#include "common.h"

int reverse(int x) {
    int64_t ret = 0;
    while (x) {
        int remain = x % 10;
        x /= 10;
        ret = ret * 10 +remain;
        if (ret > std::numeric_limits<int>::max() ||ret < std::numeric_limits<int>::min() ) {
            return 0;
        }
    }
    return ret;

}

int main() {
    struct Case {
        int x;
        int expect;
    } cases[] = {
        {-123, -321},
        {123, 321},
        {0, 0},
        {std::numeric_limits<int>::min(), 0},
        {1000000003, 0},
    };

    int size = sizeof(cases)/sizeof(Case);

    bool ok = true;
    for (int i = 0; i < size; i++) {
        int result = reverse(cases[i].x);
        if (cases[i].expect != result) {
            ok = false;
            cerr << "Case " << i << " Failed. expect: " <<cases[i].expect << " actual output: " << result << "\n";
        }
    }
    if (ok) {
        cout << "ALL PASSED.";
    }
    return 0;
}
