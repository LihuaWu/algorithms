/*
 * 9. Palindrome Number Add to List
 * DescriptionSubmissionsSolutions
 * Total Accepted: 198782
 * Total Submissions: 574988
 * Difficulty: Easy
 * Contributor: LeetCode
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 * click to show spoilers.
 *
 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 *
 * If you are thinking of converting the integer to string, note the restriction of using extra space.
 *
 * You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
 *
 * Notes: reverse is never a problem. 
 *  1). if an integer is a palindrome, then the reverse it wouldn't cause overflow.
 *  2). if an integer is not a palindrome, we don't care whether it overflows or not.
 *
 * There is a more generic way of solving this problem.
 * bool isPalindrome(int x) 
 * */

#include "common.h"

bool isPalindrome(int x) { 
    if ( x < 0) return false;

    int len = 1;
    for (len = 1; (x/len) >= 10; len *= 10);

    while(x) {
        int left = x / len;
        int right = x % 10;
        if (left != right) {
            return false;
        }
        x = (x%len) / 10;
        len /= 100;
    }
    return true;
}

int main() {
    struct Case {
        string description;
        int x;
        bool expect;
    } cases[] = {
        {"Normal", 101, true},
        {"Normal", 1221, true},
        {"Not", 112, false},
        {"Neg", -121, false},
        {"Not", 100021, false},
        {"Not", 10003001, false},
        
    };
    int size = sizeof(cases)/sizeof(Case);
    bool ok = true;
    for (int i = 0; i < size; i++) {
        bool result = isPalindrome(cases[i].x);
        if (result != cases[i].expect) {
            ok = false;
            cerr << "Case " << i << " Failed, [" << cases[i].description << "] expect: " << cases[i].expect << " actual output: " << result << "\n";
        }
    }
    if (ok) {
        cout << "ALL PASSED.\n";
    }

    return 0;
}



