// Created by Gavin at 2026/02/01 16:46
// leetgo: 1.4.15
// https://leetcode.cn/problems/first-unique-character-in-a-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> position;
        queue<pair<char, int>> q;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (!position.count(s[i])) {
                position[s[i]] = i;
                q.emplace(s[i], i);
            } else {
                position[s[i]] = -1;
                while (!q.empty() && position[q.front().first] == -1) {
                    q.pop();
                }
            }
        }
        return q.empty() ? -1 : q.front().second;

    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string s;
	LeetCodeIO::scan(cin, s);

	Solution *obj = new Solution();
	auto res = obj->firstUniqChar(s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
