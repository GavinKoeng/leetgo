// Created by Gavin at 2025/12/12 10:53
// leetgo: 1.4.15
// https://leetcode.cn/problems/minimum-size-subarray-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int n = nums.size();
	   if (n == 0) {
			   return 0;
	   }
	   int ans = INT_MAX;
	   vector<int> sums(n + 1, 0);
	   for (int i = 1; i <= n; i++) {
			   sums[i] = sums[i - 1] + nums[i - 1];
	   }
	   for (int i = 1; i <= n; i++) {
			   int tar = target + sums[i - 1];
			   auto bound = lower_bound(sums.begin(), sums.end(), tar);
			   if (bound != sums.end()) {
					   ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
									   }
	   }
	   return ans == INT_MAX ? 0 : ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int target;
	LeetCodeIO::scan(cin, target);
	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->minSubArrayLen(target, nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
