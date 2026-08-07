// Created by gavin at 2026/08/06 17:05
// leetgo: 1.4.15
// https://leetcode.cn/problems/reverse-linked-list-ii/

#include <bits/stdc++.h>
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

// ListNode
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* prev = dummyHead;
        for (int i = 0; i < left - 1; i++) prev = prev->next;
        ListNode* cur = prev->next;
        stack<ListNode*> stk;
        for (int i = 0; i < right - left + 1; i++) {
            stk.push(cur);
            cur = cur->next;
        }
        ListNode* after = cur;
        cur = prev;
        for (int i = 0; i < right - left + 1; i++) {
            cur->next = stk.top();
            stk.pop();
            cur = cur->next;
        }
        cur->next = after;
        return dummyHead->next;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* head;
	LeetCodeIO::scan(cin, head);
	int left;
	LeetCodeIO::scan(cin, left);
	int right;
	LeetCodeIO::scan(cin, right);

	Solution *obj = new Solution();
	auto res = obj->reverseBetween(head, left, right);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
