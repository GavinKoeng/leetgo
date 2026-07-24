// Created by Gavin at 2025/12/08 16:54
// leetgo: 1.4.15
// https://leetcode.cn/problems/linked-list-cycle-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited;
		while (head != nullptr) {
				if (visited.count(head)) {
						return head;
				}
				visited.insert(head);
				head = head->next;
		}
		return nullptr;
    }
};

// @lc code=end

// Warning: this is a manual question, the generated test code may be incorrect.
int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* head;
	LeetCodeIO::scan(cin, head);
	int pos;
	LeetCodeIO::scan(cin, pos);

	Solution *obj = new Solution();
	auto res = obj->detectCycle(head);
	//auto res = obj->detectCycle(head, pos);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
