/*
 *  Longest Common Prefix Add to List
 *  DescriptionSubmissionsSolutions
 *  Total Accepted: 163774
 *  Total Submissions: 527290
 *  Difficulty: Easy
 *  Contributor: LeetCode
 *  Write a function to find the longest common prefix string amongst an array of strings.
 *
 *  string longestCommonPrefix(vector<string>& strs)
 *
 * */

#include "common.h"

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0) return "";
    size_t size = strs[0].size();
    for (int i = 1; i < strs.size(); i++) {
        size = min(size, strs[i].size());
    }
    string ret;
    for (int i = 0; i < size; i++) {
        bool same = true;
        char cur = strs[0][i];
        for (int j = 1; j < strs.size(); j++) {
            if (strs[j][i] != cur) {
                same = false;
                break;
            }
        }
        if (same) {
            ret += cur;
        } else {
            break;
        }
    }
    return ret;
}

int main() {
    struct Case {
        vector<string> strs;
        string expect;
    } cases[] = {
        {{"abc", "aab", "adc"}, "a"},
        {{"aaaaasdsfs", "aabb", "adddd", "a"}, "a"},
        {{"aaaaasdsfs", "aabb", "adddd", "bbe"}, ""},
    };

    int size = sizeof(cases)/sizeof(Case);
    bool ok = true;
    for (int i = 0; i < size; i++) {
        string output = longestCommonPrefix(cases[i].strs);
        if (output != cases[i].expect) {
            cerr << "Case " << i << " Failed, expect: " <<cases[i].expect << " actual output: " << output << "\n";
            ok = false;
        }
    }
    if (ok) {
        cout << "ALL PASSED.\n";
    }
}
