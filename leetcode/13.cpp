/*
 * Roman to Integer Add to List
 * DescriptionSubmissionsSolutions
 * Total Accepted: 140763
 * Total Submissions: 315486
 * Difficulty: Easy
 * Contributor: LeetCode
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 * int romanToInt(string s)
 * */

#include "common.h"

int romanCharToInt(char c) {
    switch(c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int romanToInt(string s) {
    if (s.size() <= 0) return 0;
    int result = romanCharToInt(s[0]);

    for (int i = 1; i < s.size(); i++) {
        int prev = romanCharToInt(s[i-1]);
        int cur = romanCharToInt(s[i]);
        if (prev < cur) {
            result = result - prev + (cur-prev);
        } else {
            result += cur;
        }
    }
    return result;
}

int main() {
    struct Case {
        string  s;
        int expect;
    } cases[] = {
        {"I", 1},
        {"II", 2},
        {"III", 3},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"MCDXXXVII", 1437},
        {"MMMCCCXXXIII", 3333},
    };

    int size = sizeof(cases)/sizeof(Case);
    bool ok = true;
    for (int i = 0; i < size; i++) {
        int output = romanToInt(cases[i].s);
        if (output != cases[i].expect) {
            ok = false;
            cerr << "Case: " << i << " Failed. expect: " << cases[i].expect << " actual output: " << output << "\n";
        }
    }
    if (ok) {
        cout << "ALL PASSED.\n";
    }
    return 0;
}
