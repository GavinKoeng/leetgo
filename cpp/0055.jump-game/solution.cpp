// Created by Gavin at 2025/12/09 18:24
// leetgo: 1.4.15
// https://leetcode.cn/problems/jump-game/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
		int rightmost = 0;
		for (int i = 0; i < n; ++i) {
				if (i <= rightmost) {
						rightmost = max(rightmost, i + nums[i]);
						if (rightmost >= n - 1) {
								return true;
						}
				}
		}
		return false;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->canJump(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
