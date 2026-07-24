// Created by Gavin at 2025/12/14 12:08
// leetgo: 1.4.15
// https://leetcode.cn/problems/combination-sum/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
      if (idx == candidates.size()) {
        return;
      }
      if (target == 0) {
        ans.emplace_back(combine);
        return;
      }
      dfs(candidates, target, ans, combine, idx + 1);
      if (target - candidates[idx] >= 0) {
        combine.emplace_back(candidates[idx]);
        dfs(candidates, target - candidates[idx], ans, combine, idx);
        combine.pop_back();
      }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> ans;
      vector<int> combine;
      dfs(candidates, target, ans, combine, 0);
      return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> candidates;
	LeetCodeIO::scan(cin, candidates);
	int target;
	LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();
	auto res = obj->combinationSum(candidates, target);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
