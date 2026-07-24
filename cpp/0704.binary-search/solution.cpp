// Created by Gavin at 2025/12/10 16:27
// leetgo: 1.4.15
// https://leetcode.cn/problems/binary-search/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
		while (left <= right) {
				int mid = (right - left) / 2 + left;
				int num = nums[mid];
				if (num == target) {
						return mid;
				} else if (num > target) {
						right = mid - 1;
				} else {
						left = mid + 1;
				}
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
	int target;
	LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();
	auto res = obj->search(nums, target);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
