// Created by Gavin at 2026/01/06 01:29
// leetgo: 1.4.15
// https://leetcode.cn/problems/edit-distance/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        if (n * m == 0) return n + m;
        vector<vector<int>> D(n + 1, vector<int>(m + 1));

        for (int i = 0; i < n + 1; i++) {
            D[i][0] = i;
        }
        for (int j = 0; j < m + 1; j++) {
            D[0][j] = j;
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int left = D[i - 1][j] + 1;
                int down = D[i][j - 1] + 1;
                int left_down = D[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) left_down += 1;
                D[i][j] = min(left, min(down, left_down));
            }
        }
        return D[n][m];
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string word1;
	LeetCodeIO::scan(cin, word1);
	string word2;
	LeetCodeIO::scan(cin, word2);

	Solution *obj = new Solution();
	auto res = obj->minDistance(word1, word2);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
