// Created by Gavin at 2025/12/27 21:26
// leetgo: 1.4.15
// https://leetcode.cn/problems/minimum-genetic-mutation/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> cnt;
        unordered_set<string> visited;
        char keys[4] = {'A', 'C', 'G', 'T'};
        for (auto & w : bank) {
            cnt.emplace(w);
        }
        if (start == end) {
            return 0;
        }
        if (!cnt.count(end)) {
            return -1;
        }
        queue<string> qu;
        qu.emplace(start);
        visited.emplace(start);
        int step = 1;
        while (!qu.empty()) {
            int sz = qu.size();
            for (int i = 0; i < sz; i++) {
                string curr = qu.front();
                qu.pop();
                for (int j = 0; j < 8; j++) {
                    for (int k = 0; k < 4; k++) {
                        if (keys[k] != curr[j]) {
                            string next = curr;
                            next[j] = keys[k];
                            if (!visited.count(next) && cnt.count(next)) {
                                if (next == end) {
                                    return step;
                                }
                                qu.emplace(next);
                                visited.emplace(next);
                            }
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	string startGene;
	LeetCodeIO::scan(cin, startGene);
	string endGene;
	LeetCodeIO::scan(cin, endGene);
	vector<string> bank;
	LeetCodeIO::scan(cin, bank);

	Solution *obj = new Solution();
	auto res = obj->minMutation(startGene, endGene, bank);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
