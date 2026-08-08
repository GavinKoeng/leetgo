// Created by gavin at 2026/08/08 20:26
// leetgo: 1.4.17
// https://leetcode.cn/problems/valid-parentheses/

#include <bits/stdc++.h>
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 != 0) return false;
        unordered_map<char, char> pairs {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        stack<char> stk;
        for (char ch : s) {
            if (pairs.count(ch)) {
                if (stk.empty() || pairs[ch] != stk.top()) {
                    return false;
                } else {
                    stk.pop();
                }
            } else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);

	Solution *obj = new Solution();
	auto res = obj->isValid(s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
