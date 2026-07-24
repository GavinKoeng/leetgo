// Created by Gavin at 2025/12/10 11:47
// leetgo: 1.4.15
// https://leetcode.cn/problems/powx-n/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    double quickMul(double x, long long N) {
			if (N == 0) {
					return 1.0;
			}
			double y = quickMul(x, N / 2);
			return N % 2 == 0 ? y * y : y * y * x;
	}
    double myPow(double x, int n) {
        long long N = n;
		return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	double x;
	LeetCodeIO::scan(cin, x);
	int n;
	LeetCodeIO::scan(cin, n);

	Solution *obj = new Solution();
	auto res = obj->myPow(x, n);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
