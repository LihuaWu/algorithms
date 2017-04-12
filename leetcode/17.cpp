/*
 *  Letter Combinations of a Phone Number Add to List
 *  DescriptionSubmissionsSolutions
 *  Total Accepted: 138911
 *  Total Submissions: 415163
 *  Difficulty: Medium
 *  Contributor: LeetCode
 *  Given a digit string, return all possible letter combinations that the number could represent.
 *
 *  A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 *
 *
 *  Input:Digit string "23"
 *  Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *  Note:
 *  Although the above answer is in lexicographical order, your answer could be in any order you want.
 *
 * vector<string> letterCombinations(string digits)
 *  */

#include "common.h"


void dfs(string digit, vector<string>& ret, string table[], string& s) {
    if (s.size() == digit.size()) {
        ret.push_back(s);
    } else {
        int cur = digit[s.size()] - '0';
        string choice = table[cur];
        for (int i = 0; i < choice.size(); i++) {
            s.push_back(choice[i]);
            dfs(digit, ret, table, s);
            s.pop_back(); 
        }
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ret;
    if (digits.size() == 0) return ret;
    string table[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    string s;
    dfs(digits, ret, table, s);
    return ret;

}

int main() {
    auto show = [](string digits) {
        auto res = letterCombinations(digits);
        cout << res.size() << " elements: ";
        for (auto i : res) {
            cout << i << " ";
        }
        cout << "\n";
    };

    show("234");
    show("");
    return 0;
}
