// Created by Gavin at 2026/01/03 15:45
// leetgo: 1.4.15
// https://leetcode.cn/problems/perfect-squares/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int numSquares(int n) {
        vector<int>  f(n + 1);
        for (int i = 1; i <= n; ++i) {
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int n;
	LeetCodeIO::scan(cin, n);

	Solution *obj = new Solution();
	auto res = obj->numSquares(n);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
