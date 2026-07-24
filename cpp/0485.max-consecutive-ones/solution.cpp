// Created by Gavin at 2026/01/23 10:48
// leetgo: 1.4.15
// https://leetcode.cn/problems/max-consecutive-ones/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
       int k = 0, ans = 0, n = nums.size();
       for (int i = 0; i < n; ++i) {
           if (nums[i] == 1) {
               ++k;
           } else {
               ans = max(ans, k);
               k = 0;
           }
       }
       ans = max(ans, k);
       return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->findMaxConsecutiveOnes(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
