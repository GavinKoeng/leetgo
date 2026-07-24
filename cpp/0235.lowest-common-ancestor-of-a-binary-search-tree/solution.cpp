// Created by Gavin at 2025/12/26 13:16
// leetgo: 1.4.15
// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<TreeNode*> getPath(TreeNode* root, TreeNode* target) {
        vector<TreeNode*> path;
        TreeNode* node = root;
        while (node != target) {
            path.push_back(node);
            if (target->val < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        path.push_back(node);
        return path;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p = getPath(root, p);
        vector<TreeNode*> path_q = getPath(root, q);
        TreeNode* ancestor;
        for (int i = 0; i < path_p.size() && i < path_q.size(); ++i) {
            if (path_p[i] == path_q[i]) {
                ancestor = path_p[i];
            } else {
                break;
            }
        }
        return ancestor;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	TreeNode* root;
	LeetCodeIO::scan(cin, root);
	int p;
	LeetCodeIO::scan(cin, p);
	int q;
	LeetCodeIO::scan(cin, q);

	Solution *obj = new Solution();
	auto res = obj->lowestCommonAncestor(root, p, q);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
