// Created by Gavin at 2026/01/22 09:50
// leetgo: 1.4.15
// https://leetcode.cn/problems/hamming-distance/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x ^ y, ret = 0;
        while (s) {
            ret += s & 1;
            s >>= 1;
        }
        return ret;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int x;
	LeetCodeIO::scan(cin, x);
	int y;
	LeetCodeIO::scan(cin, y);

	Solution *obj = new Solution();
	auto res = obj->hammingDistance(x, y);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
