/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 * */


#include "common.h"

//From Haoel
string convert2(string s, int numRows) {
    if (numRows <= 1 || numRows >= s.size()) return s;

    vector<string> r(numRows);
    int row = 0;
    int step = 1;
    for (int i = 0; i < s.size(); i++) {
        if (row == numRows-1) step = -1;
        if (row == 0) step = 1;
        r[row] += s[i];
        row += step;
    }
    string ret;
    for (int i = 0; i < numRows; i++) {
        ret += r[i];
    }
    return ret;
}

string convert(string s, int numRows) {
    int size = s.size();
    if (numRows <= 1 || numRows >= size) return s;
    vector<bool> vis(size, false);
    int step = numRows + numRows - 2;
    ostringstream oss;
    int idx = -1;
    for (int i = 0; i <= step/2; i++) {
        for (int j = 0; j < size;  j += step) {
            idx = j + i;
            if (idx < size && !vis[idx]) {
                vis[idx] = true;
                oss << s[idx];
            }
            idx = j + step-i;
            if (idx < size && !vis[idx]) {
                vis[idx] = true;
                oss << s[idx];
            }
        }
    }
    return oss.str();
}

class Case {
public:
    string s;
    int row;
    string expect;
};

int main() {
    Case cases[] = {
        {"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"},
        {"PAYPALISHIRING", 4, "PINALSIGYAHRPI"},
    };

    int size = sizeof(cases) / sizeof(Case);

    bool ok = true;
    for (int i = 0; i < size; i++) {
        string result = convert2(cases[i].s, cases[i].row);
        if (cases[i].expect != result) {
            ok = false;
            cerr << "case " << i << " failed, expect " << cases[i].expect.size() << " actual result: " <<  result.size() << "\n";
        }
    }
    if (ok) {
        cout << "ALL PASSED.\n";
    }

    return 0;
}
