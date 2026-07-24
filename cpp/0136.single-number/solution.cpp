// Created by Gavin at 2025/12/09 18:52
// leetgo: 1.4.15
// https://leetcode.cn/problems/single-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
		for (auto e: nums) ret ^= e;
		return ret;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->singleNumber(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
