// Created by Gavin at 2025/12/09 19:17
// leetgo: 1.4.15
// https://leetcode.cn/problems/majority-element/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;
		int majority = 0, cnt = 0;
		for (int num: nums) {
				++counts[num];
				if (counts[num] > cnt) {
						majority = num;
						cnt = counts[num];
				}
		}
		return majority;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->majorityElement(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
