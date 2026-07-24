// Created by Gavin at 2025/12/24 23:42
// leetgo: 1.4.15
// https://leetcode.cn/problems/maximum-depth-of-binary-tree/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int maxDepth(TreeNode* root) {
      if (root == nullptr) return 0;
      return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	TreeNode* root;
	LeetCodeIO::scan(cin, root);

	Solution *obj = new Solution();
	auto res = obj->maxDepth(root);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
