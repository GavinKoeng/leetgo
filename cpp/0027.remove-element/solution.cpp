// Created by Gavin at 2026/07/29 10:25
// leetgo: 1.4.15
// https://leetcode.cn/problems/remove-element/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //if(nums.empty()) return 0;
        int n = nums.size();
        int slow = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == val) {
            } else {
                nums[slow++] = nums[i];
            }
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
	int val;
	LeetCodeIO::scan(cin, val);

	Solution *obj = new Solution();
	auto res = obj->removeElement(nums, val);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
