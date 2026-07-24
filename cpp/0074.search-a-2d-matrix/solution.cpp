// Created by Gavin at 2025/12/11 12:44
// leetgo: 1.4.15
// https://leetcode.cn/problems/search-a-2d-matrix/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
		int low = 0, high = m * n - 1;
		while (low <= high) {
				int mid = (high - low) / 2 + low;
				int x = matrix[mid / n][mid % n];
				if (x < target) {
						low = mid + 1;
				} else if (x > target) {
						high = mid - 1;
				} else {
						return true;
				}
		}
		return false;
    }
};

// @lc code=end

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
