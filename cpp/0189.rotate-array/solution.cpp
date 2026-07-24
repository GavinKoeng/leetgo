// Created by Gavin at 2025/12/10 16:36
// leetgo: 1.4.15
// https://leetcode.cn/problems/rotate-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> rotate(vector<int>& nums, int k) {
        int n = nums.size();
		vector<int> newArr(n);
		for (int i = 0; i < n; ++i) {
				newArr[(i + k) % n] = nums[i];
		}
		nums.assign(newArr.begin(), newArr.end());
		return nums;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);
	int k;
	LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();
	auto res = obj->rotate(nums, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
