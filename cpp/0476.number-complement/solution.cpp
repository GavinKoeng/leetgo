// Created by Gavin at 2026/01/21 09:31
// leetgo: 1.4.15
// https://leetcode.cn/problems/number-complement/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int findComplement(int num) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int num;
	LeetCodeIO::scan(cin, num);

	Solution *obj = new Solution();
	auto res = obj->findComplement(num);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
