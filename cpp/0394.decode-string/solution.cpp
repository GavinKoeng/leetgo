// Created by Gavin at 2026/01/26 09:12
// leetgo: 1.4.15
// https://leetcode.cn/problems/decode-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    string decodeString(string s) {
        vector <string> stk;
        size_t ptr = 0;

        while (ptr < s.size()) {
            char cur = s[ptr];
            if (isdigit(cur)) {
                string digits = getDigits(s, ptr);
                stk.push_back(digits);
            } else if (isalpha(cur) || cur == '[') {
                stk.push_back(string(1, s[ptr++]));
            } else {
                ptr++;
                vector <string> sub;
                while (stk.back() != "[") {
                    sub.push_back(stk.back());
                    stk.pop_back();
                }
                reverse(sub.begin(), sub.end());
                stk.pop_back();
                int repTime = stoi(stk.back());
                stk.pop_back();
                string t, o = getString(sub);
                while (repTime--) t += o;
                stk.push_back(t);
            }
        }
        return getString(stk);
    }

    string getDigits(string &s, size_t &ptr) {
        string ret = "";
        while (isdigit(s[ptr])) {
            ret += s[ptr++];
        }
        return ret;
    }

    string getString(vector <string> &v) {
        string ret;
        for (const auto &s : v) {
            ret += s;
        }
        return ret;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);

	Solution *obj = new Solution();
	auto res = obj->decodeString(s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
