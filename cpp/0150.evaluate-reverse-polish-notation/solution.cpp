// Created by gavin at 2026/08/13 00:07
// leetgo: 1.4.17
// https://leetcode.cn/problems/evaluate-reverse-polish-notation/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        vector<int> stk((n + 1) / 2);
        int index = -1;
        for (int i = 0; i < n; i++) {
            string& token = tokens[i];
            if (token.length() > 1 || isdigit(token[0])) {
                index++;
                stk[index] = atoi(token.c_str());
            } else {
                switch (token[0]) {
                    case '+':
                        index--;
                        stk[index] += stk[index + 1];
                        break;
                    case '-':
                        index--;
                        stk[index] -= stk[index + 1];
                        break;
                    case '*':
                        index--;
                        stk[index] *= stk[index + 1];
                        break;
                    case '/':
                        index--;
                        stk[index] /= stk[index + 1];
                        break;
                }
            }
        }
        return stk[index];
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
