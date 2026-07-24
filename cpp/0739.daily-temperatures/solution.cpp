// Created by Gavin at 2026/01/28 23:09
// leetgo: 1.4.15
// https://leetcode.cn/problems/daily-temperatures/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector <int> ans(n);
        stack <int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int previousIndex = stk.top();
                ans[previousIndex] = i - previousIndex;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> temperatures;
	LeetCodeIO::scan(cin, temperatures);

	Solution *obj = new Solution();
	auto res = obj->dailyTemperatures(temperatures);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
