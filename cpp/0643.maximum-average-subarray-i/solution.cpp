// Created by Gavin at 2025/12/12 13:06
// leetgo: 1.4.15
// https://leetcode.cn/problems/maximum-average-subarray-i/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
		int n = nums.size();
		for (int i = 0; i < k; i++) {
				sum += nums[i];
		}
		int maxSum = sum;
		for (int i = k; i < n; i++) {
				sum = sum - nums[i - k] + nums[i];
				maxSum = max(maxSum, sum);
		}
		return static_cast<double>(maxSum) / k;
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
	auto res = obj->findMaxAverage(nums, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
