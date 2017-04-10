/*
 * Longest Substring Without Repeating Characters
 *
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 *
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 *
 * Given "bbbbb", the answer is "b", with the length of 1.
 *
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 *
 *  Idea:
 *   
 *   Using a map store each char's index.
 *   
 *   So, we can be easy to know the when duplication and the previous duplicated char's index.
 *   
 *   Then we can take out the previous duplicated char, and keep tracking the maxiumn length. 
 * */

#include "common.h"

int lengthOfLongestSubstring(string s) {
    vector<int> m(256, -1);
    int lastRepeatPos = -1;
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++) {
        if (m[s[i]] != -1 && lastRepeatPos < m[s[i]]) {
            lastRepeatPos = m[s[i]];
        }
        if (i - lastRepeatPos > maxLen) {
            maxLen = i - lastRepeatPos;
        }
        m[s[i]] = i;
    }
    return maxLen;
 }

int main() {
    struct Case {
        char s[200];
        int expect;
    }cases[] = {
        {"abcabcbb", 3},
        {"bbbbb", 1},
        {"pwwkew", 3},
        {"aab", 2},
    }; 

    int size = sizeof(cases)/sizeof(Case);
    bool ok = true;
    for (int i = 0; i < size; i++) {
        int result = lengthOfLongestSubstring(string(cases[i].s));
        if (cases[i].expect != result) {
            ok = false;
            cerr << "case " << i << " Failed, expect: " <<  cases[i].expect << " actual output: " << result << "\n";
        }
    }
    if (ok) {
        cout << "ALL PASSED.\n";
    }
    return 0;
}
