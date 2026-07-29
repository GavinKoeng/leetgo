// Created by Gavin at 2026/07/29 10:05
// leetgo: 1.4.15
// https://leetcode.cn/problems/max-consecutive-ones/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, Count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i]) {
                Count++;
            } else {
                maxCount = max(maxCount, Count);
                Count = 0;
            }
        }
        maxCount = max(maxCount, Count);
        return maxCount;
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
