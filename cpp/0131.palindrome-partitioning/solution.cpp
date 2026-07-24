// Created by Gavin at 2025/12/17 23:04
// leetgo: 1.4.15
// https://leetcode.cn/problems/palindrome-partitioning/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
private:
    vector<vector<int>> f;
	vector<vector<string>> ret;
	vector<string> ans;
	int n;

public:
	void dfs(const string& s, int i) {
        if (i == n) {
		    ret.push_back(ans);
			return;
		}
		for (int j = i; j < n; ++j) {
		    if (f[i][j]) {
				ans.push_back(s.substr(i, j - i + 1));
				dfs(s, j + 1);
				ans.pop_back();
			}
		}
	}
	
    vector<vector<string>> partition(string s) {
			n = s.size();
			f.assign(n, vector<int>(n, true));

			for (int i = n - 1; i >= 0; --i) {
		        for (int j = i + 1; j < n; ++j) {
				    f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
				}
			}

			dfs(s, 0);
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
	auto res = obj->partition(s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
