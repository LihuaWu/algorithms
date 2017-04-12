/*
 * 12. Integer to Roman Add to List
 * DescriptionSubmissionsSolutions
 * Total Accepted: 99452
 * Total Submissions: 227649
 * Difficulty: Medium
 * Contributor: LeetCode
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 * string intToRoman(int num)
 * */

#include "common.h"

string intToRoman(int num) {
    string table[] = { "I", "V", "X", "L", "C", "D", "M"};
    ostringstream oss;
    int len = 10;
    int cnt = 1;
    while(num/len >= 10) {
        len *= 10;
        cnt++;
    }
    while(num) {
        int cur = num / len;
        if (cur < 4) {
            for(int i = 0; i < cur; i++) {
                oss << table[2 * cnt];
            }
        } else if (cur < 5) {
            oss << table[2*cnt] << table[2*cnt+1];
        } else if (cur < 9){
            oss << table[2*cnt+1];
            for (int i = 0; i < cur-5; i++) {
                oss << table[2*cnt];
            }
        } else {
            oss << table[2*cnt] << table[2*cnt+2];
        }

        num %= len;
        len /= 10;
        cnt--;
    }
    return oss.str();
}

/*
 * Input1II2
 * III3IV4
 * V5
 * VI6
 * VII7
 * VIII 8
 * IX9
 * X10
 * XI11
 * XII12
 * XIII13
 * XIV14
 * XV15
 * XVI16
 * XVII17
 * XVIII18
 * XIX19
 * XX20
 * XXX30
 * XL40
 * LeetCode50LX60
 * LXX70
 * LXXX80
 * XC90
 * XCIX 99*/

int main() {
    struct Case {
        string  expect;
        int num;
    } cases[] = {
        {"I", 1},
        {"II", 2},
        {"III", 3},
        {"IV", 4},
        {"V", 5},
        {"IX", 9},
        {"MCDXXXVII", 1437},
    };

    int size = sizeof(cases)/sizeof(Case);
    bool ok = true;
    for (int i = 0; i < size; i++) {
        string output = intToRoman(cases[i].num);
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




