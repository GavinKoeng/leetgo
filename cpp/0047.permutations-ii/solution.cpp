// Created by Gavin at 2025/12/14 10:31
// leetgo: 1.4.15
// https://leetcode.cn/problems/permutations-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
    vector<int> vis;

public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm) {
      if (idx == nums.size()) {
        ans.emplace_back(perm);
        return;
      }
      for (int i = 0; i < (int)nums.size(); ++i) {
        if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
          continue;
        }
        perm.emplace_back(nums[i]);
        vis[i] = 1;
        backtrack(nums, ans, idx + 1, perm);
        vis[i] = 0;
        perm.pop_back();
      }
      }
      
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>> ans;
      vector<int> perm;
      vis.resize(nums.size());
      sort(nums.begin(), nums.end());
      backtrack(nums, ans, 0, perm);
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
	auto res = obj->permuteUnique(nums);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
