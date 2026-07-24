// Created by Gavin at 2026/01/29 20:08
// leetgo: 1.4.15
// https://leetcode.cn/problems/trapping-rain-water/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector <int> left(n), right(n);
        left[0] = height[0];
        for (int i = 1; i < n; i++) {
            left[i] += max(left[i - 1], height[i]);
        }

        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] += max(right[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> height;
	LeetCodeIO::scan(cin, height);

	Solution *obj = new Solution();
	auto res = obj->trap(height);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
