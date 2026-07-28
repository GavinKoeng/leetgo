// Created by Gavin at 2026/07/28 16:58
// leetgo: 1.4.15
// https://leetcode.cn/problems/move-zeroes/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int right = 0, left = 0;
       int n = nums.size();
       while (right < n) {
           if (nums[right]) {
               swap(nums[right], nums[left]);
               left++;
           }
           right++;
       }
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->moveZeroes(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
