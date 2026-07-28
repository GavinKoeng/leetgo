// Created by Gavin at 2026/07/28 17:24
// leetgo: 1.4.15
// https://leetcode.cn/problems/max-consecutive-ones/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int count = 0, num = 0, mov = 0;
        while (mov < n) {
            if (nums[mov]) {
                num++;
                if (count < num) {
                    count = num;
                }
            } else {
                num = 0;
            }
            mov++;
        }
        return count;
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
