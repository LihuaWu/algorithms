/*
 * C. Longest Regular Bracket Sequence
 * time limit per test2 seconds
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
 * This is yet another problem dealing with regular bracket sequences.
 *
 * We should remind you that a bracket sequence is called regular, if by inserting «+» and «1» into it we can get a correct mathematical expression. For example, sequences «(())()», «()» and «(()(()))» are regular, while «)(», «(()» and «(()))(» are not.
 *
 * You are given a string of «(» and «)» characters. You are to find its longest substring that is a regular bracket sequence. You are to find the number of such substrings as well.
 *
 * Input
 * The first line of the input file contains a non-empty string, consisting of «(» and «)» characters. Its length does not exceed 106.
 *
 * Output
 * Print the length of the longest substring that is a regular bracket sequence, and the number of such substrings. If there are no such substrings, write the only line containing "0 1".
 *
 * Examples
 * input
 * )((())))(()())
 * output
 * 6 2
 * input
 * ))(
 * output
 * 0 1
 *
 * */

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string s;
int n;

int main() {
    cin >> s;
    n = s.size();
    vector<int> d(n, -1);
    vector<int> c(n, -1);
    vector<int> buf;
    map<int, int> db;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            buf.push_back(i);
        } else {
            if (buf.size() > 0) {
                d[i] = buf.back();
                buf.pop_back();
                c[i] = d[i];
                if (s[d[i]-1] == ')') {
                    if (c[d[i]-1] != -1) {
                        c[i] = c[d[i]-1];
                    }
                }
            }
        }
        if (c[i] != -1) {
            db[i-c[i]+1]++; 
        }
    }
    if (db.size() == 0) {
        cout << " 0 1";
    } else {
        cout << db.rbegin()->first << " " <<db.rbegin()->second;
    }

    return 0;
}
