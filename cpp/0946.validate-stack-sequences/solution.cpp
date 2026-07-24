// Created by Gavin at 2026/01/21 09:34
// leetgo: 1.4.15
// https://leetcode.cn/problems/validate-stack-sequences/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        for (int i = 0, j = 0; i < n; i++) {
            st.emplace(pushed[i]);
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> pushed;
	LeetCodeIO::scan(cin, pushed);
	vector<int> popped;
	LeetCodeIO::scan(cin, popped);

	Solution *obj = new Solution();
	auto res = obj->validateStackSequences(pushed, popped);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
