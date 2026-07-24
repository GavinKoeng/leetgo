// Created by Gavin at 2025/12/12 14:59
// leetgo: 1.4.15
// https://leetcode.cn/problems/permutation-in-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       int n = s1.length(), m = s2.length();
	   if (n > m) {
			   return false;
	   }
	   vector<int> cnt1(26), cnt2(26);
	   for (int i = 0; i < n; ++i) {
			   ++cnt1[s1[i] - 'a'];
			   ++cnt2[s2[i] - 'a'];
	   }
	   if (cnt1 == cnt2) {
			   return true;
	   }
	   for (int i = n; i < m; ++i) {
			   ++cnt2[s2[i] - 'a'];
			   --cnt2[s2[i - n] - 'a'];
			   if (cnt1 == cnt2) {
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

	string s1;
	LeetCodeIO::scan(cin, s1);
	string s2;
	LeetCodeIO::scan(cin, s2);

	Solution *obj = new Solution();
	auto res = obj->checkInclusion(s1, s2);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
