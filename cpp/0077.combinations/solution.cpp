// Created by Gavin at 2025/12/15 02:15
// leetgo: 1.4.15
// https://leetcode.cn/problems/combinations/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    void dfs(int cur, int n, int k) {
      if (temp.size() + (n - cur + 1) < k) {
        return;
      }
      if (temp.size() == k) {
        ans.push_back(temp);
        return;
      }
      temp.push_back(cur);
      dfs(cur + 1, n, k);
      temp.pop_back();
      dfs(cur + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
      dfs(1, n, k);
      return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int n;
	LeetCodeIO::scan(cin, n);
	int k;
	LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();
	auto res = obj->combine(n, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
