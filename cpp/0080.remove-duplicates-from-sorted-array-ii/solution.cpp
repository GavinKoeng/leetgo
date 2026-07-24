// Created by Gavin at 2025/12/01 17:23
// leetgo: 1.4.15
// https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
			int n = nums.size();
			if (n <= 2) {
					return n;
			}
			int slow = 2, fast = 2;
			while (fast < n) {
					if (nums[slow - 2] != nums[fast]) {
							nums[slow] = nums[fast];
							++slow;
						}
					++fast;
			}
			return slow;
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->removeDuplicates(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
