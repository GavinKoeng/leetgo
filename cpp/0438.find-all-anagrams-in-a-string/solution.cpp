// Created by Gavin at 2025/12/12 13:22
// leetgo: 1.4.15
// https://leetcode.cn/problems/find-all-anagrams-in-a-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
		int sLen = s.size(), pLen = p.size();

		if (sLen < pLen) {
				return vector<int>();
		}

		vector<int> ans;
		vector<int> sCount(26);
		vector<int> pCount(26);
		for (int i = 0; i < pLen; ++i) {
				++sCount[s[i] - 'a'];
				++pCount[p[i] - 'a'];
		}

		if (sCount == pCount) {
				ans.emplace_back(0);
		}

		for (int i = 0; i < sLen - pLen; ++i) {
				--sCount[s[i] - 'a'];
				++sCount[s[i + pLen] - 'a'];

				if (sCount == pCount) {
						ans.emplace_back(i + 1);
				}
		}
		return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);
	string p;
	LeetCodeIO::scan(cin, p);

	Solution *obj = new Solution();
	auto res = obj->findAnagrams(s, p);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
