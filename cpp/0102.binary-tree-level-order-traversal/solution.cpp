// Created by Gavin at 2025/12/18 00:19
// leetgo: 1.4.15
// https://leetcode.cn/problems/binary-tree-level-order-traversal/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
	    if (!root) {
		    return ret;
		}

		queue <TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
		    int currentLevelSize = q.size();
			ret.push_back(vector <int> ());
			for (int i = 1; i <= currentLevelSize; ++i) {
				auto node = q.front(); q.pop();
				ret.back().push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}
		return ret;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	TreeNode* root;
	LeetCodeIO::scan(cin, root);

	Solution *obj = new Solution();
	auto res = obj->levelOrder(root);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
