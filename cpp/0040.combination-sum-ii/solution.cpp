// Created by Gavin at 2025/12/15 01:16
// leetgo: 1.4.15
// https://leetcode.cn/problems/combination-sum-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
    vector<int> sequence;

public:
    void dfs(int pos, int rest) {
      if (rest == 0) {
        ans.push_back(sequence);
        return;
      }
      if (pos == freq.size() || rest < freq[pos].first) {
        return;
      }
      dfs(pos + 1, rest);
      int most = min(rest / freq[pos].first, freq[pos].second);
      for (int i = 1; i <= most; ++i) {
        sequence.push_back(freq[pos].first);
        dfs(pos + 1, rest - i * freq[pos].first);
      }
      for (int i = 1; i <= most; ++i) {
        sequence.pop_back();
      }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      for (int num: candidates) {
        if (freq.empty() || num != freq.back().first) {
          freq.emplace_back(num, 1);
        } else {
          ++freq.back().second;
        }
      }
    dfs(0, target);
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
	auto res = obj->combinationSum2(candidates, target);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
