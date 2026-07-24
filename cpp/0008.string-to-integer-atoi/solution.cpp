// Created by Gavin at 2025/12/10 11:59
// leetgo: 1.4.15
// https://leetcode.cn/problems/string-to-integer-atoi/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Automaton {
		string state = "start";
		unordered_map<string, vector<string>> table = {
				{"start", {"start", "signed", "in_number", "end"}},
				{"signed", {"end", "end", "in_number", "end"}},
				{"in_number", {"end", "end", "in_number", "end"}},
				{"end", {"end", "end", "end", "end"}}
		};

		int get_col(char c) {
				if (isspace(c)) return 0;
				if (c == '+' or c == '-') return 1;
				if (isdigit(c)) return 2;
				return 3;
		}

public:
		int sign = 1;
		long long ans = 0;

		void get(char c) {
				state = table[state][get_col(c)];
				if (state == "in_number") {
						ans = ans * 10 + c - '0';
						ans = sign == 1	? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
				}
				else if (state == "signed")
						sign = c == '+' ? 1 : -1;
		}
};

class Solution {
public:
    int myAtoi(string s) {
			Automaton automaton;
			for (char c : s)
					automaton.get(c);
			return automaton.sign * automaton.ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);

	Solution *obj = new Solution();
	auto res = obj->myAtoi(s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
