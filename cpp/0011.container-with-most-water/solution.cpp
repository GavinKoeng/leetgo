// Created by Gavin at 2025/12/08 16:14
// leetgo: 1.4.15
// https://leetcode.cn/problems/container-with-most-water/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
		int ans = 0;
		while (l < r) {
				int area = min(height[l], height[r]) * (r - l);
				ans = max(ans, area);
				if (height[l] <= height[r]) {
						++l;
				}
				else {
						--r;
				}
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
	auto res = obj->maxArea(height);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
