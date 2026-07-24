// Created by Gavin at 2025/12/09 19:00
// leetgo: 1.4.15
// https://leetcode.cn/problems/single-number-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
		for (int num: nums) {
				++freq[num];
		}
		int ans = 0;
		for (auto [num, occ]: freq) {
				if (occ == 1) {
						ans = num;
						break;
				}
		}
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
	auto res = obj->singleNumber(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
