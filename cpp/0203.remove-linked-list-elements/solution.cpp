// Created by Gavin at 2026/07/31 23:28
// leetgo: 1.4.15
// https://leetcode.cn/problems/remove-linked-list-elements/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            head = head->next;
        }
        if (head == nullptr) {
            return head;
        }
        ListNode* cur = head;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* head;
	LeetCodeIO::scan(cin, head);
	int val;
	LeetCodeIO::scan(cin, val);

	Solution *obj = new Solution();
	auto res = obj->removeElements(head, val);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
