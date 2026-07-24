// Created by Gavin at 2026/01/25 23:08
// leetgo: 1.4.15
// https://leetcode.cn/problems/evaluate-reverse-polish-notation/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n = tokens.size();
        for (int i = 0; i < n; ++i) {
            string& token = tokens[i];
            if (isNumber(token)) {
                stk.push(atoi(token.c_str()));
            } else {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                switch (token[0]) {
                    case '+' :
                        stk.push(num1 + num2);
                        break;
                    case '-' :
                        stk.push(num1 - num2);
                        break;
                    case '*' :
                        stk.push(num1 * num2);
                        break;
                    case '/' :
                        stk.push(num1 / num2);
                        break;
                }
            }
        }
        return stk.top();
    }

    bool isNumber(string& token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> tokens;
	LeetCodeIO::scan(cin, tokens);

	Solution *obj = new Solution();
	auto res = obj->evalRPN(tokens);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
