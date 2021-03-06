/*
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 *
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
 *
 * spoilers alert... click to show requirements for atoi.
 *
 * Requirements for atoi:
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 *
 * The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 * int myAtoi(string str) 
 * */


#include "common.h"

int myAtoi(string str) {
    int size = str.size();
    int64_t ret = 0;
    int sign = 1;
    int i = 0;
    //filter spaces
    while(i < size && isspace(str[i])) {i++;}
    if (i == size) return 0;

    //deal with sign
    if (!isdigit(str[i])) {
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+') {
            i++;
        } else {
            return 0;
        }
    }
    while(i < size) {
        if (!isdigit(str[i])) break;
        ret = 10 * ret + str[i] - '0';
        if (ret * sign > std::numeric_limits<int>::max()) {  
            return std::numeric_limits<int>::max();
        } else if (ret * sign < std::numeric_limits<int>::min()) {
            return std::numeric_limits<int>::min();
        }
        i++;
    }
    return sign * ret;
}

int main() {
    struct Case {
        string str;
        int expect;
    } cases[] = {
        {"  +", 0},
        {"  -", 0},
        {"0", 0},
        {"-123", -123},
        {"+123", 123},
        {"123", 123}, 
        {"     123", 123},
        {"123abcde", 123},
        {"abc1323", 0},
        {"+2147483647", std::numeric_limits<int>::max() },
        {"+2147483648", std::numeric_limits<int>::max() },
        {"-2147483648", std::numeric_limits<int>::min() },
        {"-2147483649", std::numeric_limits<int>::min() },

    };
    int size = sizeof(cases)/sizeof(Case);

    bool ok = true;
    for (int i = 0; i < size; i++) {
        int result = myAtoi(cases[i].str);
        if (result != cases[i].expect) {
            ok = false;
            cerr << "Case " << i << " Failed. expect: " << cases[i].expect << " actual output: " << result << " \n";
        }
    }
    if (ok) {
        cout << "ALL PASSED.";
    }
    return 0;
}
