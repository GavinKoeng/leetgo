// Created by gavin at 2026/08/08 16:43
// leetgo: 1.4.17
// https://leetcode.cn/problems/reverse-linked-list-ii/

#include <bits/stdc++.h>
#include "../LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* pre = dummyHead;
        for (int i = 0; i < left - 1; i++) pre = pre->next;
        ListNode* cur = pre->next;
        ListNode* next = nullptr;
        for (int i = 0; i < right - left; i++) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
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
