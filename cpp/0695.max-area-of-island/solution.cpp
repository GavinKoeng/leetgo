// Created by Gavin at 2025/12/13 12:11
// leetgo: 1.4.15
// https://leetcode.cn/problems/max-area-of-island/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
    int dfs(vector<vector<int>>& grid, int cur_i, int cur_j) {
      if (cur_i < 0 || cur_j < 0 || cur_i == grid.size() || cur_j == grid[0].size() || grid[cur_i][cur_j] != 1) {
        return 0;
      }
      grid[cur_i][cur_j] = 0;
      int di[4] = {0, 0, 1, -1};
      int dj[4] = {1, -1, 0, 0};
      int ans = 1;
      for (int index = 0; index != 4; ++index) {
        int next_i = cur_i + di[index], next_j = cur_j + dj[index];
        ans += dfs(grid, next_i, next_j);
      }
      return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int ans = 0;
      for (int i = 0; i != grid.size(); ++i) {
        for (int j = 0; j != grid[0].size(); ++j) {
          ans = max(ans, dfs(grid, i, j));
          }
      }
      return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> grid;
	LeetCodeIO::scan(cin, grid);

	Solution *obj = new Solution();
	auto res = obj->maxAreaOfIsland(grid);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
