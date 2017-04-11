/*
 * B. Spreadsheets
 * time limit per test10 seconds
 * memory limit per test64 megabytes
 * inputstandard input
 * outputstandard output
 * In the popular spreadsheets systems (for example, in Excel) the following numeration of columns is used. The first column has number A, the second — number B, etc. till column 26 that is marked by Z. Then there are two-letter numbers: column 27 has number AA, 28 — AB, column 52 is marked by AZ. After ZZ there follow three-letter numbers, etc.
 *
 * The rows are marked by integer numbers starting with 1. The cell name is the concatenation of the column and the row numbers. For example, BC23 is the name for the cell that is in column 55, row 23.
 *
 * Sometimes another numeration system is used: RXCY, where X and Y are integer numbers, showing the column and the row numbers respectfully. For instance, R23C55 is the cell from the previous example.
 *
 * Your task is to write a program that reads the given sequence of cell coordinates and produce each item written according to the rules of another numeration system.
 *
 * Input
 * The first line of the input contains integer number n (1 ≤ n ≤ 105), the number of coordinates in the test. Then there follow n lines, each of them contains coordinates. All the coordinates are correct, there are no cells with the column and/or the row numbers larger than 106 .
 *
 * Output
 * Write n lines, each line should contain a cell coordinates in the other numeration system.
 * Examples
 * input
 * 2
 * R23C55
 * BC23
 * output
 * BC23
 * R23C55
 * */

#include <ctype.h>

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {

    //BC -> 55
    auto string2int = [](string s) -> int {
        int ret = 0;
        for (int i = 0; i < s.size(); i++) {
            ret = ret * 26 + s[i] - 'A' + 1;
        }
        return ret;
    };


    //55 -> BC
    auto int2string = [](int i) -> string {
        string ret;
        while (i) {
            int remain = i % 26;
            if (remain == 0) {
                i = i/26-1;
            } else {
                i = i/26;
            }
            ret += 'A' + (remain+25)%26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    };

    //R23C55 -> BC23
    auto A2B = [&](string s) -> string {
        int pivot = s.find('C');
        string row = s.substr(1, pivot-1);
        string col = s.substr(pivot+1);
        istringstream iss(col);
        int colNum;
        iss >> colNum;
        return int2string(colNum) + row;
    };

    //BC23 -> R23C55
    auto B2A = [&](string s) -> string {
        int pivot = find_if(s.begin(), s.end(), [](char c)->bool {return isdigit(c) != 0; }) - s.begin();
        string row = s.substr(pivot);
        int colNum = string2int(s.substr(0, pivot));
        ostringstream oss;
        oss << colNum;
        return "R" + row + "C" + oss.str();

    };

    int n;
    cin >> n;
    auto convert = [&](string s) -> string {
        if (s[0] == 'R' && isdigit(s[1]) && s.find('C') != string::npos) {
            return A2B(s);
        } else {
            return B2A(s);
        }
    };

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << convert(s) << "\n";
    }
}
