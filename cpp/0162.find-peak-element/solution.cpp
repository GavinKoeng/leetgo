// Created by Gavin at 2025/12/11 15:10
// leetgo: 1.4.15
// https://leetcode.cn/problems/find-peak-element/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
			int n = nums.size();
			int idx = rand() % n;

			auto get = [&](int i) -> pair<int, int> {
					if (i == -1 || i == n) {
							return {0, 0};
					}
					return {1, nums[i]};
			};

			while (!(get(idx - 1) < get(idx) && get(idx) > get(idx + 1))) {
					if (get(idx) < get(idx + 1)) {
							idx += 1;
					} else {
							idx -= 1;
					}
			}
			return idx;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->findPeakElement(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
