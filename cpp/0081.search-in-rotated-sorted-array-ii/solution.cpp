// Created by Gavin at 2025/12/11 11:06
// leetgo: 1.4.15
// https://leetcode.cn/problems/search-in-rotated-sorted-array-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int n = nums.size();
	   if (n == 0) {
			   return false;
	   }
	   if (n == 1) {
			   return nums[0] == target;
	   }
	   int l = 0, r = n - 1;
	   while (l <= r) {
			   int mid = (l + r) / 2;
			   if (nums[mid] == target) {
					   return true;
			   }
			   if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
					   ++l;
					   --r;
			   } else if (nums[l] <= nums[mid]) {
					   if (nums[l] <= target && target < nums[mid]) {
							   r = mid - 1;
					   } else {
							   l = mid + 1;
					   }
			   } else {
					   if (nums[mid] < target && target <= nums[n -1]) {
							   l = mid + 1;
					   } else {
							   r = mid - 1;
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
	int target;
	LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();
	auto res = obj->search(nums, target);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
