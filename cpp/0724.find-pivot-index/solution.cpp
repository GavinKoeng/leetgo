// Created by Gavin at 2026/02/04 00:40
// leetgo: 1.4.15
// https://leetcode.cn/problems/find-pivot-index/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int num = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (2 * num + nums[i] == sum) {
                return i;
            }
            num += nums[i];
        }
        return -1;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->pivotIndex(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
