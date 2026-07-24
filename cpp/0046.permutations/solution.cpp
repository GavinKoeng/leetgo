// Created by Gavin at 2025/12/14 10:09
// leetgo: 1.4.15
// https://leetcode.cn/problems/permutations/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len) {
      if (first == len) {
        res.emplace_back(output);
        return;
      }
      for (int i = first; i < len; ++i) {
        swap(output[i], output[first]);
        backtrack(res, output, first + 1, len);
        swap(output[i], output[first]);
      }
    }

    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> res;
      backtrack(res, nums, 0 , nums.size());
      return res;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums;
	LeetCodeIO::scan(cin, nums);

	Solution *obj = new Solution();
	auto res = obj->permute(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
