// Created by Gavin at 2025/12/03 16:17
// leetgo: 1.4.15
// https://leetcode.cn/problems/palindrome-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isPalindrome(int x) {
       if (x < 0 || (x % 10 == 0 &&	x != 0)) {
			   return false;
	   }

	   int revertedNumber = 0;
	   while (x > revertedNumber) {
			   revertedNumber = revertedNumber * 10 + x % 10;
			   x /= 10;
	   }

	   return x == revertedNumber || x == revertedNumber / 10;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	int x;
	LeetCodeIO::scan(cin, x);

	Solution *obj = new Solution();
	auto res = obj->isPalindrome(x);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
