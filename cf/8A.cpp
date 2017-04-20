/*
 * */

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string s, s1, s2, a[] = {"fantasy", "forward", "backward", "both"};
int x, out;

int main() {
    cin >> s >> s1 >> s2;
    if ((x = s.find(s1)) != -1 && s.find(s2, x+s1.size()) != -1) out++;
    reverse(s.begin(), s.end());
    if ((x = s.find(s1)) != -1 && s.find(s2, x+s1.size()) != -1) out += 2;
    cout << a[out];


    return 0;
}
