/*
 * 11. Container With Most Water Add to List
 * DescriptionSubmissionsSolutions
 * Total Accepted: 124411
 * Total Submissions: 343310
 * Difficulty: Medium
 * Contributor: LeetCode
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container and n is at least 2.
 * int maxArea(vector<int>& height)
 * */

#include "common.h"

int maxArea(vector<int>& height) {
    int size = height.size();
    int left = 0, right = size-1;
    int ret = 0;
    while(left < right) {
        int cur = min(height[left], height[right]) * (right-left);
        if (ret < cur) { ret = cur; }
        if (height[left] < height[right]) {
            left++;
        } else if (height[left] > height[right]) {
            right--;
        } else {
            left++, right--;
        }
    }
    return ret;
}

int main() {
    struct Case {
        vector<int> height;
        int expect;
    } cases[] = {
        {{1,2,3}, 2},
        {{3, 2, 1, 4}, 9},
    };
    int size = sizeof(cases)/sizeof(Case);
    bool ok = true;
    for (int i = 0; i < size; i++) {
        int ret = maxArea(cases[i].height);
        if (ret != cases[i].expect) {
            ok = false;
            cerr << "Case " << i << " Failed. expect: " << cases[i].expect << " actual output: " <<ret << "\n"; 
        }
    }
    if (ok) {
        cout << "ALL PASSED.\n";
    }
    return 0;
}
