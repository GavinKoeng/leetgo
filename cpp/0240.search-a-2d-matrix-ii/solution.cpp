// Created by Gavin at 2025/12/11 12:51
// leetgo: 1.4.15
// https://leetcode.cn/problems/search-a-2d-matrix-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& row: matrix) {
				auto it = lower_bound(row.begin(), row.end(), target);
				if (it != row.end() && *it == target) {
						return true;
				}
		}
		return false;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<int>> matrix;
	LeetCodeIO::scan(cin, matrix);
	int target;
	LeetCodeIO::scan(cin, target);

	Solution *obj = new Solution();
	auto res = obj->searchMatrix(matrix, target);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
