// Created by Gavin at 2025/12/13 12:36
// leetgo: 1.4.15
// https://leetcode.cn/problems/island-perimeter/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
  constexpr static int dx[4] = {0, 1, 0, -1};
  constexpr static int dy[4] = {1, 0, -1, 0};

public:
    int islandPerimeter(vector<vector<int>>& grid) {
      int n = grid.size(), m = grid[0].size();
      int ans = 0;
      for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
          if (grid[i][j]) {
            int cnt = 0;
            for (int k = 0; k != 4; ++k) {
              int tx = i + dx[k];
              int ty = j + dy[k];
              if (tx < 0 || tx >= n || ty < 0 || ty >= m || !grid[tx][ty]) {
                cnt += 1;
              }
            }
            ans += cnt;
          }
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
	auto res = obj->islandPerimeter(grid);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
