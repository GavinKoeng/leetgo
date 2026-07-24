// Created by Gavin at 2025/12/11 12:37
// leetgo: 1.4.15
// https://leetcode.cn/problems/valid-perfect-square/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isPerfectSquare(int num) {
       int left = 0, right = num;
	   while (left <= right) {
			   int mid = (right - left) / 2 + left;
			   long square = (long) mid * mid;
			   if (square < num) {
					   left = mid + 1;
			   } else if (square > num) {
					   right = mid - 1;
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

	int num;
	LeetCodeIO::scan(cin, num);

	Solution *obj = new Solution();
	auto res = obj->isPerfectSquare(num);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
