// Created by Gavin at 2026/02/01 13:38
// leetgo: 1.4.15
// https://leetcode.cn/problems/valid-anagram/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> table(26, 0);
        for (auto& ch : s) {
            table[ch - 'a']++;
        }
        for (auto& ch : t) {
            table[ch - 'a']--;
            if (table[ch - 'a'] < 0) {
                return false;
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
	string t;
	LeetCodeIO::scan(cin, t);

	Solution *obj = new Solution();
	auto res = obj->isAnagram(s, t);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
