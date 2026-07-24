// Created by Gavin at 2026/02/06 22:14
// leetgo: 1.4.15
// https://leetcode.cn/problems/valid-sudoku/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<vector<char>> board;
	LeetCodeIO::scan(cin, board);

	Solution *obj = new Solution();
	auto res = obj->isValidSudoku(board);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
