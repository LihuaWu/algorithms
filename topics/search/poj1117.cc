#include <stdio.h>
#include <string.h>

#include <utility>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int ORD[] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000,
};

vector<pair<string, int> > res;

void dfs(int cur, int skipped, int acc, const string& num) {
//    printf("cur=%d skipped=%d acc=%d num=%s N=%d\n", cur, skipped, acc, num.c_str(), N);
    if (acc > N) return;
    if (acc == N && skipped != -1) {
        if (num[0] != '0') {
            res.push_back(make_pair(num, skipped));
        }
        return;
    }
    int ord = ORD[cur];
    if (ord > N) return;
    if (cur > 9) return;

    for (int i = 0; i <= 9; i++) {
        char buf[2];
        buf[0] = '0' + i;
        buf[1] = 0;
        string nexNum = string(buf)+num;
        if (skipped != -1) {
            int cur_acc = acc + i * ord + i * ORD[cur-1];
            if (cur_acc / ORD[cur-1] % 10 == N /ORD[cur-1] % 10) {
                dfs(cur+1, skipped, cur_acc, nexNum);
            }
        } else {
           int cur_acc = acc + 2 * i * ORD[cur]; 
            if (cur_acc / ord % 10 == N / ORD[cur] % 10) {
                dfs(cur+1, skipped, cur_acc, nexNum);
            }

            cur_acc = acc + i * ORD[cur];
            dfs(cur+1, cur, cur_acc, nexNum);
        }
    }
}

bool comp(const pair<string, int>& lhs, const pair<string, int>& rhs) {
    return lhs.first == rhs.first;
}

//here we shoud convert string to int, since string comparision is alphabetical.
//eg:  "23" > "212" which is obviously inacceptable.
bool lessThan(const pair<string, int> lhs, const pair<string, int>& rhs) {
    int left = ::atoi(lhs.first.c_str());
    int right = ::atoi(rhs.first.c_str());
    return left < right;
}


int main () {
    cin >> N;
    dfs(0, -1, 0, "");
    sort(res.begin(), res.end(), lessThan);
    res.erase(unique(res.begin(), res.end(), comp),  res.end()); 
    cout << res.size() << "\n";
    for (size_t i = 0; i < res.size(); i++) {
        string second=res[i].first;
        second.erase(second.begin()+second.size()-1-res[i].second);
        printf("%s + %s = %d\n",  res[i].first.c_str(), second.c_str(), N);
    }
    return 0;
}
