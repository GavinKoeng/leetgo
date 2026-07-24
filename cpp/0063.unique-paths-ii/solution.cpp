// Created by Gavin at 2025/12/30 22:18
// leetgo: 1.4.15
// https://leetcode.cn/problems/unique-paths-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector <int> f(m);

        f[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    f[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j] == 0) {
                    f[j] += f[j - 1];
                }
            }
        }
        return f.back();
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> obstacleGrid;
	LeetCodeIO::scan(cin, obstacleGrid);

	Solution *obj = new Solution();
	auto res = obj->uniquePathsWithObstacles(obstacleGrid);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
