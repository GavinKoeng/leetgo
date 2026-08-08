// Created by gavin at 2026/08/08 17:52
// leetgo: 1.4.17
// https://leetcode.cn/problems/valid-parentheses/

#include <bits/stdc++.h>
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            } else if (stk.empty()) {
                return false;
            } else if (s[i] == ')' && stk.top() != '(') {
                return false;
            } else if (s[i] == '}' && stk.top() != '{') {
                return false;
            } else if (s[i] == ']' && stk.top() != '[') {
                return false;
            } else if ((s[i] == ')' && stk.top() == '(') || (s[i] == '}' && stk.top() == '{') || (s[i] == ']' && stk.top() == '[')) {
                stk.pop();
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
