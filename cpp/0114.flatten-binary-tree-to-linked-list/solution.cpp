// Created by Gavin at 2025/12/25 13:19
// leetgo: 1.4.15
// https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> l;
        preorderTravelsal(root, l);
        int n = l.size();
        for (int i = 1; i < n; ++i) {
            TreeNode *prev = l.at(i - 1), *curr = l.at(i);
            prev->left = nullptr;
            prev->right = curr;
        }
    }

    void preorderTravelsal(TreeNode* root, vector<TreeNode*> &l) {
        if (root != NULL) {
            l.push_back(root);
            preorderTravelsal(root->left, l);
            preorderTravelsal(root->right, l);
        }
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	TreeNode* root;
	LeetCodeIO::scan(cin, root);

	Solution *obj = new Solution();
	auto res = obj->flatten(root);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
