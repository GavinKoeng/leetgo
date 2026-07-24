// Created by Gavin at 2025/12/14 00:01
// leetgo: 1.4.15
// https://leetcode.cn/problems/largest-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &x, const int &y) {
            return to_string(x) + to_string(y) > to_string(y) + to_string(x);
        });
        if (nums[0] == 0) {
          return "0";
        }
        string ret;
        for (int &x: nums) {
          ret += to_string(x);
        }
        return ret;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->largestNumber(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
