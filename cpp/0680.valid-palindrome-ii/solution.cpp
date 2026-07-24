// Created by Gavin at 2025/12/03 16:54
// leetgo: 1.4.15
// https://leetcode.cn/problems/valid-palindrome-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool checkPalindrome(const string& s, int low, int high) {
			for (int i = low, j = high; i < j; ++i, --j) {
					if (s[i] != s[j]) {
							return false;
					}
			}
			return true;
	}

    bool validPalindrome(string s) {
			int low = 0, high = s.size() - 1;
			while (low < high) {
					char c1 = s[low], c2 = s[high];
					if (c1 == c2) {
							++low;
							--high;
					} else {
							return checkPalindrome(s, low, high - 1) || checkPalindrome(s, low + 1, high);
					}
			}
			return true;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);

	Solution *obj = new Solution();
	auto res = obj->validPalindrome(s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
