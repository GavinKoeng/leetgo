// Created by Gavin at 2025/12/03 20:19
// leetgo: 1.4.15
// https://leetcode.cn/problems/assign-cookies/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      sort(g.begin(), g.end());
      sort(s.begin(), s.end());
      int m = g.size(), n = s.size();
      int count = 0;
      for (int i = 0, j = 0; i < m && j < n; i++, j++) {
        while (j < n && g[i] > s[j]) {
          j++;
        }
        if (j < n) {
          count++;
        }
      }
      return count;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> g;
	LeetCodeIO::scan(cin, g);
	vector<int> s;
	LeetCodeIO::scan(cin, s);

	Solution *obj = new Solution();
	auto res = obj->findContentChildren(g, s);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
