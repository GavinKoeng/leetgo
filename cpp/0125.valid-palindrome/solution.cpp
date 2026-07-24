// Created by Gavin at 2025/12/03 16:37
// leetgo: 1.4.15
// https://leetcode.cn/problems/valid-palindrome/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isPalindrome(string s) {
		string sgood;
		for (char ch: s) {
				if (isalnum(ch)) {
						sgood += tolower(ch);
				}
		}
		string sgood_rev(sgood.rbegin(), sgood.rend());
		return sgood == sgood_rev;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);

	Solution *obj = new Solution();
	auto res = obj->isPalindrome(s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
